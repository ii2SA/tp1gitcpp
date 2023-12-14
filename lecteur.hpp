#ifndef D_LECTEUR
#define D_LECTEUR

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Lecteur : public Livre
{
protected:
    std::string _nom;
    std::string _prenom;
    int _id;
    std::vector<int> _listeISBN;

public:
    Lecteur(std::string _nom, std::string _prenom, int _id, std::vector<int> _listeISBN);
    ~Lecteur();
    void setListISBN();
};

#endif