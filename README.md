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
