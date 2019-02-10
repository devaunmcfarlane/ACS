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
private:
    StaffArray* staffArray;
    database* db;
};

#endif // STAFFCONTROL_H
