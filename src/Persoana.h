#ifndef PERSOANA_H
#define PERSOANA_H

#pragma once
#include<iostream>
#include<string>

class Persoana
{
    std::string m_nume; //private


public:
    Persoana(std::string nume);
    Persoana();
    ~Persoana();

    void sayHello();

    int getVarsta()
    {
        return m_varsta;
    }
    
protected:
    int m_varsta;


};

#endif