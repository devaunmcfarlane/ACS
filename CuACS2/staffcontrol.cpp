#include "staffcontrol.h"

using namespace std;

StaffControl::StaffControl()
{

}

StaffControl::StaffControl(database* database) {
    staffArray = new StaffArray();

    db = database;

    launch();
}

StaffControl::~StaffControl() {
    returnAllDataToDb();
}

void StaffControl::launch() {
    QSqlQuery animals = db->getAllAnimals();
    QSqlQuery staff = db->getAllStaff();
    QSqlQuery clients = db->getAllClients();

    while(staff.next()) {
            Staff* stf = new Staff(staff.value(0).toInt(), staff.value(1).toString(), staff.value(2).toString());
            if (staffArray->addStaff(stf)) {
                qDebug() << "Staff Added to StaffControl Array!";
            }
        }
}

void StaffControl::returnAllDataToDb() {
    db->deleteData();  //remove all data so updated data can be entered

    for(int i = 0; i < staffArray->getSize(); i++) { //loop through Staff
        Staff* stf = staffArray->getStaff(i);
        db->addStaff(stf->getID(), stf->getName(), stf->getPassword());
    }
}







