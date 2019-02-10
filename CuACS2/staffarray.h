#ifndef STAFFARRAY_H
#define STAFFARRAY_H

#include "staff.h"

class StaffArray
{
public:
    StaffArray();
    ~StaffArray();
    bool addStaff(Staff*);
    bool removeStaff(int);
    Staff* getStaff(int);
    bool setStaff(int,Staff*);
    int getSize();
    int findStaff(int);
private:
    Staff* elements[256];
    int size;
};

#endif // STAFFARRAY_H
