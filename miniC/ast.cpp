#include "ast.h"
#include <set>
#include <iostream>
#include <sstream>
#include "asm.h"

extern Asm assemblyResultFile;

class MethodInfo{
    public:
        Type returnType;
        list<Parameter *> parameters;
};

class Context{
    public:
        struct Context * prev;
        map<string, Type> vars;
};

map<string, Type> vars = {};
map<string, Type> globalVars = {};
map<string, MethodInfo *> methods = {};


Context * context = NULL;


Type getLocalVariableType(string id){
    Context  * currentContext = context;
    while (currentContext != NULL)
    {
        if (currentContext->vars[id] != 0)
        {
            return currentContext->vars[id];
        }
        currentContext = currentContext->prev;
    }
    return INVALID;
}

Type getVariableType(string id){
    Type result = INVALID;
    if (context != NULL)
    {
        result = getLocalVariableType(id);
    }
    if (result != INVALID)
    {
        return result;
    }
    return globalVars[id] == 0 ? INVALID : globalVars[id];
}


void pushContext(){
    vars.clear();
    Context * c = new Context();
    c->vars = vars;
    c->prev = context;
    context = c;
}

void popContext(){
    if (context != NULL)
    {
        Context * previous = context->prev;
        free(context);
        context = previous;
    }
}


string getTypeName(Type type){
    switch (type)
    {
        case INT:
            return "INT";
        case FLOAT:
            return "FLOAT";
        case VOID:
            return "VOID";
        case STRING:
            return "STRING";
        case BOOL:
            return "BOOL";
    }
    cerr<<"Invalid type"<<endl;
    exit(0);
}

map<string, Type> resultTypes = {
    {"INT,INT", INT},
    {"FLOAT,FLOAT", FLOAT},
    {"INT,FLOAT", FLOAT},
    {"FLOAT,INT", FLOAT}
};

const char * intTemps[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};

const char * floatTemps [] = {"$f0",
                            "$f1",
                            "$f2",
                            "$f3",
                            "$f4",
                            "$f5",
                            "$f6",
                            "$f7",
                            "$f8",
                            "$f9",
                            "$f10",
                            "$f11",
                            "$f12",
                            "$f13",
                            "$f14",
                            "$f15",
                            "$f16",
                            "$f17",
                            "$f18",
                            "$f19",
                            "$f20",
                            "$f21",
                            "$f22",
                            "$f23",
                            "$f24",
                            "$f25",
                            "$f26",
                            "$f27",
                            "$f28",
                            "$f29",
                            "$f30",
                            "$f31"
                        };

#define INT_TEMP_COUNT 10
#define FLOAT_TEMP_COUNT 32
set<string> intTempMap;
set<string> floatTempMap;

string getIntTemp(){
    for (int i = 0; i < INT_TEMP_COUNT; i++)
    {
        if (intTempMap.find(intTemps[i]) == intTempMap.end())
        {
            intTempMap.insert(intTemps[i]);
            return string(intTemps[i]);
        }
    }
    return "";
}

string getFloatTemp(){
    for (int i = 0; i < FLOAT_TEMP_COUNT; i++)
    {
        if (floatTempMap.find(floatTemps[i]) == floatTempMap.end())
        {
            floatTempMap.insert(floatTemps[i]);
            return string(floatTemps[i]);
        }
    }
    return "";
}

void releaseRegister(string temp){
    intTempMap.erase(temp);
    floatTempMap.erase(temp);
}

void toFloat(Code &context){
    if (context.type == INT)
    {
        string floatTemp = getFloatTemp();
        stringstream code;
        code << context.code
        << "mtc1 "<< context.place<< ", "<< floatTemp<<endl
        << "cvt.s.w "<< floatTemp <<", "<<floatTemp<<endl;
        releaseRegister(context.place);
        context.place = floatTemp;
        context.type = FLOAT;
        context.code = code.str();
    }
}


int labelCounter = 0;
string newLabel(string prefix){
    stringstream ss;
    ss<<prefix<<"_"<<labelCounter;
    labelCounter++;
    return ss.str();
}


Type FloatExpr::getType(){
    return FLOAT;
}

