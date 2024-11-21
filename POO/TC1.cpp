#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Autobuz
{
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:

    Autobuz():idAutobuz(++nrAutobuze)
    {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen("") + 1];
        strcpy(this->producator, "");
    }

    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : Autobuz() {

        if (capacitate > 0) {
            this->capacitate = capacitate;
        }

        if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        if (producator) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
    }

    Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze) {
        capacitate = a.capacitate;
        nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        if (a.producator) {
            this->producator = new char[strlen(a.producator) + 1];
            strcpy(this->producator, a.producator);
        }
    }

    ~Autobuz() {
        delete[] producator;
    }

    friend ostream& operator<<(ostream& out, const Autobuz& a) {
        out << "idAutobuz: " << a.idAutobuz << "; ";
        out << "capacitate: " << a.capacitate << "; ";
        out << "nrPersoaneImbarcate: " << a.nrPersoaneImbarcate << "; ";
        out << "Producator: ";
        if (a.producator) {
            out << a.producator;
        }
        out << endl;

        return out;
    }

    int getCapacitate() {
        return capacitate;
    }

    void setCapacitate(int capacitate) {
        if (capacitate >= 0) {
            this->capacitate = capacitate;
        }
    }

    const char* getProducator() {
        return producator;
    }

    void setProducator(const char* producator) {
        delete[] this->producator;
        if (producator) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
    }

    Autobuz& operator=(const Autobuz& a) {
        if (this != &a) {
            capacitate = a.capacitate;
            nrPersoaneImbarcate = a.nrPersoaneImbarcate;
            delete[] producator;
            if (a.producator) {
                this->producator = new char[strlen(a.producator) + 1];
                strcpy(this->producator, a.producator);
            }
        }
        return *this;
    }

    int getNumarLocuriLibere() {
        return capacitate - nrPersoaneImbarcate;
    }

    operator int() {
        return nrPersoaneImbarcate;
    }

    bool operator>(const Autobuz& a) {
        return capacitate > a.capacitate;
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    Autobuz a1;
    cout << "Constructor fara parametri" << endl;
    cout << a1 << endl;


    Autobuz a2(63, 36, "Otokar");
    cout << "Constructor cu parametri" << endl;
    cout << a2 << endl;


    Autobuz a3 = a2;
    cout << "Constructor de copiere" << endl;
    cout << a3 << endl;


    cout << "Metode accesor" << endl;
    a3.setCapacitate(78);
    cout << "a3.getCapacitate(): " << a3.getCapacitate() << endl;
    a3.setProducator("MAN");
    cout << "a3.getProducator(): " << a3.getProducator() << endl;
    cout << endl;

    a1 = a3;
    cout << "Operatorul =" << endl;
    cout << a1 << endl;


    cout << "Metoda getNumarLocuriLibere()" << endl;
    cout << "a3.getNumarLocuriLibere(): " << a3.getNumarLocuriLibere() << endl;
    cout << endl;

    cout << "Operator int()" << endl;
    cout << "int(a3): " << int(a3) << endl;


    cout << endl << "Operator > " << endl;
    if (a3 > a2) {
        cout << "a3 > a2";
    }
    else {
        cout << "a2 > a3";
    }
    cout << endl;


    return 0;
}