#ifndef ANIMALARRAY_H
#define ANIMALARRAY_H

#include "animal.h"

class AnimalArray
{
public:
    AnimalArray();
    ~AnimalArray();
    bool addAnimal(Animal*);
    bool removeAnimal(int);
    Animal* getAnimal(int);
    bool setAnimal(int,Animal*);
    int getSize();
    int findAnimal(int);
private:
    Animal* elements[256];
    int size;
};

#endif // ANIMALARRAY_H
