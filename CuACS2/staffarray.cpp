#include "staffarray.h"

StaffArray::StaffArray()
{
    size = 0;
}

StaffArray::~StaffArray()
{

}

bool StaffArray::addStaff(Staff* emp)
{
    if(size >= 256)
        return false;

    elements[size++] = emp;
    return true;
}

bool StaffArray::removeStaff(int i)
{

}

int StaffArray::getSize()
{
    return size;
}

int StaffArray::findStaff(int eId)
{
    for (int i = 0; i < getSize(); i++) {
        if(elements[i]->getID() == eId) {
            return i;
        }
    }
    return -1;
}

Staff* StaffArray::getStaff(int i) {
    return elements[i];
}

bool StaffArray::setStaff(int i,Staff* emp) {
    elements[i] = emp;
    return true;
}
