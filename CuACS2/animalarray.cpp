#include "animalarray.h"

AnimalArray::AnimalArray()
{
    size = 0;
}

bool AnimalArray::addAnimal(Animal* a)
{
    if(size >= 256)
        return false;

    elements[size++] = a;
    return true;
}

int AnimalArray::getSize()
{
    return size;
}

int AnimalArray::findAnimal(int aId)
{
    for (int i = 0; i < getSize(); i++) {
        if(elements[i]->getID() == aId) {
            return i;
        }
    }
    return -1;
}

Animal* AnimalArray::getAnimal(int i) {
    return elements[i];
}

bool AnimalArray::setAnimal(int i,Animal* a) {
    elements[i] = a;
    return true;
}

