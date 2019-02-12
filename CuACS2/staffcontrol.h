#ifndef STAFFCONTROL_H
#define STAFFCONTROL_H

#include <staff.h>
#include <staffarray.h>
#include <database.h>
#include <QString>

class StaffControl
{
public:
    StaffControl();
    ~StaffControl();
    StaffControl(database*);
    void launch();
    void returnAllDataToDb();
    StaffArray* test();
    bool checkPassword(int, QString);
private:
    database* db;
    StaffArray* staffArray;
};

#endif // STAFFCONTROL_H
