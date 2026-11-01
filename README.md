#include <iostream>
#include <string>

using namespace std;

enum Categorie { 
    TREI_STELE = 3, 
    PATRU_STELE = 4, 
    CINCI_STELE = 5 
};

class Hotel {
private:
    const int id;
    string denumire;
    Categorie categorie;
    int nrCamere;
    float* vectorPreturi;

public:
    static int nrHoteluri;

    Hotel() : id(++nrHoteluri) {
        this->denumire = "Default";
        this->nrCamere = 0;
        this->categorie = TREI_STELE;
        this->vectorPreturi = nullptr;
    }

    Hotel(int id, string denumire, Categorie categorie, int nrCamere, float* vectorPreturi) 
        : id(id) {
        this->denumire = denumire;
        this->categorie = categorie;
        this->nrCamere = nrCamere;
        
        if (nrCamere > 0 && vectorPreturi != nullptr) {
            this->vectorPreturi = new float[nrCamere];
            for (int i = 0; i < this->nrCamere; i++) {
                this->vectorPreturi[i] = vectorPreturi[i];
            }
        } else {
            this->vectorPreturi = nullptr;
        }

        nrHoteluri++;
    }

    Hotel(const Hotel& h) : id(++nrHoteluri) {
        this->denumire = h.denumire;
        this->nrCamere = h.nrCamere;
        this->categorie = h.categorie;

        if (h.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[h.nrCamere];
            for (int i = 0; i < h.nrCamere; i++) {
                this->vectorPreturi[i] = h.vectorPreturi[i];
            }
        } else {
            this->vectorPreturi = nullptr;
        }
    }

    Hotel& operator=(const Hotel& h) {
        if (this == &h) {
            return *this;
        }

        this->denumire = h.denumire;
        this->nrCamere = h.nrCamere;
        this->categorie = h.categorie;

        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
            this->vectorPreturi = nullptr;
        }

        if (h.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[h.nrCamere];
            for (int i = 0; i < h.nrCamere; i++) {
                this->vectorPreturi[i] = h.vectorPreturi[i];
            }
        }

        return *this;
    }

    void afisareHotel() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr camere: " << this->nrCamere;
        cout << endl << "Categorie: ";
        if (this->categorie == TREI_STELE) {
            cout << "TREI STELE";
        } else if (this->categorie == PATRU_STELE) {
            cout << "PATRU STELE";
        } else {
            cout << "CINCI STELE";
        }

        if (this->nrCamere > 0 && this->vectorPreturi != nullptr) {
            cout << endl << "Preturi per camera: ";
            for (int i = 0; i < this->nrCamere - 1; i++) {
                cout << this->vectorPreturi[i] << ", ";
            }
            cout << this->vectorPreturi[this->nrCamere - 1] << ".";
        }
        cout << endl;
    }

    int getNrCamere() {
        return this->nrCamere;
    }

    void setNrCamere(int nrCamereNou) {
        if (nrCamereNou >= 0) {
            this->nrCamere = nrCamereNou;
        } else {
            throw "Valoare negativa";
        }
    }

    float* getVectorPreturi() {
        if (this->nrCamere <= 0 || this->vectorPreturi == nullptr) {
            return nullptr;
        }
        float* vectorPreturiNou = new float[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            vectorPreturiNou[i] = this->vectorPreturi[i];
        }
        return vectorPreturiNou;
    }

    void setVectorPreturi(float* vector, int nrC) {
        setNrCamere(nrC);

        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }

        if (nrC > 0 && vector != nullptr) {
            this->vectorPreturi = new float[this->nrCamere];
            for (int i = 0; i < this->nrCamere; i++) {
                this->vectorPreturi[i] = vector[i];
            }
        } else {
            this->vectorPreturi = nullptr;
        }
    }

    bool operator<(const Hotel& h) {
        return this->nrCamere < h.nrCamere;
    }

    ~Hotel() {
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }
    }
};

int Hotel::nrHoteluri = 0;

int main() {
    Hotel hDefault;
    hDefault.afisareHotel();

    float* vectorPreturi = new float[3] {350, 270, 410};
    Hotel* pHotel = new Hotel(7, "Continental", PATRU_STELE, 3, vectorPreturi);
    delete[] vectorPreturi;

    pHotel->afisareHotel();

    Hotel hCopie = *pHotel;
    hCopie.afisareHotel();

    hDefault = *pHotel;
    hDefault.afisareHotel();

    cout << endl << "Am construit " << Hotel::nrHoteluri << " hoteluri!";

    if (hDefault < hCopie) {
        cout << endl << "Hotelul default are mai putine camere decat celalalt!";
    } else {
        cout << endl << "Hotelul copie are mai putine camere sau egal!";
    }

    delete pHotel;

    return 0;
}
# mihalache_daria_maria_teme_POO
Să se definească o clasă Hotel care să conțină un identificator constant, denumirea hotelului, numărul de camere și un vector alocat dinamic pentru prețurile camerelor.
#include <iostream>
#include <string>

