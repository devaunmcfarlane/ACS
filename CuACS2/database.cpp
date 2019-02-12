#include "database.h"

database::database(QSqlDatabase db)
{
    initializeDatabase(db);
}

database::~database() {
}

void database::initializeDatabase(QSqlDatabase db) {

    //  opening database
    if(!db.open()) {
        qDebug() << "Connection Error:" << db.lastError().text();
    }

   qDebug() << "Opened the database!";

   QSqlQuery qry;
   //  creating tables within database

   /*
   qry.prepare("DELETE FROM animals");
   if(!qry.exec()) {
       qDebug() << "Deleting Error: " << qry.lastError().text();
   }
   else {
       qDebug() << "Deleted Animals";
   }
   qry.prepare("DELETE FROM staff");
   if(!qry.exec()) {
       qDebug() << "Deleting Error: " << qry.lastError().text();
   }
   else {
       qDebug() << "Deleted Staff";
   }
   */

   qry.prepare( "CREATE TABLE IF NOT EXISTS animals (id INTEGER UNIQUE PRIMARY KEY, type VARCHAR(30), breed VARCHAR(30), age VARCHAR(30), size VARCHAR(30), colour VARCHAR(30), weight VARCHAR(30))" );
   if( !qry.exec() )
       qDebug() << qry.lastError().text();
   else {
       qDebug() << "Animal table created!";
   }

   QSqlQuery a,b;
   a.prepare("INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
   a.bindValue(":id", 1001);
   a.bindValue(":type", "Dog");
   a.bindValue(":breed", "Aussie");
   a.bindValue(":age", "1");
   a.bindValue(":size", "Small");
   a.bindValue(":colour", "Black");
   a.bindValue(":weight", "20 lbs");
   if(!a.exec()) {
       qDebug() << "Animal error: " << a.lastError().text();
   }

   b.prepare("INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
   b.bindValue(":id", 1002);
   b.bindValue(":type", "Cat");
   b.bindValue(":breed", "Persian");
   b.bindValue(":age", "3");
   b.bindValue(":size", "Small");
   b.bindValue(":colour", "White");
   b.bindValue(":weight", "10 lbs");
   if(!b.exec()) {
       qDebug() << "Animal error: " << b.lastError().text();
   }

   a.prepare("INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
   a.bindValue(":id", 1003);
   a.bindValue(":type", "Dog");
   a.bindValue(":breed", "Poodle");
   a.bindValue(":age", "7");
   a.bindValue(":size", "Small");
   a.bindValue(":colour", "Grey");
   a.bindValue(":weight", "12 lbs");
   if(!a.exec()) {
       qDebug() << "Animal error: " << a.lastError().text();
   }

   b.prepare("INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
   b.bindValue(":id", 1004);
   b.bindValue(":type", "Cat");
   b.bindValue(":breed", "Russian Blue");
   b.bindValue(":age", "3");
   b.bindValue(":size", "Small");
   b.bindValue(":colour", "White");
   b.bindValue(":weight", "10 lbs");
   if(!b.exec()) {
       qDebug() << "Animal error: " << b.lastError().text();
   }

   b.prepare("INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
   b.bindValue(":id", 1005);
   b.bindValue(":type", "Dog");
   b.bindValue(":breed", "Golden Retriever");
   b.bindValue(":age", "6");
   b.bindValue(":size", "Large");
   b.bindValue(":colour", "Gold");
   b.bindValue(":weight", "50 lbs");
   if(!b.exec()) {
       qDebug() << "Animal error: " << b.lastError().text();
   }

   qry.prepare( "CREATE TABLE IF NOT EXISTS clients (ClientID INTEGER UNIQUE PRIMARY KEY, name VARCHAR(30), password VARCHAR(30))" );
   if(!qry.exec())
       qDebug() << qry.lastError().text();
   else {
       qDebug() << "Client table created!";
   }

   qry.prepare( "CREATE TABLE IF NOT EXISTS staff (StaffID INTEGER UNIQUE PRIMARY KEY, name VARCHAR(30), password VARCHAR(30))" );
   if(!qry.exec())
       qDebug() << qry.lastError().text();
   else {
       qDebug() << "Staff table created!";
   }

   //if no user has id 1000 add that staff.  This way there will always be at least one staff.  Ids start at 1000.
   qry.prepare("INSERT INTO staff (StaffID, name, password) VALUES (1000, 'Super', 'password')");
   if(!qry.exec()) {
       qDebug() << "Staff already in system, no problem here.";
   }
   else {
       qDebug() << "Staff inserted to the staff table in database!";
   }
}

int database::checkStaff(int id) {
    QSqlQuery qry;
    qry.prepare("SELECT * from staff");
    if(!qry.exec()) {
        qDebug() << qry.lastError().text();
        qDebug() << "Error with checking staff in staff table";
        return 0;
    }
    while(qry.next()) {
        if(qry.value(0) == id) {
            return 1;
        }
    }
    return 0;
}

QSqlQuery database::getAllAnimals() {
    QSqlQuery qry;
    qry.prepare("SELECT * from animals");
    if(!qry.exec()) {
        qDebug() << "Problem returning all animals: " << qry.lastError().text();
        return qry;
    }
    return qry;
}

QSqlQuery database::getAllClients() {
    QSqlQuery qry;
    qry.prepare("SELECT * from clients");
    if(!qry.exec()) {
        qDebug() << "Problem returning all clients: " << qry.lastError().text();
        return qry;
    }
    return qry;
}

QSqlQuery database::getAllStaff() {
    QSqlQuery qry;
    qry.prepare("SELECT * from staff");
    if(!qry.exec()) {
        qDebug() << "Problem returning all staff: " << qry.lastError().text();
        return qry;
    }
    return qry;
}


void database::addAnimal(int id, QString type, QString breed, QString age, QString size, QString colour, QString weight) {
    QSqlQuery qry;

    qry.prepare( "INSERT INTO animals (id, type, breed, age, size, colour, weight) VALUES (:id, :type, :breed, :age, :size, :colour, :weight)");
    qry.bindValue(":id", id);
    qry.bindValue(":type", type);
    qry.bindValue(":breed", breed);
    qry.bindValue(":age", age);
    qry.bindValue(":size", size);
    qry.bindValue(":colour", colour);
    qry.bindValue(":weight", weight);

    if( !qry.exec() ) {
        qDebug() << "Problem adding animal - " << qry.lastError().text();
        return;
    }
    qDebug() << "Animal added to animals table";
}

void database::addStaff(int id, QString name, QString password) {
    QSqlQuery qry;

    qry.prepare( "INSERT INTO staff (StaffID, name, password) VALUES (:id, :name, :password)");
    qry.bindValue(":StaffID", id);
    qry.bindValue(":name", name);
    qry.bindValue(":password", password);

    if( !qry.exec() ) {
        qDebug() << "Problem adding staff - " << qry.lastError().text();
        return;
    }
    qDebug() << "Staff added to staff table";
}

void database::deleteDataAnimals() {
    QSqlQuery qry;

    qry.prepare("DELETE FROM animals");
    if(!qry.exec()) {
        qDebug() << "1  -"<< qry.lastError().text();
    }
}
void database::deleteDataStaff() {
    QSqlQuery qry;

    qry.prepare("DELETE FROM staff");
    if(!qry.exec()) {
        qDebug() << "2 -- "<< qry.lastError().text();
    }
}
void database::deleteDataClients() {
    QSqlQuery qry;

    qry.prepare("DELETE FROM clients");
    if( !qry.exec()) {
        qDebug() << "3 -- "<<qry.lastError().text();
    }
}
