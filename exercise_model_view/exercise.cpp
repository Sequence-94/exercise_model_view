#include "exercise.h"

Exercise::Exercise(): data{"UNKNOWN"}, num{0}
{
}

Exercise::Exercise(QString d, int n): data{d}, num{n}
{
}

void Exercise::setData(QString d)
{
    data = d;
}

void Exercise::setNum(int n)
{
    num = n;
}

QString Exercise::getData() const
{
    return data;
}

int Exercise::getNum() const
{
    return num;
}
