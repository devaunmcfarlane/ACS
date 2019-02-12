#ifndef ANIMALCONTROL_H
#define ANIMALCONTROL_H

#include "animal.h"
#include "animalarray.h"
#include <database.h>
#include <QString>

class AnimalControl
{
public:
    AnimalControl();
    ~AnimalControl();
    AnimalControl(database*);
    void launch();
    void returnAllDataToDb();
    bool addAnimal(QString,QString,QString,QString,QString,QString);
    int largestAnimalId;
    AnimalArray* getAllAnimals();
private:
    AnimalArray* animalArray;
    database* db;

};

#endif // ANIMALCONTROL_H
