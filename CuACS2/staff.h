#ifndef STAFF_H
#define STAFF_H

#include <QString>
#include <QDebug>

class Staff
{
public:
    Staff();
    Staff(int,QString,QString);
    ~Staff();
    int getID();
    bool setID(int);
    QString getName();
    bool setName(QString);
    QString getPassword();
    bool setPassword(QString);
private:
    int ID;
    QString name;
    QString password;
};

#endif // STAFF_H
