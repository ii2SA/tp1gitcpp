#ifndef D_LIVRE
#define D_LIVRE

#include <iostream>
#include <string>
#include <vector>
#include "date.hpp"
#include <ctime>


class Livre : public Lecteur
{
 protected:
    std::string _titre;
    std::string _auteur;
    std::string _langue;
    std::string _genre;
    Date _publication;
    int _ISBN;
    std::vector<int> _listeid;
    Date date;
 public:

    ~Livre();
    Livre(Livre &);
    Livre(std::string titre = "none", std::string auteur="none", std::string langue="english", std::string genre="none", Date publication, int ISBN=0, std::vector<int=0> listeid);
    void setListID();
    // void datePublication();
    std::string getTitre();
    std::string getAuteur();
    std::string getLangue();
    std::string getGenre();
    Date getPublication();
    std::string getISBN();
    // std::string getListID();



};

#endif