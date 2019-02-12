#ifndef STAFFARRAY_H
#define STAFFARRAY_H

#include "staff.h"
#include <QDebug>

class StaffArray
{
public:
    StaffArray();
    ~StaffArray();
    bool addStaff(Staff*);
    Staff* getStaff(int);
    bool setStaff(int,Staff*);
    int getSize();
    int findStaff(int);
    bool checkPassword(int, QString);
private:
    Staff* elements[256];
    int size;
};

#endif // STAFFARRAY_H
