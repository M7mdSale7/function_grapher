#ifndef MATHEXECUTER_H
#define MATHEXECUTER_H
#include <string>
#include "mathnode.h"
using std::string;

class MathExecuter
{
private:
    string expression;
    MathNode *root;
public:
    MathExecuter(string exp);
    MathNode *createTree(int startIndex, int length);
    double executeForX(double x);
};

#endif // MATHEXECUTER_H
