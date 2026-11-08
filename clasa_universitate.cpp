#include <iostream>
#include <string>

using namespace std;

enum TipUniversitate { 
    DE_STAT = 1, 
    PRIVATA = 2 
};

class Universitate {
private:
    const int id;
    string denumire;
    TipUniversitate tip;
    int nrFacultati;
    float* vectorBugete;

public:
    static int nrUniversitati;

    Universitate() : id(++nrUniversitati) {
        this->denumire = "Default";
        this->nrFacultati = 0;
        this->tip = DE_STAT;
        this->vectorBugete = nullptr;
    }

    Universitate(int id, string denumire, TipUniversitate tip, int nrFacultati, float* vectorBugete) 
        : id(id) {
        this->denumire = denumire;
        this->tip = tip;
        this->nrFacultati = nrFacultati;
        
        if (nrFacultati > 0 && vectorBugete != nullptr) {
            this->vectorBugete = new float[nrFacultati];
            for (int i = 0; i < this->nrFacultati; i++) {
                this->vectorBugete[i] = vectorBugete[i];
            }
        } else {
            this->vectorBugete = nullptr;
        }

        nrUniversitati++;
    }

    Universitate(const Universitate& u) : id(++nrUniversitati) {
        this->denumire = u.denumire;
        this->nrFacultati = u.nrFacultati;
        this->tip = u.tip;

        if (u.vectorBugete != nullptr) {
            this->vectorBugete = new float[u.nrFacultati];
            for (int i = 0; i < u.nrFacultati; i++) {
                this->vectorBugete[i] = u.vectorBugete[i];
            }
        } else {
            this->vectorBugete = nullptr;
        }
    }

    Universitate& operator=(const Universitate& u) {
        if (this == &u) {
            return *this;
        }

        this->denumire = u.denumire;
        this->nrFacultati = u.nrFacultati;
        this->tip = u.tip;

        if (this->vectorBugete != nullptr) {
            delete[] this->vectorBugete;
            this->vectorBugete = nullptr;
        }

        if (u.vectorBugete != nullptr) {
            this->vectorBugete = new float[u.nrFacultati];
            for (int i = 0; i < u.nrFacultati; i++) {
                this->vectorBugete[i] = u.vectorBugete[i];
            }
        }

        return *this;
    }

    void afisareUniversitate() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr facultati: " << this->nrFacultati;
        cout << endl << "Tip: ";
        if (this->tip == DE_STAT) {
            cout << "DE STAT";
        } else {
            cout << "PRIVATA";
        }

        if (this->nrFacultati > 0 && this->vectorBugete != nullptr) {
            cout << endl << "Bugete per facultate: ";
            for (int i = 0; i < this->nrFacultati - 1; i++) {
                cout << this->vectorBugete[i] << ", ";
            }
            cout << this->vectorBugete[this->nrFacultati - 1] << ".";
        }
        cout << endl;
    }

    int getNrFacultati() {
        return this->nrFacultati;
    }

    void setNrFacultati(int nrFacultatiNou) {
        if (nrFacultatiNou >= 0) {
            this->nrFacultati = nrFacultatiNou;
        } else {
            throw "Valoare negativa";
        }
    }

    float* getVectorBugete() {
        if (this->nrFacultati <= 0 || this->vectorBugete == nullptr) {
            return nullptr;
        }
        float* vectorBugeteNou = new float[this->nrFacultati];
        for (int i = 0; i < this->nrFacultati; i++) {
            vectorBugeteNou[i] = this->vectorBugete[i];
        }
        return vectorBugeteNou;
    }

    void setVectorBugete(float* vector, int nrF) {
        setNrFacultati(nrF);

        if (this->vectorBugete != nullptr) {
            delete[] this->vectorBugete;
        }

        if (nrF > 0 && vector != nullptr) {
            this->vectorBugete = new float[this->nrFacultati];
            for (int i = 0; i < this->nrFacultati; i++) {
                this->vectorBugete[i] = vector[i];
            }
        } else {
            this->vectorBugete = nullptr;
        }
    }

    bool operator<(const Universitate& u) {
        return this->nrFacultati < u.nrFacultati;
    }

    ~Universitate() {
        if (this->vectorBugete != nullptr) {
            delete[] this->vectorBugete;
        }
    }
};

int Universitate::nrUniversitati = 0;

int main() {
    Universitate uDefault;
    uDefault.afisareUniversitate();

    float* vectorBugete = new float[3] {1500.5f, 2300.0f, 1850.2f};
    Universitate* pUniv = new Universitate(10, "Politehnica", DE_STAT, 3, vectorBugete);
    delete[] vectorBugete;

    pUniv->afisareUniversitate();

    Universitate uCopie = *pUniv;
    uCopie.afisareUniversitate();

    uDefault = *pUniv;
    uDefault.afisareUniversitate();

    cout << endl << "Am construit " << Universitate::nrUniversitati << " universitati!";

    if (uDefault < uCopie) {
        cout << endl << "Prima universitate are mai putine facultati!";
    } else {
        cout << endl << "A doua universitate are mai putine facultati sau egal!";
    }

    delete pUniv;

    return 0;
}
