#include "animalcontrol.h"

AnimalControl::AnimalControl()
{

}

AnimalControl::AnimalControl(database* database) {
    animalArray = new AnimalArray();
    largestAnimalId = 1000;
    db = database;

    launch();
}

AnimalControl::~AnimalControl() {
    returnAllDataToDb();
}

void AnimalControl::launch() {
    QSqlQuery animals = db->getAllAnimals();

    while(animals.next()) {
            Animal* stf = new Animal(animals.value(0).toInt(), animals.value(1).toString(), animals.value(2).toString(), animals.value(3).toString(), animals.value(4).toString(), animals.value(5).toString(), animals.value(6).toString());
            if (animalArray->addAnimal(stf)) {
                qDebug() << "Animal Added! " << animals.value(0).toInt() << " " << animals.value(1).toString() << " " << animals.value(2).toString() << " " << animals.value(3).toString() << " " << animals.value(4).toString() << " " <<animals.value(5).toString() << " " <<animals.value(6).toString();
            }
            if(animals.value(0).toInt() > largestAnimalId) {
                largestAnimalId = animals.value(0).toInt();
            }
        }

}

void AnimalControl::returnAllDataToDb() {
    db->deleteDataAnimals();  //remove all animals so updated data can be entered

    for(int i = 0; i < animalArray->getSize(); i++) { //loop through Animals
        Animal* stf = animalArray->getAnimal(i);
        db->addAnimal(stf->getID(), stf->getType(), stf->getBreed(), stf->getAge(), stf->getSize(), stf->getColour(), stf->getWeight());
    }
}

bool AnimalControl::addAnimal(QString t,QString b,QString a,QString s,QString c,QString w) {
    largestAnimalId++;
    Animal* animalToAdd = new Animal(largestAnimalId,t,b,a,s,c,w);
    bool result = animalArray->addAnimal(animalToAdd);
    return result;
}

AnimalArray* AnimalControl::getAllAnimals() {
    return animalArray;
}
