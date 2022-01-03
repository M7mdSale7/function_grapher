#ifndef MATHNODE_H
#define MATHNODE_H


class MathNode
{
protected:
    MathNode* left = nullptr, *right = nullptr;
public:
    MathNode(MathNode* l, MathNode* r);
    virtual double executeOperation()=0;
    virtual ~MathNode();
};

class AddNode : public MathNode
{
public:
    AddNode(MathNode* l, MathNode* r);
    double executeOperation();
};

class SubtractNode : public MathNode
{
public:
    SubtractNode(MathNode* l, MathNode* r);
    double executeOperation();
};

class MultiplyNode : public MathNode
{
public:
    MultiplyNode(MathNode* l, MathNode* r);
    double executeOperation();
};

class DivideNode : public MathNode
{
public:
    DivideNode(MathNode* l, MathNode* r);
    double executeOperation();
};

class PowerNode : public MathNode
{
public:
    PowerNode(MathNode* l, MathNode* r);
    double executeOperation();
};

class NumberNode : public MathNode
{
private:
    double numberValue;
public:
    NumberNode(double num, MathNode* l, MathNode* r);
    double executeOperation();
};

class XNode : public MathNode
{
private:
    static double x;
public:
    XNode(MathNode* l, MathNode* r);
    static void setX(double newX);
    double executeOperation();
};

#endif // MATHNODE_H
