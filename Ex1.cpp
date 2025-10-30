#include <iostream>
#include <cmath>
using namespace std;

class Forme {
public:
    virtual double aire() const = 0;
    virtual void afficher() const = 0;
    virtual ~Forme() {}
};

class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(double r) : rayon(r) {}
    double aire() const override {
        return M_PI * rayon * rayon;
    }
    void afficher() const override {
        cout << "cercle de rayon " << rayon << " son aire est  : " << aire() << endl;
    }
};

class Rectangle : public Forme {
private:
    double longueur;
    double largeur;
public:
    Rectangle(double l, double L) : longueur(l), largeur(L) {}
    double aire() const override {
        return longueur * largeur;
    }
    void afficher() const override {
        cout << "rectangle de " << longueur  << largeur<< "son aire est : " << aire() << endl;
    }
};

int main() {
    int n;
    cout << "combien de formes voulez-vous créer ? ";
    cin >> n;

    Forme** tableau = new Forme*[n];

    for (int i = 0; i < n; i++) {
        int choix;
        cout << "forme " << i + 1 << " (taper 1 pour  cercle ou 2 pour rectangle) : ";
        cin >> choix;

        if (choix == 1) {
            double r;
            cout << "donner le rayon du cercle : ";
            cin >> r;
            tableau[i] = new Cercle(r);
        } else if (choix == 2) {
            double l, L;
            cout << "donner la longueur du rectangle : ";
            cin >> l;
            cout << "donner la largeur du rectangle : ";
            cin >> L;
            tableau[i] = new Rectangle(l, L);
        } else {
            tableau[i] = new Cercle(1);
        }
    }

    cout << "aires des formes :"<<endl;
    for (int i = 0; i < n; i++) {
        tableau[i]->afficher();
    }

    for (int i = 0; i < n; i++) {
        delete tableau[i];
    }
    delete[] tableau;

    return 0;
}
