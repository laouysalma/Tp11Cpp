#include <iostream>
using namespace std;

class Animal {
public:
    virtual void crier() const = 0;
    void info() const {
        cout << "Je suis un animal." << endl;
    }
    virtual ~Animal() {}
};

class Chien : public Animal {
public:
    void crier() const override {
        cout << "Wouf !" << endl;
    }
};

class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou !" << endl;
    }
};

class Vache : public Animal {
public:
    void crier() const override {
        cout << "Meuh !" << endl;
    }
};

int main() {
    int n;
    cout << "combien d'animaux voulez-vous créer ? ";
    cin >> n;

    Animal** zoo = new Animal*[n];

    for (int i = 0; i < n; i++) {
        int choix;
        cout << "animal " << i + 1 << " (1 = Chien, 2 = Chat, 3 = Vache) : ";
        cin >> choix;

        if (choix == 1)
            zoo[i] = new Chien();
        else if (choix == 2)
            zoo[i] = new Chat();
        else
            zoo[i] = new Vache();
    }

    cout << "informations et cris des animaux :\n";
    for (int i = 0; i < n; i++) {
        zoo[i]->info();
        zoo[i]->crier();
    }

    for (int i = 0; i < n; i++)
        delete zoo[i];
    delete[] zoo;

    return 0;
}
