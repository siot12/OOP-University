#include <iostream>
#include "Contact.h"
#include "Enum.h"
using namespace std;

class Prieten: public Contact
{
    const char* datanastere="3 Mai 2000";
    const char* nrtel="0755432532";
    const char* adress="Bucuresti";
public:
    Prieten()
    {
        nume = "Rolly";
    }
};

class Necunoscut:public Contact
{
    const char * nr="0732456987";
public:
    Necunoscut()
    {
        nume = "Baby";
    }
};

class Coleg:public Contact
{
    const char* nrtel="07564214521";
    const char* firma="Cervix Inc.";
    const char* adress="Timisoara";
public:
    Coleg()
    {
        nume = "Albert";
    }
};

class Agenda
{
    Contact* contacte[100];
    int nrcontacte=0;
public:
    Agenda& AddContact(Contact* obj)
    {
        contacte[nrcontacte] = obj;
        nrcontacte++;
        return *this;
    }
    Agenda& DeleteContact(const char* nume)
    {
        for (int i = 0;i < nrcontacte;i++)
        {
            if (nume == contacte[i]->GetName())
            {
                contacte[i] = contacte[i + 1];
            }
       }
        nrcontacte--;
        return *this;
    }
    void PrintFriendList()
    {
        for (int i = 0;i < nrcontacte;i++)
        {
            if (dynamic_cast<Prieten*>(contacte[i])!= nullptr)
            {
                cout << contacte[i]->GetName()<<" ";
           }
        }
        cout << endl;
    }
    bool FindContact(const char* nume)
    {
        for (int i = 0;i < nrcontacte;i++)
        {
            if (nume == contacte[i]->GetName())
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Agenda a;
    a.AddContact(new Prieten);
    a.AddContact(new Prieten);
    a.AddContact(new Necunoscut);
    cout << a.FindContact("Rolly") << endl;
    a.PrintFriendList();
    a.DeleteContact("Rolly");
    a.PrintFriendList();
    return 0;
}

