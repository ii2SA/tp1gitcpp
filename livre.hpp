#ifndef D_LIVRE
#define D_LIVRE

#include <iostream>
#include <string>
#include <vector>

#include <ctime>

class livre : public lecteur

{
private:
    std::string _titre;
    std::string _auteur;
    std::string _langue;
    std::string _genre;
    time_t _publication;
    int _ISBN;
    std::vector<int> _listeid;

public:
    livre();
    ~livre();
    livre(livre &);
    livre(std::string titre, std::string auteur, std::string langue, std::string genre, time_t publication, int ISBN, std::vector<int> listeid);
    void setListID();
    // void datePublication();
};

#endif