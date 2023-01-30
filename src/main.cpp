#include "Student.h"
//#include "Angajat.h"
//#include "Student_licenta.h"
//#include "Student_master.h"
#include<vector>

//curs 20: functii virtuale si polimorfism
class Enemy
{
    public:
        Enemy()
            {
                std::cout<<"Enemy created\n";
            }
        
        virtual void Attack()
        {
            std::cout<<"Enemy attacks with power "<<attackPower<<std::endl;
        }
        virtual ~Enemy()
        /*in general pt clasa de baza destructorul se declara virtual,(intotdeauna cand avem mostenire), 
        -ca sa ne asiguram ca obiectul de baza va fi distrus (in special daca folosim heap)
        - pt ca nu stim ce se intampla cu codul nostru mai departe, ce clase derivate se creaza, etc
        -keywordul "virtual" vine cu un cost: se creaza in memorie(pe langa stack si heap) Vtable
        -Vtable contine niste adrese in care se afla functiile virtuale*/
        {
            std::cout<<"Enemy destroyed\n";
        }

    protected:
        int attackPower;
        void setAttackPower(int a)
        {
            attackPower=a;
        }

};

class Ninja: public Enemy
{
    public:
        Ninja()
            {
                std::cout<<"Ninja created\n";
                setAttackPower(20);
            }
        ~Ninja()
        {
            std::cout<<"Ninja destroyed\n";
        }
        
        void attack()
        {
            std::cout<<"Ninja attacks with power "<<attackPower<<std::endl;
        }
};

class Monster:public Enemy
{
    public:
        Monster()
            {
                std::cout<<"Monster created\n";
                setAttackPower(30);
            }
        ~Monster()
        {
            std::cout<<"Monster destroyed\n";
        }
        void attack()
            {
                std::cout<<"Monster attacks with power "<<attackPower<<std::endl;
            }
        
};

class Orc:public Enemy
{
    public:
        Orc()
            {
                std::cout<<"Orc created\n";
                setAttackPower(40);
            }
        ~Orc()
        {
            std::cout<<"Orc destroyed\n";
        }
    void Attack()
    {
        std::cout<<"orc attacks with power "<<attackPower<<std::endl;
    }
};

void BattleScene(Enemy* e)
{
    std::cout<<"Un inamic te ataca\n";
    e->Attack();
}

void EnemyCleanUp(Enemy* e)
{
    std::cout<<"We will cleanup/delete an Enemy object\n";
    delete e;
}


//problema diamant
class A
{
public:
   A()
    {
        std::cout<<"A was created\n";
    }
   ~A()
    {
        std::cout<<"A was deleted\n";
    }
};
class B: virtual public A
{
public:
   B()
    {
        std::cout<<"B was created\n";
     }
   ~B()
     {
        std::cout<<"B was deleted\n";
    }
};
class C: virtual public A
{
public:
   C()
    {
        std::cout<<"C was created\n";
    }
   ~C()
    {
        std::cout<<"C was deleted\n";
     }
};
class D: public B, public C
{
public:
   D()
    {
        std::cout<<"D was created\n";
    }
   ~D()
    {
        std::cout<<"D was deleted\n";
     }
};

int main(int argc, char const *argv[])
{

   // D* d= new D();
    //delete d;

    std::vector<Enemy*> enemyList;

    enemyList.push_back(new Ninja()); //creez pe heap un ninja si il bag in vectorul enemyList
    enemyList.push_back(new Orc());
    enemyList.push_back(new Monster());

    /*for(int i=0; i<enemyList.size(); i++)
    {
        BattleScene(enemyList[i]);
    }*/ //-> o varianta




    for(std::vector<Enemy*>::iterator it=enemyList.begin(); it!=enemyList.end(); it++)
    {
        BattleScene(*it);
    } // a doua varianta cu iteratori




   /*for(auto it=enemyList.begin(); it!=enemyList.end(); it++)
    {
        BattleScene(*it);
    } // a treia varianta , se foloseste "auto"*/
     



     for(auto* enemy: enemyList) //traducere pt fiecare inamic din enemylist
        {
            BattleScene(enemy);
        } // a patra varianta , se foloseste "auto"
    for(auto* enemy: enemyList) 
        {
            delete enemy;
        } 
        enemyList.clear();
        std::cout<<"Lista are dimensiunea "<<enemyList.size()<<std::endl;

    //Monster m;
    Ninja* n= new Ninja;

    Enemy* e1 = n; 
    BattleScene(e1);

    EnemyCleanUp(e1);
   




    Enemy* e2=n;


    //e1->setAttackPower(20);
    //e2->setAttackPower(30);
    BattleScene(e1);
    BattleScene(e2);
    Orc o;
    Enemy* e3=&o;
    BattleScene(e3); 




    /*Student* s = new Student(19, "Sergiu"); //s-a folosit un pointer catre un obiect pe heap
    s->sayHello();//prin "->" se dereferentiaza si acceseaza metoda de la adresa respectiva  = (*s).sayHello();
    std::cout<<"Varsta este "<<s->getVarsta()<<std::endl;

    Student_licenta* Ioana=new Student_licenta(21, "Ioana");
    Ioana->sayHello();
    Student_master* Maria=new Student_master();
    Student Denisa;
    Denisa.sayHello();*/


    

    //delete s;
    return 0;
}
