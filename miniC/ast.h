#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <map>
#include <list>
#include "code.h"

using namespace std;

class Expr;
class InitDeclarator;
class Statement;
class Declaration;
class Parameter;

typedef list<InitDeclarator *> InitDeclaratorList;
typedef list<Expr *> InitializerList;
typedef list<Parameter *> ParameterList;
typedef list<Declaration *> DeclarationList;
typedef list<Expr *> ArgumentList;
typedef list<Statement *> StatementList;

class Expr{
    public:
        int line;
        virtual Type getType() = 0;
        virtual void gen(Code &context) = 0;
};

class Statement{
    public:
        int line;
        virtual int evaluateSemantic() = 0;
        virtual string genCode() = 0;
};

class BinaryExpr : public Expr{
    public:
        BinaryExpr(Expr * leftExpr, Expr * rightExpr, int line){
            this->leftExpr = leftExpr;
            this->rightExpr = rightExpr;
            this->line = line;
        }
        Expr * leftExpr;
        Expr * rightExpr;
        int line;
};

#define IMPLEMENT_BINARY_EXPR(name) \
class name##Expr: public BinaryExpr{ \
    public: \
        name##Expr(Expr * leftExpr, Expr * rightExpr, int line) : BinaryExpr(leftExpr, rightExpr, line){}\
        Type getType();\
        void gen(Code &context);\
};\

class FloatExpr : public Expr{
    public:
        FloatExpr(float value, int line){
            this->value = value;
            this->line = line;
        }
        float value;
        int line;
        Type getType();
        void gen(Code &context);
};

class IntExpr : public Expr{
    public:
        IntExpr(int value, int line){
            this->value = value;
            this->line = line;
        }
        int value;
        int line;
        Type getType();
        void gen(Code &context);
};

class IdExpr : public Expr{
    public:
        IdExpr(string name, int line){
            this->name = name;
            this->line = line;
        }
        string name;
        int line;
        Type getType();
        void gen(Code &context);;
};

class StringExpr : public Expr{
    public:
        StringExpr(string value, int line){
            this->value = value;
            this->line = line;
        }
        string value;
        int line;
        Type getType();
        void gen(Code &context);
};

class MethodInvocationExpr: public Expr{
    public:
        MethodInvocationExpr(IdExpr * id, ArgumentList args, int line){
            this->id = id;
            this->args = args;
            this->line = line;
        }
        IdExpr * id;
        ArgumentList args;
        int line;
        Type getType();
        void gen(Code &context);
};

class ArrayExpr: public Expr{
    public:
        ArrayExpr(IdExpr * id, Expr * indexExpression, int line){
            this->id = id;
            this->indexExpression = indexExpression;
            this->line = line;
        }
        IdExpr* id;
        Expr * indexExpression;
        int line;
        Type getType();
        void gen(Code &context);
};

class UnaryExpr: public Expr{
    public:
        UnaryExpr(int type, Expr* expression){
            this->type = type;
            this->expression = expression;
        }

        int type;
        Expr* expression;
        Type getType();
        void gen(Code &context);
};

class ReturnStatement : public Statement{
    public:
        ReturnStatement(Expr * expr, int line){
            this->expr = expr;
            this->line = line;
        }
        Expr * expr;
        int line;
        int evaluateSemantic();
        string genCode();
};

class IfStatement: public Statement{
    public:
        IfStatement(Expr * condition, Statement * trueStatement, int line){
            this->condition = condition;
            this->trueStatement = trueStatement;
            this->line = line;
        }
        Expr * condition;
        Statement * trueStatement;
        int line;
        int evaluateSemantic();
        string genCode();
};

class IfElseStatement: public Statement{
    public:
        IfElseStatement(Expr * condition, Statement * trueStatement, Statement * falseStatement, int line){
            this->condition = condition;
            this->trueStatement = trueStatement;
            this->line = line;
            this->falseStatement = falseStatement;
        }
        Expr * condition;
        Statement * trueStatement;
        Statement * falseStatement;
        int line;
        int evaluateSemantic();
        string genCode();
};

