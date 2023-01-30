#ifndef STUDENT_H
#define STUDENT_H

#pragma once
#include "Persoana.h"

class Student: public Persoana
{
public:
    Student(int varsta, std::string nume);
    Student();
    ~Student();


private:

};

#endif