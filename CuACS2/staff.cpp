#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(int i,QString n,QString p)
{
    ID = i;
    name = n;
    password = p;
}

Staff::~Staff()
{

}

int Staff::getID()
{
    return ID;
}

bool Staff::setID(int ID)
{
    this->ID = ID;
    return true;
}

QString Staff::getName()
{
    return name;
}

bool Staff::setName(QString name)
{
    this->name = name;
    return true;
}

QString Staff::getPassword()
{
    return password;
}

bool Staff::setPassword(QString password)
{
    this->password = password;
    return true;
}


