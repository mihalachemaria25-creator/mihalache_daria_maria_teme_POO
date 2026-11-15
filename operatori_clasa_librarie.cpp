#include <iostream>
#include <string>
using namespace std;

enum Program { INCHISA = 0 ,   DESCHISA = 1 };

class Librarie {
private:
    const int id;
    Program program;
    string denumire;
    float chirie;
    int nrRafturi;
    float* vectorPreturi;

public:
    static int nrLibrarii;

    //constructor implicit implementare
    Librarie() :id(++nrLibrarii) {
        this->program = INCHISA;
        this->denumire = "necunoscuta";
        this->chirie = 0;
        this->nrRafturi = 0;
        this->vectorPreturi = nullptr;
    }

    //constructor cu parametrii
    Librarie(int id,Program program, string denumire,float chirie,  int nrRafturi, float* vectorPreturi) :id(id) {
        this->program = program; 
        this->denumire = denumire;
        this->chirie = chirie;
        this->nrRafturi = nrRafturi;
        this->vectorPreturi = new float[nrRafturi];
        for (int i = 0;i < this->nrRafturi;i++) {
            this->vectorPreturi[i] = vectorPreturi[i];
        }
        nrLibrarii++;
    }

    //constructor de copiere
    Librarie(const Librarie& c) :id(++nrLibrarii) {
        this->program = c.program;
        this->denumire = c.denumire;
        this->chirie = c.chirie;
        this->nrRafturi = c.nrRafturi;
        if (c.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[c.nrRafturi];
            for (int i = 0;i < c.nrRafturi;i++) {
                this->vectorPreturi[i] = c.vectorPreturi[i];
            }
        }
        else {
            this->vectorPreturi = nullptr;
        }
        


    }

    //operatorul = 
    void operator=(const Librarie& c)  {
        this->program = c.program;
        this->denumire = c.denumire;
        this->chirie = c.chirie;
        this->nrRafturi = c.nrRafturi;

        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
            this->vectorPreturi = nullptr;
        }

        if (c.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[c.nrRafturi];
            for (int i = 0;i < c.nrRafturi;i++) {
                this->vectorPreturi[i] = c.vectorPreturi[i];
            }
        }
        else {
            this->vectorPreturi = nullptr;
        }

    }



    void afisareLibrarii() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Libraria este ";
        if (this->program == 1) {
            cout << "deschisa! ";
        }
        else {
            cout << "inchisa!";
        }
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Chirie: " << this->chirie << " euro!";
        cout << endl << "Nr rafturi= " << this->nrRafturi;
        if (this->nrRafturi != 0) {
            cout << endl << "Preturile sunt ";
            for (int i = 0;i < this->nrRafturi;i++) {
                cout << this->vectorPreturi[i] << " , ";
            }
            cout << this->vectorPreturi[this->nrRafturi - 1] << ".";
        }
    }


    //get si set pentru nrRafturi

    int getNrRafturi() {
         return this->nrRafturi;
    }


    void setNrRafturi(int nrRafturiNou) {
        if (nrRafturiNou >= 0) {
            this->nrRafturi = nrRafturiNou;
        }
        else {
            throw "Valoare negativa! ";
        }

    }

    //get si set pentru vectorPreturi-pointer

    float* getVectorPreturi() {
        float* vectorPreturiNou = new float[this->nrRafturi];
        for (int i = 0; i < this->nrRafturi; i++)
        {
            vectorPreturiNou[i] = this->vectorPreturi[i];
        }
        return vectorPreturiNou;
    }

    void setVectorPreturi(float* vector, int nrR) {
        setNrRafturi(nrR);

        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }

        this->vectorPreturi = new float[this->nrRafturi];
        for (int i = 0; i < this->nrRafturi; i++)
        {
            this->vectorPreturi[i] = vector[i];
        }

        delete[] vector;

    }



    ~Librarie() {
        if (this->vectorPreturi != nullptr) {
            delete[]this->vectorPreturi;
        }
    }

