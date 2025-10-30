#include <iostream>
using namespace std;

class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;
    virtual ~Paiement() {}
};

class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "tu a paye " << montant << " DH par carte bancaire." << endl;
    }
};

class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "tu a paye " << montant << " DH en espèces." << endl;
    }
};

int main() {
    int n;
    cout << "Combien de paiements voulez-vous simuler ? ";
    cin >> n;

    Paiement** tableau = new Paiement*[n];

    for (int i = 0; i < n; i++) {
        int choix;
        double montant;
        cout << "paiement " << i + 1 << " (1 = Carte, 2 = Espèces) : ";
        cin >> choix;
        cout << "introduire  le montant : ";
        cin >> montant;

        if (choix == 1) {
            tableau[i] = new PaiementCarte();
        } else if (choix == 2) {
            tableau[i] = new PaiementEspece();
        } else {
            tableau[i] = new PaiementEspece();
        }

        tableau[i]->effectuerPaiement(montant);
    }

    for (int i = 0; i < n; i++) {
        delete tableau[i];
    }
    delete[] tableau;

    return 0;
}