class WhileStatement: public Statement{
    public:
        WhileStatement(Expr * condition, Statement * statement, int line){
            this->condition = condition;
            this->statement = statement;
            this->line = line;
        }
        Expr * condition;
        Statement * statement;
        int line;
        int evaluateSemantic();
        string genCode();
};

class PrintStatement: public Statement{
    public:
        PrintStatement(Expr * expr, int line){
            this->expr = expr;
            this->line = line;
        }
        Expr * expr;
        int line;
        int evaluateSemantic();
        string genCode();
};

class BlockStatement: public Statement{
    public:
        BlockStatement(DeclarationList declarations, StatementList statements, int line){
            this->declarations = declarations;
            this->statements = statements;
            this->line = line;
        }
        DeclarationList declarations;
        StatementList statements;
        int line;
        int evaluateSemantic();
        string genCode();
};

class Declarator{
    public:
        Declarator(string id, Expr* arrayDeclaration, bool isArray, int line){
            this->id = id;
            this->arrayDeclaration = arrayDeclaration;
            this->line = line;
        }
        string id;
        Expr* arrayDeclaration;
        bool isArray;
        int line;
};

class Parameter{
    public:
        Parameter(Type type, Declarator * declarator, int line){
            this->type = type;
            this->declarator = declarator;
            this->line = line;
        }
        Type type;
        Declarator * declarator;
        int line;
        int evaluateSemantic();
};

class MethodDefinitionStatement: public Statement{
    public:
        MethodDefinitionStatement(Type type, string id, ParameterList params, Statement * stmt, int line){
            this->type = type;
            this->id = id;
            this->params = params;
            this->stmt = stmt;
            this->line = line;
        }
        Type type;
        string id;
        ParameterList params;
        Statement * stmt;
        int line;
        int evaluateSemantic();
        string genCode();
};

class InitDeclarator{
    public:
        InitDeclarator(Declarator * declarator, InitializerList * initializer, int line){
            this->declarator = declarator;
            this->initializer = initializer;
            this->line = line;
        }
        Declarator * declarator;
        InitializerList * initializer;
        int line;
};

class Declaration : public Statement{
    public:
        Declaration(Type type, InitDeclaratorList declarations, int line){
            this->type = type;
            this->declarations = declarations;
            this->line = line;
        }
        Type type;
        InitDeclaratorList declarations;
        int line;
        int evaluateSemantic();
        string genCode();
};

class GlobalDeclaration : public Statement {
    public:
        GlobalDeclaration(Declaration * declaration){
            this->declaration = declaration;
        }
        Declaration * declaration;
        int evaluateSemantic();
        string genCode();
};

class ExprStatement : public Statement{
    public:
        ExprStatement(Expr * expr, int line){
            this->expr = expr;
            this->line = line;
        }
        Expr * expr;
        int evaluateSemantic();
        string genCode();
};


IMPLEMENT_BINARY_EXPR(Add);
IMPLEMENT_BINARY_EXPR(Sub);
IMPLEMENT_BINARY_EXPR(Div);
IMPLEMENT_BINARY_EXPR(Mult);
IMPLEMENT_BINARY_EXPR(Eq);
IMPLEMENT_BINARY_EXPR(Neq);
IMPLEMENT_BINARY_EXPR(Gte);
IMPLEMENT_BINARY_EXPR(Gt);
IMPLEMENT_BINARY_EXPR(Lt);
IMPLEMENT_BINARY_EXPR(Lte);
IMPLEMENT_BINARY_EXPR(LogicalAnd);
IMPLEMENT_BINARY_EXPR(LogicalOr);
IMPLEMENT_BINARY_EXPR(Assign);
IMPLEMENT_BINARY_EXPR(PlusAssign);
IMPLEMENT_BINARY_EXPR(MinusAssign);


#endif