using namespace std;

class Hotel {
private:
    const int id;
    string denumire;
    int nrCamere;
    float* vectorPreturi;

public:
    static int nrHoteluri;

    Hotel() : id(++nrHoteluri) {
        //id = 0;
        //denumire = "Default";
        this->denumire = "Default";
        this->nrCamere = 0;
        this->vectorPreturi = nullptr;
    }

    Hotel(int id, string denumire, int nrCamere,
        float* vectorPreturi)
        : id(id) {
        this->denumire = denumire;
        this->nrCamere = nrCamere;
        this->vectorPreturi = new float[nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i] = vectorPreturi[i];
        }

        nrHoteluri++;
    }

    void afisareHotel() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr camere: " << this->nrCamere;

        if (this->nrCamere > 0) {
            cout << endl << "Preturi per camera: ";

            for (int i = 0; i < this->nrCamere - 1; i++) {
                cout << this->vectorPreturi[i] << ", ";
            }

            cout << this->vectorPreturi[this->nrCamere - 1] << ".";
        }
    }

    ~Hotel() {
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }
    }
};

int Hotel::nrHoteluri = 0;

void main() {
    Hotel h1;
    h1.afisareHotel();

    float* vectorPreturi = new float[3] {200, 300, 450};

    Hotel* pHotel = new Hotel(7, "Continental", 3, vectorPreturi);

    pHotel->afisareHotel();

    delete pHotel;
    delete[] vectorPreturi;

    cout << endl << "Am construit "
        << Hotel::nrHoteluri << " hoteluri!";
}




#include<iostream>
#include<string>

using namespace std;

class Hotel {
private:
    const int id;
    string denumire;
    int nrCamere;
    float* vectorPreturi;

public:
    static int nrHoteluri;

    Hotel() : id(++nrHoteluri) {
        //id = 0;
        //denumire = "Default";
        this->denumire = "Default";
        this->nrCamere = 0;
        this->vectorPreturi = nullptr;
    }

    Hotel(int id, string denumire, int nrCamere,
        float* vectorPreturi)
        : id(id) {
        this->denumire = denumire;
        this->nrCamere = nrCamere;
        this->vectorPreturi = new float[nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i] = vectorPreturi[i];
        }

        nrHoteluri++;
    }

    void afisareHotel() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr camere: " << this->nrCamere;

        if (this->nrCamere > 0) {
            cout << endl << "Preturi per camera: ";

            for (int i = 0; i < this->nrCamere - 1; i++) {
                cout << this->vectorPreturi[i] << ", ";
            }

            cout << this->vectorPreturi[this->nrCamere - 1] << ".";
        }
    }

    // get si set pentru nrCamere
    int getNrCamere() {
        return this->nrCamere;
    }

    void setNrCamere(int nrCamereNou) {
        if (nrCamereNou >= 0) {
            this->nrCamere = nrCamereNou;
        }
        else {
            //throw exception();
            //throw 404;
            throw "Valoare negativa";
        }
    }

    // get si set pentru vectorPreturi (pointer)
    float* getVectorPreturi() {
        float* vectorPreturiNou = new float[this->nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            vectorPreturiNou[i] = this->vectorPreturi[i];
        }

        return vectorPreturiNou;
    }

    void setVectorPreturi(float* vector, int nrC) {
        setNrCamere(nrC);

        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }

        this->vectorPreturi = new float[this->nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i] = vector[i];
        }

        delete[] vector;
    }

    ~Hotel() {
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }
    }
};

int Hotel::nrHoteluri = 0;

int main() {
    Hotel h1;
    h1.afisareHotel();

    try {
        h1.setNrCamere(2);
    }
    catch (int cod) {
        cout << endl << cod;
    }
    catch (const char* mesaj) {
        cout << endl << mesaj;
    }
    catch (...) {
        cout << endl << "Nr camere negativ!";
    }

    cout << endl << "Noul numar de camere este: "
        << h1.getNrCamere();

    h1.setVectorPreturi(new float[3] {200, 300, 450}, 3);
    float* vector = h1.getVectorPreturi();

    cout << endl << "Noile preturi sunt: ";

    for (int i = 0; i < 3; i++) {
        cout << vector[i] << " lei, ";
    }

    h1.afisareHotel();

    delete[] vector;

    float* vectorPreturi = new float[3] {350, 270, 410};
    Hotel* pHotel = new Hotel(7, "Continental", 3, vectorPreturi);

    delete[] vectorPreturi;

    pHotel->afisareHotel();

    delete pHotel;

    cout << endl << "Am construit "
        << Hotel::nrHoteluri << " hoteluri!";

    return 0;
}
