#include "animal.h"

Animal::Animal()
{

}

Animal::Animal(int i, QString t, QString b, QString a, QString s, QString c, QString w)
{
    id = i;
    type = t;
    breed = b;
    age = a;
    size = s;
    colour = c;
    weight = w;
}

Animal::~Animal()
{

}

int Animal::getID()
{
    return id;
}

bool Animal::setID(int ID)
{
    this->id = ID;
    return true;
}

QString Animal::getType()
{
    return type;
}

bool Animal::setType(QString type)
{
    this->type = type;
    return true;
}

QString Animal::getBreed()
{
    return breed;
}

bool Animal::setBreed(QString breed)
{
    this->breed = breed;
    return true;
}

QString Animal::getSize()
{
    return size;
}

bool Animal::setSize(QString size)
{
    this->size = size;
    return true;
}

QString Animal::getAge()
{
    return age;
}

bool Animal::setAge(QString age)
{
    this->age = age;
    return true;
}

QString Animal::getColour()
{
    return colour;
}

bool Animal::setColour(QString colour)
{
    this->colour = colour;
    return true;
}

QString Animal::getWeight()
{
    return weight;
}

bool Animal::setWeight(QString weight)
{
    this->weight = weight;
    return true;
}