void FloatExpr::gen(Code &context){
    stringstream code;
    string tempReg = getFloatTemp();
    code << "li.s " <<tempReg<<", "<< this->value<<endl;
    context.code = code.str();
    context.place = tempReg;
    context.type = FLOAT;
}

Type IntExpr::getType(){
    return INT;
}

void IntExpr::gen(Code &context){
    stringstream code;
    string intTemp = getIntTemp();
    code<< "li "<< intTemp<<", "<< this->value<<endl;
    context.code = code.str();
    context.place = intTemp;
    context.type = INT;
}

Type IdExpr::getType(){
    Type type =  getVariableType(this->name);
    if (type == -1)
    {
        cerr<<"Error: "<<this->name<<" was not declared in this scope, line:"<<this->line<<endl;
        exit(0);
    }
    return type;
}

Type StringExpr::getType(){
    return STRING;
}

void StringExpr::gen(Code &context){
    string strLabel = newLabel("string");
    stringstream code;
    code<<strLabel<<": .asciiz " << this->value<<endl;
    context.place = strLabel;
    context.type = STRING;
    context.code = "";
    assemblyResultFile.data += code.str();
}

Type MethodInvocationExpr::getType(){
    MethodInfo * method = methods[this->id->name];
    if (method == NULL)
    {
        cerr<<"Error: invocation of undefined method: "<<this->id->name<<endl<< " Line: "<<this->line;
        exit(0);
    }

    if (method->parameters.size() > this->args.size())
    {
        cerr<<"Error: too few arguments for method: "<<this->id->name<<endl<<" Line: "<<this->line;
        exit(0);
    }
    if (method->parameters.size() < this->args.size())
    {
        cerr<<"Error: too many arguments for method: "<<this->id->name<<endl<<" Line: "<<this->line;
        exit(0);
    }
    
    list<Parameter *>::iterator paramIt = method->parameters.begin();
    list<Expr *>::iterator argsIt = this->args.begin();
    while (paramIt != method->parameters.end() && argsIt != this->args.end())
    {
        if ((*paramIt)->type != (*argsIt)->getType())
        {
            cerr<<"Error: invalid parameter type for param: "<<
                (*paramIt)->declarator->id<<" method: "<< this->id->name
                <<" Line: "<<this->line
                <<" expected: "<< getTypeName((*paramIt)->type)
                <<" but "<< getTypeName((*argsIt)->getType())
                <<" was provided"
                <<endl; 
        }
        
       paramIt++;
       argsIt++;
    }
    

    return method->returnType;
}

Type ArrayExpr::getType(){
    return this->id->getType();
}

Type UnaryExpr::getType(){
    if (this->expression->getType() != BOOL)
    {
        cerr<<"Unary expression works only for booleans"<<endl;
    }
    
    return BOOL;
}



int ReturnStatement::evaluateSemantic(){
    return this->expr->getType();
}

int IfStatement::evaluateSemantic(){
    if (this->condition->getType() != BOOL)
    {
        cerr<<"Error: If can only evaluate boolean expressions"<<" Line: "<<this->line<<endl;
        exit(0);
    }
    pushContext();
    int statementResult = this->trueStatement->evaluateSemantic();
    popContext();
    return statementResult;
}

int IfElseStatement::evaluateSemantic(){
    if (this->condition->getType() != BOOL)
    {
        cerr<<"Error: If can only evaluate boolean expressions"<<" Line: "<<this->line<<endl;
        exit(0);
    }
    pushContext();
    int statementResult = this->trueStatement->evaluateSemantic();
    popContext();
    pushContext();
    statementResult &= statementResult && this->trueStatement->evaluateSemantic();
    popContext();
    return statementResult;
}

int WhileStatement::evaluateSemantic(){
    if (this->condition->getType() != BOOL)
    {
        cerr<<"Error: while can only evaluate boolean expressions"<<" Line: "<<this->line<<endl;
        exit(0);
    }
    pushContext();
    int statementResult = this->statement->evaluateSemantic();
    popContext();
    return statementResult;
}

int PrintStatement::evaluateSemantic(){
    return this->expr->getType();
}

