#include "staffarray.h"

StaffArray::StaffArray()
{
    size = 0;
}

StaffArray::~StaffArray()
{

}

bool StaffArray::addStaff(Staff* stf)
{
    if(size >= 256)
        return false;

    elements[size++] = stf;
    return true;
}

int StaffArray::getSize()
{
    return size;
}

int StaffArray::findStaff(int staffId)
{
    for (int i = 0; i < getSize(); i++) {
        if(elements[i]->getID() == staffId) {
            return i;
        }
    }
    return -1;
}

Staff* StaffArray::getStaff(int i) {
    return elements[i];
}

bool StaffArray::setStaff(int i,Staff* staff) {
    elements[i] = staff;
    return true;
}

bool StaffArray::checkPassword(int staffId, QString password) {
    for (int i = 0; i < getSize(); i++) {
        if((elements[i]->getID() == staffId) && (elements[i]->getPassword() == password)) {
            return true;
        }
    }
    return false;
}
