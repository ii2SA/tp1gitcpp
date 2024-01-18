#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
    int jour;
    int mois;
    int annee;

public:
    Date(int _jour, int _mois, int _annee) : jour(_jour), mois(_mois), annee(_annee) {}

    int getJour() const {
        return jour;
    }

    int getMois() const {
        return mois;
    }

    int getAnnee() const {
        return annee;
    }

    string toString() const {
        return to_string(jour) + "/" + to_string(mois) + "/" + to_string(annee);
    }
};

class Auteur {
private:
    string nom;

public:
    Auteur(string _nom) : nom(_nom) {}

    string getNom() const {
        return nom;
    }
};

class Livre {
private:
    string titre;
    Auteur* auteur;
    bool disponible;

public:
    Livre(string _titre, Auteur* _auteur) : titre(_titre), auteur(_auteur), disponible(true) {}

    string getTitre() const {
        return titre;
    }

    Auteur* getAuteur() const {
        return auteur;
    }

    bool estDisponible() const {
        return disponible;
    }

    void emprunter() {
        disponible = false;
    }

    void rendre() {
        disponible = true;
    }
};

class Lecteur {
private:
    string nom;
    vector<Livre*> livresEmpruntes;

public:
    Lecteur(string _nom) : nom(_nom) {}

    string getNom() const {
        return nom;
    }

    vector<Livre*> getLivresEmpruntes() const {
        return livresEmpruntes;
    }

    void emprunterLivre(Livre* livre) {
        livresEmpruntes.push_back(livre);
        livre->emprunter();
    }

    void rendreLivre(Livre* livre) {
        for (auto it = livresEmpruntes.begin(); it != livresEmpruntes.end(); ++it) {
            if (*it == livre) {
                livresEmpruntes.erase(it);
                livre->rendre();
                break;
            }
        }
    }
};

class Emprunt {
private:
    Livre* livre;
    Lecteur* lecteur;
    Date dateEmprunt;

public:
    Emprunt(Livre* _livre, Lecteur* _lecteur, Date _dateEmprunt)
        : livre(_livre), lecteur(_lecteur), dateEmprunt(_dateEmprunt) {}

    Livre* getLivre() const {
        return livre;
    }

    Lecteur* getLecteur() const {
        return lecteur;
    }

    Date getDateEmprunt() const {
        return dateEmprunt;
    }
};

class Bibliothèque {
private:
    vector<Livre*> livres;
    vector<Lecteur*> lecteurs;
    vector<Emprunt*> emprunts;

public:
    void ajouterLivre(Livre* livre) {
        livres.push_back(livre);
    }

    void ajouterLecteur(Lecteur* lecteur) {
        lecteurs.push_back(lecteur);
    }

    void emprunterLivre(Livre* livre, Lecteur* lecteur, Date dateEmprunt) {
        Emprunt* emprunt = new Emprunt(livre, lecteur, dateEmprunt);
        emprunts.push_back(emprunt);
        lecteur->emprunterLivre(livre);
    }

    void rendreLivre(Livre* livre, Lecteur* lecteur) {
        for (auto it = emprunts.begin(); it != emprunts.end(); ++it) {
            if ((*it)->getLivre() == livre && (*it)->getLecteur() == lecteur) {
                emprunts.erase(it);
                lecteur->rendreLivre(livre);
                delete *it;
                break;
            }
        }
    }

    vector<Livre*> getLivresDisponibles() const {
        vector<Livre*> disponibles;
        for (Livre* livre : livres) {
            if (livre->estDisponible()) {
                disponibles.push_back(livre);
            }
        }
        return disponibles;
    }

    vector<Emprunt*> getEmpruntsEnCours() const {
        return emprunts;
    }
};

int main() {
    Auteur auteur1(string("J.K. Rowling"));
    Auteur auteur2(string("George R.R. Martin"));
    Auteur auteur3(string("Stephen King"));

    Livre livre1("Harry Potter et la Pierre Philosophale", &auteur1);
    Livre livre2("Le Trône de Fer", &auteur2);
    Livre livre3("Ça", &auteur3);

    Lecteur lecteur1("John Doe");
    Lecteur lecteur2("Jane Smith");

    Bibliothèque bibliotheque;

    bibliotheque.ajouterLivre(&livre1);
    bibliotheque.ajouterLivre(&livre2);
    bibliotheque.ajouterLivre(&livre3);

    bibliotheque.ajouterLecteur(&lecteur1);
    bibliotheque.ajouterLecteur(&lecteur2);

    Date dateEmprunt(15, 1, 2024);

    bibliotheque.emprunterLivre(&livre1, &lecteur1, dateEmprunt);
    bibliotheque.emprunterLivre(&livre2, &lecteur2, dateEmprunt);

    cout << "Livres disponibles : " << endl;
    vector<Livre*> livresDisponibles = bibliotheque.getLivresDisponibles();
    for (Livre* livre : livresDisponibles) {
        cout << livre->getTitre() << " par " << livre->getAuteur()->getNom() << endl;
    }

    cout << "Emprunts en cours : " << endl;
    vector<Emprunt*> empruntsEnCours = bibliotheque.getEmpruntsEnCours();
    for (Emprunt* emprunt : empruntsEnCours) {
        cout << emprunt->getLivre()->getTitre() << " emprunté par " << emprunt->getLecteur()->getNom()
             << " le " << emprunt->getDateEmprunt().toString() << endl;
    }

    return 0;
}