int BlockStatement::evaluateSemantic(){
    list<Declaration *>::iterator declIt = this->declarations.begin();
    while (declIt != this->declarations.end())
    {
        if((*declIt) != NULL){
            (*declIt)->evaluateSemantic();
        }
        declIt++;
    }
    
    list<Statement *>::iterator statementsIt = this->statements.begin();
    while (statementsIt  != this->statements.end())
    {
         if((*statementsIt) != NULL){
            (*statementsIt)->evaluateSemantic();
        }
        statementsIt++;
    }

    return 0;
}

int GlobalDeclaration::evaluateSemantic(){
    return this->declaration->evaluateSemantic();
}

int Declaration::evaluateSemantic(){
    list<InitDeclarator *>::iterator it = this->declarations.begin();
    while (it != this->declarations.end())
    {
        InitDeclarator * declaration = *it;

        if (declaration->declarator->isArray &&
            declaration->declarator->arrayDeclaration == NULL &&
            declaration->initializer == NULL)
        {
            cerr<<"Error: no size was provided for array "<<declaration->declarator->id<<" line "<<this->line<<endl;
            exit(0);
        }

        if (declaration->initializer != NULL)
        {
            list<Expr*>::iterator exprIt = declaration->initializer->begin();
            while (exprIt != declaration->initializer->end())
            {
                Type exprType = (*exprIt)->getType();
                string leftType = getTypeName(this->type);
                string rightType = getTypeName(exprType);
                Type resultType = resultTypes[leftType+","+rightType];
                if(resultType == 0){
                    cerr<<"Error: el tipo "<<leftType<<" no puede ser asignado a una variable tipo "<<rightType<<this->line<<endl;
                    exit(0);
                }
                exprIt++;
            }
        }
        
        if (getVariableType(declaration->declarator->id) != -1)
        {
            cerr<<"Error: redefinition of variable "<< declaration->declarator->id<<" line: "<<this->line;
            exit(0);
        }else{
            context->vars[declaration->declarator->id] = this->type;
        }
        
        it++;
    }
}

int MethodDefinitionStatement::evaluateSemantic(){

    if (this->params.size() > 4)
    {
        cerr<<"Error: only 4 paramaters can be used, line: "<<this->line<<endl;
        exit(0);
    }
    

    if (methods[this->id] != 0)
    {
        cout<<"Error: redefinition of method: "<<this->id<<" line "<<this->line<<endl;
        exit(0);
    }

    methods[this->id] = new MethodInfo();
    methods[this->id]->returnType = this->type;
    methods[this->id]->parameters = this->params;

    pushContext();
    list<Parameter *>::iterator it = this->params.begin();
    while (it != this->params.end())
    {
        (*it)->evaluateSemantic();
        it++;
    }
    
    if (this->stmt != NULL)
    {
        this->stmt->evaluateSemantic();
    }

    popContext();
    return 0;
}

int Parameter::evaluateSemantic(){
    if (getVariableType(this->declarator->id) != INVALID)
    {
        cerr<<"Error: redefinition of variable: "<<this->declarator->id<<" line: "<<this->line;
        exit(0);
    }
    context->vars[this->declarator->id] = this->type;
    return 0;
}

int ExprStatement::evaluateSemantic(){
    return this->expr->getType();
}

void AssignExpr::gen(Code &context){

}

void LogicalOrExpr::gen(Code &context){

}

void LogicalAndExpr::gen(Code &context){

}

void PlusAssignExpr::gen(Code &context){

}

void MinusAssignExpr::gen(Code &context){

}

void MethodInvocationExpr::gen(Code &context){

}


void GtExpr::gen(Code &context){

}

void IdExpr::gen(Code &context){
    
}

void LteExpr::gen(Code &context){

}

void LtExpr::gen(Code &context){
    Code leftCode, rightCode;
    stringstream code;
    this->leftExpr->gen(leftCode);
    this->rightExpr->gen(leftCode);
    if (leftCode.type == INT && rightCode.type == INT)
    {
        context.type = INT;
        code<< leftCode.code <<endl <<rightCode.code<<endl;
        releaseRegister(leftCode.place);
        releaseRegister(rightCode.place);
        string temp = getIntTemp();
        code << "slt "<<temp<<", "<<leftCode.place <<", "<<rightCode.place<<endl;
        context.place = temp;
    }

    context.code = code.str();   
}

