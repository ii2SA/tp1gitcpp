#ifndef D_LECTEUR
#define D_LECTEUR

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class lecteur : public livre
{
private:
    std::string _nom;
    std::string _prenom;
    int _id;
    std::vector<int> _listeISBN;

public:
    lecteur(std::string _nom, std::string _prenom, int _id, std::vector<int> _listeISBN);
    ~lecteur();
    void setListISBN();
};

#endif