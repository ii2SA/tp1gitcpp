#ifndef D_EMPRUNT
#define D_EMPRUNT

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class emprunt : public livre , public lecteur
{
private:
    std::string _dateEmprunt;

public:
    emprunt();
    emprunt(time_t dateEmprunt, int ISBN, int id) : _dateEmprunt(ctime(&dateEmprunt)) livre(_ISBN(ISBN)) lecteur(_id(id));
    ~emprunt();
};

#endif