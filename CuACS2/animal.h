#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

class Animal
{
public:
    Animal();
    Animal(int id, QString type, QString breed, QString age, QString size, QString colour, QString weight);
    ~Animal();
    int getID();
    bool setID(int);
    QString getType();
    bool setType(QString);
    QString getBreed();
    bool setBreed(QString);
    QString getAge();
    bool setAge(QString);
    QString getSize();
    bool setSize(QString);
    QString getColour();
    bool setColour(QString);
    QString getWeight();
    bool setWeight(QString);
private:
    int id;
    QString type;
    QString breed;
    QString age;
    QString size;
    QString colour;
    QString weight;
};

#endif // ANIMAL_H
