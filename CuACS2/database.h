#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



class database
{
public:
    database(QSqlDatabase db);
    ~database();
    void initializeDatabase(QSqlDatabase db);
    int checkStaff(int id);
    QSqlQuery getAllAnimals();
    QSqlQuery getAllClients();
    QSqlQuery getAllStaff();
    void deleteData();
    void addAnimal(int id, QString type, QString breed, QString age, QString size, QString colour, QString weight);
    void addStaff(int id, QString name, QString password);
};

#endif // DATABASE_H
