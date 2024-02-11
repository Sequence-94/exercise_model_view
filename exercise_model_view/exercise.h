#ifndef EXERCISE_H
#define EXERCISE_H

#include <QString>
#include <QObject>

class Exercise : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data READ getData WRITE setData)
    Q_PROPERTY(int num READ getNum WRITE setNum)
public:
    Exercise();
    Exercise(QString d, int n);
    void setData(QString d);
    void setNum(int n);
    QString getData() const;
    int getNum() const;
private:
    QString data;
    int num;
};

#endif // EXERCISE_H
