#include "mathexecuter.h"
#include <string>
#include <QMessageBox>
#include <QString>


MathExecuter::MathExecuter(string exp) : expression(exp)
{
    root = createTree(0, expression.size() - 1);
}

MathNode *MathExecuter::createTree(int startIndex, int endIndex)
{

    for(int i = startIndex; i <= endIndex; i++)
    {
        if(expression[i] == '+')
        {
            return new AddNode(createTree(startIndex, i-1), createTree(i+1, endIndex));
        }
        else if(expression[i] == '-')
        {
            return new SubtractNode(createTree(startIndex, i-1), createTree(i+1, endIndex));
        }
    }

    for(int i = startIndex; i <= endIndex; i++)
    {
        if(expression[i] == '*')
        {
            return new MultiplyNode(createTree(startIndex, i-1), createTree(i+1, endIndex));
        }
        else if(expression[i] == '/')
        {
            return new DivideNode(createTree(startIndex, i-1), createTree(i+1, endIndex));
        }
    }

    if(expression[startIndex] == 'x')
        return new XNode(nullptr, nullptr);

     return new NumberNode(std::stod(expression.substr(startIndex, endIndex - startIndex+1))
                           , nullptr, nullptr);
}

double MathExecuter::executeForX(double xVal)
{
    XNode::setX(xVal);
    return root->executeOperation();
}
