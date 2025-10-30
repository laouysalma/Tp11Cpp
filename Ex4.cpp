#include <iostream>
#include <string>
using namespace std;

class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;
    virtual ~NoeudFichier() {}
};

class Fichier : public NoeudFichier {
private:
    string _nom;
    int _taille;
public:
    Fichier(string n, int t) : _nom(n), _taille(t) {}
    string nom() const override { return _nom; }
    int taille() const override { return _taille; }
};

class Dossier : public NoeudFichier {
private:
    string _nom;
    NoeudFichier** enfants;
    int nbEnfants;
public:
    Dossier(string n, int nb) : _nom(n), nbEnfants(nb) {
        enfants = new NoeudFichier*[nbEnfants];
    }
    void ajouterEnfant(int index, NoeudFichier* nf) {
        if(index >=0 && index < nbEnfants)
            enfants[index] = nf;
    }
    string nom() const override { return _nom; }
    int taille() const override {
        int sum = 0;
        for(int i=0; i<nbEnfants; i++)
            sum += enfants[i]->taille();
        return sum;
    }
    ~Dossier() {
        for(int i=0;i<nbEnfants;i++)
            delete enfants[i];
        delete[] enfants;
    }
};

int main() {
    int nbFichiers;
    cout << "combien de fichiers dans le dossier ? ";
    cin >> nbFichiers;

    Dossier* dossier = new Dossier("MonDossier", nbFichiers);

    for(int i=0;i<nbFichiers;i++){
        string nom;
        int tailleF;
        cout << "nom du fichier " << i+1 << " : ";
        cin >> nom;
        cout << "taille du fichier " << i+1 << " : ";
        cin >> tailleF;
        dossier->ajouterEnfant(i, new Fichier(nom, tailleF));
    }

    cout << "taille totale du dossier " << dossier->nom() << " : " << dossier->taille() << " Ko" << endl;

    delete dossier;

    return 0;
}
