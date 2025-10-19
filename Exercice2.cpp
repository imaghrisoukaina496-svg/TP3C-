#include <iostream>
#include <iomanip>  // pour std::hex et std::setw
#include <cstring>  // pour memcpy
using namespace std;

class Buffer {
private:
    size_t size;           // Taille du buffer (en octets)
    unsigned char* data;   // Pointeur vers la mémoire allouée

public:
    // 🔹 Constructeur par défaut
    Buffer() : size(0), data(nullptr) {
        cout << "Constructeur par défaut : buffer vide" << endl;
    }

    // 🔹 Constructeur paramétré
    Buffer(size_t n) : size(n) {
        data = new unsigned char[n];  // allocation dynamique
        memset(data, 0, n);           // remplir avec des zéros
        cout << "Constructeur paramétré : buffer de " << size << " octet(s)" << endl;
    }

    // 🔹 Constructeur de copie (copie profonde)
    Buffer(const Buffer& other) : size(other.size) {
        if (other.data) {
            data = new unsigned char[size];
            memcpy(data, other.data, size);
            cout << "Constructeur de copie : duplication de " << size << " octet(s)" << endl;
        } else {
            data = nullptr;
            cout << "Constructeur de copie : buffer vide" << endl;
        }
    }

    //Opérateur d’affectation (règle des trois)
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            // Libérer l'ancien contenu
            delete[] data;

            size = other.size;
            if (other.data) {
                data = new unsigned char[size];
                memcpy(data, other.data, size);
                cout << "Opérateur d’affectation : copie de " << size << " octet(s)" << endl;
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    //Méthode pour obtenir la taille
    size_t getSize() const {
        return size;
    }

    //Remplir le buffer avec une valeur donnée
    void fill(unsigned char value) {
        if (data) {
            memset(data, value, size);
        }
    }

    // Afficher le contenu en hexadécimal
    void printHex() const {
        if (size == 0) {
            cout << "(buffer vide)" << endl;
            return;
        }

        cout << std::hex << std::uppercase << std::setfill('0');
        for (size_t i = 0; i < size; ++i) {
            cout << setw(2) << static_cast<int>(data[i]) << " ";
        }
        cout << std::dec << endl;
    }

    //Destructeur
    ~Buffer() {
        if (data) {
            cout << "🗑️ Destruction du buffer de " << size << " octet(s)" << endl;
            delete[] data;
        } else {
            cout << "🗑️ Destruction du buffer vide" << endl;
        }
    }
};

int main() {
    cout << "=== Début du programme ===" << endl;

    Buffer b1;                  // Constructeur par défaut
    Buffer b2(8);               // Constructeur paramétré
    b2.fill(0xAA);              // Remplir avec 0xAA

    Buffer b3 = b2;             // Constructeur de copie

    cout << "\n--- Affichage des buffers ---" << endl;
    cout << "b1 (" << b1.getSize() << " octet(s)) : "; b1.printHex();
    cout << "b2 (" << b2.getSize() << " octet(s)) : "; b2.printHex();
    cout << "b3 (" << b3.getSize() << " octet(s)) : "; b3.printHex();

    return 0;
}
