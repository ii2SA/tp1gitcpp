#include "livre.hpp"

Livre::Livre()
{
}

Livre::Livre(std::string titre, std::string auteur, std::string langue, std::string genre, Date publication, int ISBN, std::vector<int> listeid) : _publication(publication)
{
    _titre = titre;
    _auteur = auteur;
    _langue = langue;
    _genre = genre;
    _publication = publication;
    _ISBN = ISBN;
    // std::vector<int> _listeid;
}

/*livre::datePublication()
{
    if (time(&_publication) == -1)
    {
        std::cout << "date invalide" << exit(1);
    }
    _publication = ctime(&_publication);

}*/

void Livre::setListID() : Lecteur(_id)
{
    _listeid.push_back(_id);
    _listeid = _listeid;
}

Livre::~Livre()
{
}
