#include "animal.h"

Animal::Animal()
{

}

Animal::Animal(int id, QString type, QString breed, QString age, QString size, QString colour, QString weight)
{
    id = id;
    type = type;
    breed = breed;
    age = age;
    size = size;
    colour = colour;
    weight = weight;
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
