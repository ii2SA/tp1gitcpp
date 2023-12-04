#include "livre.hpp"

livre::livre()
{
}

livre::livre(std::string titre, std::string auteur, std::string langue, std::string genre, time_t publication, int ISBN, std::vector<int> listeid) : _publication(ctime(&publication))
{
}

/*livre::datePublication()
{
    if (time(&_publication) == -1)
    {
        std::cout << "date invalide" << exit(1);
    }
    _publication = ctime(&_publication);

}*/

void livre::setListID() : lecteur(_id)
{
    _listeid.push_back(_id);
    _listeid = _listeid;
}

livre::~livre()
{
}