void GteExpr::gen(Code &context){

}

void NeqExpr::gen(Code &context){

}

void ArrayExpr::gen(Code &context){

}

void UnaryExpr::gen(Code &context){

}

void EqExpr::gen(Code &context){
    Code leftSideCode, rightSideCode;
    this->leftExpr->gen(leftSideCode);
    this->rightExpr->gen(rightSideCode);
    stringstream code;
    if (leftSideCode.type == INT && rightSideCode.type == INT)
    {
        context.type = INT;
        releaseRegister(leftSideCode.place);
        releaseRegister(rightSideCode.place);
        code << leftSideCode.code << endl<< rightSideCode.code;
        string tempInt = getIntTemp();
        string label = newLabel("eqlabel");
        string finalLabel = newLabel("finalEqLabel");
        code <<"beq "<<leftSideCode.place <<", " << rightSideCode.place <<", "<<label<<endl;
        code << "li "<<tempInt<<", 0"<<endl<< " j "<< finalLabel<<endl;
        code << label <<": "<<endl<<"li "<<tempInt<<", 1"<<endl;
        code << finalLabel<<": "<<endl;
        context.place = tempInt;
    }else{

    }

}


#define IMPLEMENT_BINARY_GET_TYPE(name)\
Type name##Expr::getType(){\
    string leftType = getTypeName(this->leftExpr->getType());\
    string rightType = getTypeName(this->rightExpr->getType());\
    Type resultType = resultTypes[leftType+","+rightType];\
    if(resultType == 0){\
        cerr<<"Error: el tipo "<<leftType<<" no puede ser operado con el tipo "<<rightType<<" linea: "<<this->line<<endl;\
        exit(0);\
    }\
    return resultType;\
}\

#define IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(name)\
Type name##Expr::getType(){\
    string leftType = getTypeName(this->leftExpr->getType());\
    string rightType = getTypeName(this->rightExpr->getType());\
    Type resultType = resultTypes[leftType+","+rightType];\
    if(resultType == 0){\
        cerr<<"Error: el tipo "<<leftType<<" no puede ser operado con el tipo "<<rightType<<" linea: " <<this->line<<endl;\
        exit(0);\
    }\
    return BOOL;\
}\

#define IMPLEMENT_BINARY_ARIT_GEN_CODE(name, op)\
void name##Expr::gen(Code &code){\
    Code leftCode, rightCode;\
    stringstream ss;\
    this->leftExpr->gen(leftCode);\
    this->rightExpr->gen(rightCode);\
    if(leftCode.type == INT && rightCode.type == INT){\
        code.type = INT;\
        releaseRegister(leftCode.place);\
        releaseRegister(rightCode.place);\
        ss<< leftCode.code << endl\
        << rightCode.code <<endl\
        << intArithmetic(leftCode, rightCode, code, op)<< endl;\
    }else{\
        code.type = FLOAT;\
        toFloat(leftCode);\
        toFloat(rightCode);\
        releaseRegister(leftCode.place);\
        releaseRegister(rightCode.place);\
        ss << leftCode.code << endl\
        << rightCode.code <<endl\
        << floatArithmetic(leftCode, rightCode, code, op)<<endl;\
    }\
    code.code = ss.str();\
}\

string intArithmetic(Code &leftCode, Code &rightCode, Code &resultCode, char op){
    resultCode.place = getIntTemp();
    stringstream code;
    switch (op)
    {
        case '+':
            code <<"add "<< resultCode.place<<", "<< leftCode.place<<", "<< rightCode.place;
            break;
        case '-':
            code <<"sub "<< resultCode.place<<", "<< leftCode.place<<", "<< rightCode.place;
            break;
        case '*':
            code <<"mult "<< leftCode.place<<", "<< rightCode.place << endl<< "mflo " << resultCode.place;
            break;
        case '/':
            code <<"div "<< leftCode.place<<", "<< rightCode.place << endl<< "mflo " << resultCode.place;
            break;
        default:
            break;
    }
    return code.str();
}

