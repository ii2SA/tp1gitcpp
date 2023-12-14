#ifndef D_EMPRUNT
#define D_EMPRUNT

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Emprunt : public Livre , public Lecteur
{
protected:
    Date _dateEmprunt;

public:
    Emprunt();
    Emprunt(Date dateEmprunt, int ISBN, int id) : _dateEmprunt(dateEmprunt) Livre(_ISBN(ISBN)) Lecteur(_id(id));
    ~Emprunt();
    emLivre(Livre &);
    reLivre(Livre &);
};

#endif