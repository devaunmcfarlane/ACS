#include "animalcontrol.h"

AnimalControl::AnimalControl()
{

}

AnimalControl::AnimalControl(database* database) {
    animalArray = new AnimalArray();

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
                qDebug() << "Animal Added!";
            }
        }
}

void AnimalControl::returnAllDataToDb() {
    db->deleteData();  //remove all data so updated data can be entered

    for(int i = 0; i < animalArray->getSize(); i++) { //loop through Animals
        Animal* stf = animalArray->getAnimal(i);
        db->addAnimal(stf->getID(), stf->getType(), stf->getBreed(), stf->getAge(), stf->getSize(), stf->getColour(), stf->getWeight());
    }
}
