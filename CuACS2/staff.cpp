#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(int id,QString name,QString password)
{
    ID = id;
    name = name;
    password = password;
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


