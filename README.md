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