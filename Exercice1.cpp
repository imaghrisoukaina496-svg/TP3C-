#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;

public:
    // 🔹 Constructeur par défaut
    CompteBancaire() {
        titulaire = "Inconnu";
        solde = 0.0;
        cout << "Constructeur par défaut appelé pour " << titulaire << endl;
    }

    // 🔹 Constructeur paramétré
    CompteBancaire(const string& nom, double montant) {
        titulaire = nom;
        solde = montant;
        cout << "Constructeur paramétré appelé pour " << titulaire << endl;
    }

    // 🔹 Constructeur de copie
    CompteBancaire(const CompteBancaire& autre) {
        titulaire = autre.titulaire;
        solde = autre.solde;
        cout << "Constructeur de copie appelé pour " << titulaire << endl;
    }

    // 🔹 Méthode pour afficher les infos du compte
    void afficher() const {
        cout << "Titulaire : " << titulaire << " | Solde : " << solde << " DH" << endl;
    }

    // 🔹 Destructeur
    ~CompteBancaire() {
        cout << "Destructeur appelé pour " << titulaire << endl;
    }
};

int main() {
    CompteBancaire compte1;                           // constructeur par défaut
    CompteBancaire compte2("Alice", 1500.0);          // constructeur paramétré
    CompteBancaire compte3 = compte2;                 // constructeur de copie

 
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    
    return 0;
}