//OPERATORI NOI
    bool operator<(const Librarie& c) {
        return this->nrRafturi < c.nrRafturi;
    }

    void operator+=(float chirieDeAdunat) {
        this->chirie += chirieDeAdunat;
    }

    //operatorul negatie
    bool operator!() {
        return this->chirie > 0;
    }

    //operatorul functie
    float operator()(float valoareDeAdaugat)
    {
        return this->chirie + valoareDeAdaugat;
    }

    //operatorul index
    float& operator[](int index) {
        if (index >= 0 && index < this->nrRafturi) {
            return this->vectorPreturi[index];
        }
        else {
            throw exception();
        }
    }


    //operator << / operator de afisare
    friend void operator<<(ostream& out, Librarie lib) {
        out << endl << "Operator de afisare: ";
        out << endl << "Id: " << lib.id;
        out << endl << "Libraria este : ";
        if (lib.program == INCHISA) out << "inchisa!";
        if (lib.program == DESCHISA) out << "deschisa!";
        out << endl << "Denumire: " << lib.denumire;
        out << endl << "Chirie: " << lib.chirie;
        out << endl << "Nr rafturi: " << lib.nrRafturi;
        if (lib.vectorPreturi != nullptr) {
            out << endl << "Vector preturi: ";
            for (int i = 0; i < lib.nrRafturi - 1; i++) {
                out << lib.vectorPreturi[i] << " lei, ";
            }
            out << lib.vectorPreturi[lib.nrRafturi - 1] << " lei.";
        }
    }

    friend void operator>>(istream& in, Librarie& lib);

    //postincrementare j = i++
    Librarie operator++(int) {
        Librarie copie = *this;
        this->chirie++;

        return copie;
    }

    //preincrementare j = ++i
    Librarie operator++() {
        this->chirie++;
        return *this;
    }

    //cast explicit
    explicit operator int() {
        return this->nrRafturi;
    }




};
int Librarie::nrLibrarii = 0;


void operator>>(istream& in, Librarie& lib) {
    cout << endl << "Chirie: ";
    in >> lib.chirie;

    cout << endl << "Denumire: ";
    in >> lib.denumire;

    cout << endl << "Libraria este ";
    int program;
    in >> program;

    if (program == 0) lib.program = INCHISA;
    if (program == 1) lib.program = DESCHISA;

    cout << endl << "Nr rafturi: ";
    in >> lib.nrRafturi;

    cout << endl << "Vector preturi: ";

    if (lib.vectorPreturi != nullptr) {
        delete[] lib.vectorPreturi;
        lib.vectorPreturi = nullptr;
    }

    lib.vectorPreturi = new float[lib.nrRafturi];
    for (int i = 0; i < lib.nrRafturi; i++) {
        cout << endl << "vectorPreturi[" << i << "]: ";
        in >> lib.vectorPreturi[i];
    }
}



int main() {
    Librarie cLuceafarul;
    cLuceafarul += 200;
    if (!cLuceafarul) {
        cout << endl << " Chirie nenula!";
    }
    else {
        cout << endl << "Chirie nula!";
    }
    cout << endl << "Apel operator functie: " << cLuceafarul(10);
    cout << cLuceafarul;

    Librarie Slavici = cLuceafarul++;
    cout << Slavici;
    cout << cLuceafarul;

    float* vectorPreturi = new float [4] {120, 130, 140, 150};
    Librarie* pEminescu = new Librarie(2, DESCHISA, "Eminescu",500, 4, vectorPreturi);
    pEminescu->afisareLibrarii();

    if (cLuceafarul < *pEminescu) {
        cout << endl << "Libraria Luceafarul are mai putine rafturi!";
    }
    else {
        cout << "Libraria Eminescu are mai putine rafturi!";
    }

    (*pEminescu)[0] = 30;
    cout << endl << "Apel operator index: " << (*pEminescu)[0];

   ;

    cout << endl << "Sunt " << Librarie::nrLibrarii << " librarii";
    cout << (int)(*pEminescu);
    delete pEminescu;
}
}
