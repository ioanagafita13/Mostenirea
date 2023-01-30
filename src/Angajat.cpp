#include "Angajat.h"

Angajat::Angajat(std::string nume):
Persoana(nume)
{
    std::cout<<"Un angajat a fost creat\n";
}

Angajat::~Angajat()
{
    std::cout<<"Un angajat a fost distrus\n";
}