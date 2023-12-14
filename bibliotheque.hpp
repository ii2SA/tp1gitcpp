#ifndef D_BIBLIOTHEQUE
#define D_BIBLIOTHEQUE

#include <iostream>
#include <string>
#include <vector>
#include "date.hpp"
#include <ctime>

class Bibliotheque : public Livre, public Lecteur , public Emprunt
{
 protected:



 public:
   Bibliotheque(std::string name , std::string adresse , std::string email);
    ~Bibliotheque();
    estDisponible();
};

Bibliotheque::Bibliotheque(/* args */)
{
}

Bibliotheque::~Bibliotheque()
{
}

inline Bibliotheque::estDisponible()
{
    cout<<"Une personne est deja en possession de ce livre. veuillez en choisir un autre"<<
}