string floatArithmetic(Code &leftCode, Code &rightCode, Code &resultCode, char op){
    resultCode.place = getFloatTemp();
    stringstream code;
    switch (op)
    {
    case '+':
        code <<"add.s "<< resultCode.place<<", "<< leftCode.place<<", "<< rightCode.place;
        break;
     case '-':
        code <<"sub.s "<< resultCode.place<<", "<< leftCode.place<<", "<< rightCode.place;
        break;
     case '*':
        code <<"mul.s " << resultCode.place<<"," << leftCode.place<<", "<< rightCode.place;
        break;
     case '/':
        code <<"div.s "<< resultCode.place<< ", "<< leftCode.place<<", "<< rightCode.place;
        break;
    default:
        break;
    }
    return code.str();
}


string ReturnStatement::genCode(){
    return "";
}

string IfStatement::genCode(){
    return "";
}

string IfElseStatement::genCode(){
    return "";
}

string WhileStatement::genCode(){
    stringstream code;
    string whileLabel = newLabel("while");
    string endWhileLabel = newLabel("endWhile");
    Code exprCode;
    this->condition->gen(exprCode);
    releaseRegister(exprCode.place);
    code << whileLabel <<": "<<endl
    << exprCode.code << endl;
    if (exprCode.type == INT)
    {
        code <<"beqz "<< exprCode.place<< ", "<<endWhileLabel<<endl;
    }else{
        code <<"bc1f " << endWhileLabel <<endl;
    }
    code<< this->statement->genCode() <<endl
    << "j " <<whileLabel<<endl
    <<endWhileLabel<<": "<<endl;
    return code.str();
}

string PrintStatement::genCode(){
    Code exprCode;
    this->expr->gen(exprCode);
    releaseRegister(exprCode.place);
    stringstream code;
    code << exprCode.code <<endl;
    if (exprCode.type == INT)
    {
        code<<"move $a0, "<<exprCode.place<<endl
        << "li $v0, 1"<<endl
        << "syscall"<<endl;
    }else if (exprCode.type == FLOAT)
    {
        code<<"mov.s $f12, "<<exprCode.place<<endl
        << "li $v0, 2"<<endl
        << "syscall"<<endl;
    }else if (exprCode.type == STRING)
    {
        code<<"la $a0, "<<exprCode.place<<endl
        << "li $v0, 4"<<endl
        << "syscall"<<endl;   
    }
    
    return code.str();
}

string BlockStatement::genCode(){
    stringstream code;
    list<Declaration *>::iterator itd = this->declarations.begin();
    while (itd != this->declarations.end())
    {
        Declaration * dec = *itd;
        if (dec != NULL)
        {
            code << dec->genCode()<<endl;
        }
        
        itd++;
    }

    list<Statement *>::iterator its = this->statements.begin();
    while (its != this->statements.end())
    {
        Statement * stmt = *its;
        if (stmt != NULL)
        {
            code << stmt->genCode()<<endl;
        }
        
        its++;
    }
    return code.str();
}

string MethodDefinitionStatement::genCode(){
    return this->stmt->genCode();
}

string Declaration::genCode(){
    return "";
}

string GlobalDeclaration::genCode(){
    return "";
}

string ExprStatement::genCode(){
    return "";
}

IMPLEMENT_BINARY_GET_TYPE(Add);
IMPLEMENT_BINARY_GET_TYPE(Sub);
IMPLEMENT_BINARY_GET_TYPE(Div);
IMPLEMENT_BINARY_GET_TYPE(Mult);
IMPLEMENT_BINARY_GET_TYPE(Assign);
IMPLEMENT_BINARY_GET_TYPE(PlusAssign);
IMPLEMENT_BINARY_GET_TYPE(MinusAssign);


IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Eq);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Neq);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Gte);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Gt);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Lt);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(Lte);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(LogicalAnd);
IMPLEMENT_BINARY_BOOLEAN_GET_TYPE(LogicalOr);


IMPLEMENT_BINARY_ARIT_GEN_CODE(Add, '+');
IMPLEMENT_BINARY_ARIT_GEN_CODE(Sub, '-');
IMPLEMENT_BINARY_ARIT_GEN_CODE(Div, '/');
IMPLEMENT_BINARY_ARIT_GEN_CODE(Mult, '*');
