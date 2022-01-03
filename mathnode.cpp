#include "mathnode.h"
#include <qmath.h>
#include <QMessageBox>
#include <QString>

MathNode::MathNode(MathNode* l, MathNode* r) : left(l), right(r)
{

}


MathNode::~MathNode()
{
    delete left;
    delete right;
}

AddNode::AddNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}

double AddNode::executeOperation()
{
    return left->executeOperation() + right->executeOperation();
}

SubtractNode::SubtractNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}

double SubtractNode::executeOperation()
{
    return left->executeOperation() - right->executeOperation();
}

MultiplyNode::MultiplyNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}

double MultiplyNode::executeOperation()
{
    return  left->executeOperation() * right->executeOperation();
}

DivideNode::DivideNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}

double DivideNode::executeOperation()
{
    return left->executeOperation() / right->executeOperation();
}

PowerNode::PowerNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}

double PowerNode::executeOperation()
{
    return powf(left->executeOperation(), right->executeOperation());
}

NumberNode::NumberNode(double num, MathNode* l, MathNode* r) : MathNode(l, r),
    numberValue(num)
{

}

double NumberNode::executeOperation()
{
    return numberValue;
}

XNode::XNode(MathNode* l, MathNode* r) : MathNode(l, r)
{

}


double XNode::x = 0;

void XNode::setX(double newX)
{
    x = newX;
}

double XNode::executeOperation()
{
    return x;
}
