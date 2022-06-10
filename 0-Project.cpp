#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
//fac in cabinet Animal A* unde retin animalul cu tot cu info
// faca functionalitea in meniu
class Animal
{
private:
    char initialaNume;
    bool Vaccin;
    string LunaVaccin;
    int* VizitemedicaleinultimeleNluni;
    int nLuni;
    double Greutate;
    float Inaltime;
    long Varsta;
    string Categorie;
    string CnpStapan;
    const int idAnimal;
    static int contorIdAnimal;

public:
    Animal();
    Animal(bool Vaccin, string LunaVaccin);
    Animal(bool Vaccin, string LunaVaccin,int* VizitemedicaleinultimeleNluni,int nLuni);
    Animal(bool Vaccin, string LunaVaccin,int* VizitemedicaleinultimeleNluni,int nLuni,double Greutate, long Varsta,string Categorie,char initialaNume, string CnpStapan );


    friend istream& operator>>(istream& in, Animal& anim);
    friend ostream& operator<<(ostream& out, const Animal& anim );
    Animal(const Animal& anim);
    Animal& operator=(const Animal& anim);

    const Animal& operator++();
    Animal operator++(int);
    Animal operator+=(double x);
    Animal operator+(Animal anim);

    friend Animal operator+(double x, Animal anim);
    friend Animal operator+(Animal anim, double x);

    int ultimaDataCandaFostVerificat(Animal anim);

    const Animal& operator--();
    Animal operator--(int);
    Animal operator-=(double x);
    Animal operator-(Animal anim);

    friend Animal operator-(double x, Animal anim);
    friend Animal operator-(Animal anim, double x);

    bool operator==(const Animal& anim);
    bool operator<(const Animal& anim);

    explicit operator int();


    int operator[](int index);

    string getCnpStapan();
    bool getVaccin();
    char  getinitialaNume();
    string getLunaVaccin();
    const int* getVizitemedicaleinultimeleNluni();
    int getnLuni();
    double getGreutate();
    float getInaltime();
    long getVarsta();
    string getCategorie();
    static int getcontorAnimal();

    int getidAnimal();

    void setCnpStapan( string CnpStapan);
    void setinitialaNume(char initialaNume);
    void setVaccin(bool Vaccin);
    void setLunaVaccin(string LunaVaccin);
    void setVizitemedicaleinultimeleNluni(int* VizitemedicaleinultimeleNluni, int n);
    void setnLuni(int nLuni);
    void setGreutate(double Greutate);
    void setInaltime(float Inaltime);
    void setVarsta(long Varsta);
    void setCategorie(string Categorie);
    ~Animal();

};
int Animal::getidAnimal()
{
    return this->idAnimal;
}
int Animal::contorIdAnimal=1;

int Animal::getcontorAnimal()
{
    return Animal::contorIdAnimal;
}

Animal::operator int()
{
    return (int)this->Greutate;
}

int Animal::operator[](int index)
{
    if(index>=0 && index<this->nLuni)
        return this->VizitemedicaleinultimeleNluni[index];
    return -1;
}
bool Animal::operator==(const Animal& anim)
{
    if(this->Categorie==anim.Categorie && this->CnpStapan==anim.CnpStapan)
        return true;
    return false;
}
bool Animal::operator<(const Animal& anim)
{

    if (  this->Varsta<anim.Varsta)
        return true;
    return false;

}

int Animal::ultimaDataCandaFostVerificat(Animal anim)
{
    int data=0;
    for(int i=0; i<anim.nLuni; i++)
        if(anim.VizitemedicaleinultimeleNluni[i]!=0)
            data=VizitemedicaleinultimeleNluni[i];
    if(data)
        return data;
    else return -1;
}

const Animal& Animal::operator++()
{
    this->Greutate++;
    return *this;
}

Animal  Animal::operator++(int)
{
    Animal aux(*this);
    this->Greutate++;
    return aux;
}
Animal  Animal::operator+=(double x)
{
    this->Greutate += x;
    return *this;
}
Animal  Animal::operator+(Animal anim)
{
    anim.Greutate=anim.Greutate+this->Greutate;
    return anim;
}
Animal operator+(double x, Animal anim)
{
    anim.Greutate=anim.Greutate+x;
    return anim;

}
Animal operator+(Animal anim, double x)
{
    anim.Greutate=anim.Greutate+x;
    return anim;
}
///////////////////
const Animal& Animal::operator--()
{
    this->Greutate--;
    return *this;
}

Animal  Animal::operator--(int)
{
    Animal aux(*this);
    this->Greutate--;
    return aux;
}
Animal  Animal::operator-=(double x)
{
    this->Greutate -= x;
    return *this;
}
Animal  Animal::operator-(Animal anim)
{
    anim.Greutate=anim.Greutate-this->Greutate;
    return anim;
}
Animal operator-(double x, Animal anim)
{
    anim.Greutate=x-anim.Greutate;
    return anim;

}
Animal operator-(Animal anim, double x)
{
    anim.Greutate=anim.Greutate-x;
    return anim;
}

Animal::Animal():idAnimal(contorIdAnimal++)
{
    this->Vaccin=false;
    this->LunaVaccin="Expirat";
    this->VizitemedicaleinultimeleNluni=NULL;
    this->nLuni=0;
    this->Greutate=0.00;
    this->Inaltime=0.00;
    this->Varsta=0;
    this->Categorie="None";
    this->initialaNume='x';
    this->CnpStapan="None";
}
Animal::Animal(bool Vaccin, string LunaVaccin):idAnimal(contorIdAnimal++)
{
    this->Vaccin=Vaccin;
    this->LunaVaccin=LunaVaccin;
    this->VizitemedicaleinultimeleNluni=NULL;
    this->nLuni=0;
    this->Greutate=0.00;
    this->Inaltime=0.00;
    this->Varsta=0;
    this->Categorie="None";
    this->initialaNume='x';
    this->CnpStapan="None";

}
Animal::Animal(bool Vaccin, string LunaVaccin,int* VizitemedicaleinultimeleNluni,int nLuni):idAnimal(contorIdAnimal++)
{
    this->Vaccin=Vaccin;
    this->LunaVaccin=LunaVaccin;
    this->nLuni=nLuni;
    this->VizitemedicaleinultimeleNluni=new int[nLuni];
    for(int i=0; i<nLuni; i++)
        this->VizitemedicaleinultimeleNluni[i]=0;

    for(int i=0; i<nLuni; i++)
        this->VizitemedicaleinultimeleNluni[i]=VizitemedicaleinultimeleNluni[i];
    this->Inaltime=0.00;
    this->Varsta=0;
    this->Categorie="None";
    this->initialaNume='x';
    this->CnpStapan="None";
}

Animal::Animal(bool Vaccin, string LunaVaccin,int* VizitemedicaleinultimeleNluni,
               int nLuni,double Greutate, long Varsta,string Categorie,char initialaNume, string CnpStapan):idAnimal(contorIdAnimal++)
{
    this->Vaccin=Vaccin;
    this->LunaVaccin=LunaVaccin;
    this->nLuni=nLuni;
    this->VizitemedicaleinultimeleNluni=new int[nLuni];
    for(int i=0; i<nLuni; i++)
        this->VizitemedicaleinultimeleNluni[i]=0;

    for(int i=0; i<nLuni; i++)
        this->VizitemedicaleinultimeleNluni[i]=VizitemedicaleinultimeleNluni[i];
    this->Greutate=Greutate;
    this->Varsta=Varsta;
    this->Categorie=Categorie;
    this->initialaNume=initialaNume;
    this->CnpStapan=CnpStapan;
}
string Animal::getCnpStapan()
{
    return CnpStapan;

}
void Animal::setCnpStapan( string CnpStapan)
{
    this->CnpStapan=CnpStapan;
}
char Animal::getinitialaNume()
{
    return initialaNume;
}
void Animal::setinitialaNume(char initialaNume)
{
    this->initialaNume=initialaNume;
}
string Animal::getCategorie()
{
    return Categorie;
}
void Animal::setCategorie(string Categorie)
{
    this->Categorie=Categorie;
}
bool Animal::getVaccin()
{
    return Vaccin;
}
void Animal::setVaccin(bool Vaccin)
{
    this->Vaccin=Vaccin;
}
string Animal::getLunaVaccin()
{
    return LunaVaccin;
}
void Animal::setLunaVaccin(string LunaVaccin)
{
    this->LunaVaccin=LunaVaccin;
}
const int* Animal::getVizitemedicaleinultimeleNluni()
{
    return this->VizitemedicaleinultimeleNluni;
}


void Animal::setVizitemedicaleinultimeleNluni(int* VizitemedicaleinultimeleNluni,int n)
{
    if(this->VizitemedicaleinultimeleNluni!=NULL)
        delete [] this->VizitemedicaleinultimeleNluni;

    this->nLuni=n;
    this->VizitemedicaleinultimeleNluni=new int[n];
    for(int i=0; i<n; i++)
        this->VizitemedicaleinultimeleNluni[i]=0;

    for(int i=0; i<n; i++)
        this->VizitemedicaleinultimeleNluni[i]=VizitemedicaleinultimeleNluni[i];

}
int Animal::getnLuni()
{
    return nLuni;
}
void Animal::setnLuni(int nLuni)
{
    this->nLuni=nLuni;
}
double Animal::getGreutate()
{
    return Greutate;
}
void Animal::setGreutate(double Greutate)
{
    this->Greutate=Greutate;
}

float Animal::getInaltime()
{
    return Inaltime;
}
void Animal::setInaltime(float Inaltime)
{
    this->Inaltime=Inaltime;
}
long Animal::getVarsta()
{
    return Varsta;
}
void Animal::setVarsta(long Varsta)
{
    this->Varsta=Varsta;
}

Animal& Animal::operator=(const Animal& anim)
{
    if(this!=&anim)
    {
        if(this->VizitemedicaleinultimeleNluni!=NULL)
            delete [] this->VizitemedicaleinultimeleNluni;

        this->Vaccin=anim.Vaccin;
        this->LunaVaccin=anim.LunaVaccin;
        this->nLuni=anim.nLuni;
        this->VizitemedicaleinultimeleNluni=new int[anim.nLuni];
        for(int i=0; i<anim.nLuni; i++)
            this->VizitemedicaleinultimeleNluni[i]=anim.VizitemedicaleinultimeleNluni[i];
        this->Greutate=anim.Greutate;
        this->Inaltime=anim.Inaltime;
        this->Varsta=anim.Varsta;
        this->Categorie=anim.Categorie;
        this->initialaNume=anim.initialaNume;
        this->CnpStapan=anim.CnpStapan;
    }

    return *this;
}
Animal::Animal(const Animal& anim):idAnimal(contorIdAnimal)
{


    this->Vaccin=anim.Vaccin;
    this->LunaVaccin=anim.LunaVaccin;
    this->nLuni=anim.nLuni;
    this->VizitemedicaleinultimeleNluni=new int[anim.nLuni];

    for(int i=0; i<anim.nLuni; i++)
        this->VizitemedicaleinultimeleNluni[i]=anim.VizitemedicaleinultimeleNluni[i];
    this->Inaltime=anim.Inaltime;
    this->Greutate=anim.Greutate;
    this->Varsta=anim.Varsta;
    this->Categorie=anim.Categorie;
    this->initialaNume=anim.initialaNume;
    this->CnpStapan=anim.CnpStapan;
}
Animal::~Animal()
{
    if(this->VizitemedicaleinultimeleNluni!=NULL)
        delete [] this->VizitemedicaleinultimeleNluni;
}

istream& operator>>(istream& in, Animal& anim)
{
    cout<<"Introduceti 1 daca animalul este vaccinat, respectiv 0 daca animalul nu este "<<endl;
    in>>anim.Vaccin;


    cout<<"Luna in care a fost vaccinat ultima data:  " ;
    in>>anim.LunaVaccin;
    cout<<"Ultimele vizite medicale:\n" ;
    in>>anim.nLuni;
    if(anim.VizitemedicaleinultimeleNluni!=NULL)
        delete [] anim.VizitemedicaleinultimeleNluni;
    anim.VizitemedicaleinultimeleNluni=new int [anim.nLuni];

    for(int i=0; i<anim.nLuni; i++)
    {
        in>>anim.VizitemedicaleinultimeleNluni[i];
        cout<<"In luna "<<anim.VizitemedicaleinultimeleNluni[i]<<" a fost verificat"<<endl;
    }
    cout<<endl;
    cout<<"Greutatea este: ";
    in>>anim.Greutate;

    cout<<"Inaltimea este: ";
    in>>anim.Inaltime;


    cout<<"Varsta este: ";
    in>>anim.Varsta;


    cout<<"Categoria de animal: ";
    in>>anim.Categorie;
    cout<<"Initiala nume: ";
    in>>anim.initialaNume;
    cout<<"Cnp stapan: ";
    in>>anim.CnpStapan;
    return in;
}
ostream& operator<<(ostream& out, const Animal& anim )
{
    // out<<"Id-ul este: "<<anim.idAnimal<<endl;
    if(anim.Vaccin)
        out<<"Animalul este vaccinat "<<anim.Vaccin<<endl;
    else out<<"Animalul nu este vaccinat "<<anim.Vaccin<<endl;

    out<<"Luna in care a fost vaccinat ultima data: "<<anim.LunaVaccin<<endl;
    if(anim.nLuni>0)
    {
        out<<"Ultimele "<<anim.nLuni<<" vizite medicale"<<endl;
        for(int i=0; i<anim.nLuni; i++)
            out <<"In luna "<<anim.VizitemedicaleinultimeleNluni[i]<<" a fost verificat"<<endl;
    }
    else out<<" Animalul nu a fost la verificat!\n";

    out<<"Greutatea este: "<<anim.Greutate<<endl;
    out<<"Inaltimea este: "<<anim.Inaltime<<endl;

    out<<"Varsta este: "<<anim.Varsta<<endl;

    out<<"Categoria de animal: "<<anim.Categorie<<endl;
    out<<"Initiala nume: "<<anim.initialaNume<<endl<<"Cnp stapan: "<<anim.CnpStapan;;
    return out;


}


class Factura
{
private:
    string Numar_factura;
    char *Data_factura_emisa;
    string Beneficiar;
    string Nume_interventie;
    int ultimeleNluniBilantLunar;
    float* BilantLunarinultimeleNluni;
    float CostInterventie;
    float TVA;
public:
    Factura();
    Factura(string Numar_factura);
    Factura(string Numar_factura, char *Data_factura_emisa);
    Factura(string Numar_factura, char *Data_factura_emisa, string Beneficiar, string Nume_interventie,
            float CostInterventie, float* BilantLunarinultimeleNluni,int ultimeleNluniBilantLunar,float TVA  );

    Factura(const Factura& fact);
    Factura operator=(const Factura& fact);
    friend istream& operator>>(istream& in, Factura& fact);
    friend ostream& operator<<(ostream& out, const Factura& fact );

    const Factura& operator++();
    Factura operator++(int);
    Factura operator+=(float x);
    Factura operator+(Factura fact);
    friend Factura operator+(float x, Factura fact);
    friend Factura operator+(Factura fact, float x);

    const Factura& operator--();
    Factura operator--(int);
    Factura operator-=(float x);
    Factura operator-(Factura fact);
    friend Factura operator-(float x, Factura fact);
    friend Factura operator-(Factura fact, float x);

    explicit operator int();

    float operator[](int index);


    bool operator==(const Factura& fact);
    bool operator<(const Factura& fact);



    string getNumar_factura();
    const char* getData_factura_emisa();
    string getBeneficiar();
    string getNume_interventie();
    int getultimeleNluniBilantLunar();
    const float* getBilantLunarinultimeleNluni();
    float getCostInterventie();
    float getTVA();

    float ProfitUltimeleNLuni(Factura fact);

    void setNumar_factura(string Numar_factura);
    void setData_factura_emisa(char* DataNoua);
    void setBeneficiar(string Beneficiar);
    void setNume_interventie(string Nume_interventie);
    void setultimeleNluniBilantLunar(int ultimeleNluniBilantLunar);
    void setBilantLunarinultimeleNluni(float *bl,int n);
    void setCostInterventie(float CostInterventie);
    void setTVA(float TVA);
    ~Factura();

};
Factura:: operator int()
{
    return (int)this->CostInterventie;
}

float Factura::operator[](int index)
{
    if(index>=0 && index<this->ultimeleNluniBilantLunar)
        return this->BilantLunarinultimeleNluni[index];
    return -1;
}
float Factura:: ProfitUltimeleNLuni(Factura fact)
{
    float suma=0;
    for(int i=0; i<fact.ultimeleNluniBilantLunar; i++)
        suma+=fact.BilantLunarinultimeleNluni[i];
    suma=(suma*(100-fact.TVA))/100;
    return suma;
}

bool Factura::operator==(const Factura& fact)
{
    if(this->Numar_factura==fact.Numar_factura)
        return true;
    return false;
}
bool Factura::operator<(const Factura& fact)
{
    if(this->CostInterventie<fact.CostInterventie)
        return true;
    return false;
}
const Factura& Factura::operator++()
{
    this->TVA++;
    return *this;

}

Factura Factura::operator++(int)
{
    Factura aux(*this);
    this->TVA++;
    return aux;
}
Factura Factura::operator+=(float x)
{
    this->CostInterventie+=x;
    return *this;
}
Factura Factura::operator+(Factura fact)
{
    fact.CostInterventie=fact.CostInterventie+this->CostInterventie;
    return fact;
}
Factura operator+(float x, Factura fact)
{
    fact.CostInterventie=x+fact.CostInterventie;
    return fact;

}
Factura operator+(Factura fact, float x)
{
    fact.CostInterventie=fact.CostInterventie+x;
    return fact;

}
////////////////
const Factura& Factura::operator--()
{
    this->TVA--;
    return *this;

}

Factura Factura::operator--(int)
{
    Factura aux(*this);
    this->TVA--;
    return aux;
}
Factura Factura::operator-=(float x)
{
    this->CostInterventie-=x;
    return *this;
}
Factura Factura::operator-(Factura fact)
{
    fact.CostInterventie=fact.CostInterventie-this->CostInterventie;
    return fact;
}
Factura operator-(float x, Factura fact)
{
    fact.CostInterventie=x-fact.CostInterventie;
    return fact;

}
Factura operator-(Factura fact, float x)
{
    fact.CostInterventie=fact.CostInterventie-x;
    return fact;

}
Factura::Factura(string Numar_factura)
{
    this->Numar_factura=Numar_factura;
    this->Data_factura_emisa=NULL;
    this->Beneficiar="None";
    this->Nume_interventie="None";
    this->BilantLunarinultimeleNluni=NULL;
    this->ultimeleNluniBilantLunar=0;
    this->CostInterventie=0.0;
    this->TVA=0.0;
}
Factura::Factura(string Numar_factura, char *Data_factura_emisa)
{
    this->Numar_factura=Numar_factura;
    this->Data_factura_emisa=new char[strlen(Data_factura_emisa)+1];
    for(int i=0; i<strlen(Data_factura_emisa)+1; i++)
        this->Data_factura_emisa[i]=Data_factura_emisa[i];
    this->Beneficiar="None";
    this->Nume_interventie="None";
    this->BilantLunarinultimeleNluni=NULL;
    this->ultimeleNluniBilantLunar=0;
    this->CostInterventie=0.0;
    this->TVA=0.0;
}
Factura::Factura()
{
    this->Numar_factura="None";
    this->Data_factura_emisa=NULL;
    this->Beneficiar="None";
    this->Nume_interventie="None";
    this->BilantLunarinultimeleNluni=NULL;
    this->ultimeleNluniBilantLunar=0;
    this->CostInterventie=0.0;
    this->TVA=0.0;
}
Factura::Factura(string Numar_factura, char *Data_factura_emisa, string Beneficiar, string Nume_interventie,
                 float CostInterventie, float* BilantLunarinultimeleNluni,int ultimeleNluniBilantLunar, float TVA    )
{
    this->Numar_factura=Numar_factura;
    this->Data_factura_emisa=new char[strlen(Data_factura_emisa)+1];
    for(int i=0; i<strlen(Data_factura_emisa)+1; i++)
        this->Data_factura_emisa[i]=Data_factura_emisa[i];
    this->Beneficiar=Beneficiar;
    this->Nume_interventie=Nume_interventie;
    this->CostInterventie=CostInterventie;

    this->ultimeleNluniBilantLunar=ultimeleNluniBilantLunar;
    this->BilantLunarinultimeleNluni=new float[ultimeleNluniBilantLunar];

    for(int i=0; i<ultimeleNluniBilantLunar; i++)
        this->BilantLunarinultimeleNluni[i]=BilantLunarinultimeleNluni[i];
    this->TVA=TVA;
}
Factura::Factura(const Factura& fact)
{


    this->Numar_factura=fact.Numar_factura;
    this->Data_factura_emisa=new char[strlen(fact.Data_factura_emisa)+1];
    for(int i=0; i<strlen(fact.Data_factura_emisa)+1; i++)
        this->Data_factura_emisa[i]=fact.Data_factura_emisa[i];

    this->Beneficiar=fact.Beneficiar;
    this->Nume_interventie=fact.Nume_interventie;
    this->CostInterventie=fact.CostInterventie;
    this->ultimeleNluniBilantLunar=fact.ultimeleNluniBilantLunar;


    this->BilantLunarinultimeleNluni= new float[fact.ultimeleNluniBilantLunar];
    for(int i=0; i<fact.ultimeleNluniBilantLunar; i++)
        this->BilantLunarinultimeleNluni[i]=fact.BilantLunarinultimeleNluni[i];
    this->TVA=fact.TVA;

}

Factura Factura::operator=(const Factura& fact)
{
    if(this!=&fact)
    {
        if(this->Data_factura_emisa!=NULL)
            delete [] this->Data_factura_emisa;

        this->Numar_factura=fact.Numar_factura;
        this->Data_factura_emisa=new char[strlen(fact.Data_factura_emisa)+1];
        for(int i=0; i<strlen(fact.Data_factura_emisa)+1; i++)
            this->Data_factura_emisa[i]=fact.Data_factura_emisa[i];

        this->Beneficiar=fact.Beneficiar;
        this->Nume_interventie=fact.Nume_interventie;
        this->CostInterventie=fact.CostInterventie;
        this->ultimeleNluniBilantLunar=fact.ultimeleNluniBilantLunar;
        if(this->BilantLunarinultimeleNluni!=NULL)
            delete [] this->BilantLunarinultimeleNluni;

        this->BilantLunarinultimeleNluni= new float[fact.ultimeleNluniBilantLunar];
        for(int i=0; i<fact.ultimeleNluniBilantLunar; i++)
            this->BilantLunarinultimeleNluni[i]=fact.BilantLunarinultimeleNluni[i];

        this->TVA=fact.TVA;
    }
    return *this;
}
float Factura::getTVA()
{
    return TVA;
}
void Factura::setTVA(float TVA)
{
    this->TVA=TVA;
}

string Factura::getNumar_factura()
{
    return Numar_factura;
}
void  Factura::setNumar_factura(string Numar_factura)
{
    this->Numar_factura=Numar_factura;
}

const char* Factura::getData_factura_emisa()
{
    return this->Data_factura_emisa;
}
void Factura::setData_factura_emisa(char* DataNoua)
{
    if(this->Data_factura_emisa!=NULL)
        delete [] this->Data_factura_emisa;

    this->Data_factura_emisa=new char[strlen(DataNoua)+1];
    strcpy(this->Data_factura_emisa,DataNoua);
}

string Factura::getBeneficiar()
{
    return Beneficiar;
}
void Factura::setBeneficiar(string Beneficiar)
{
    this->Beneficiar=Beneficiar;
}

string Factura::getNume_interventie()
{
    return Nume_interventie;
}
void Factura::setNume_interventie(string Nume_interventie)
{
    this->Nume_interventie=Nume_interventie;
}
const float* Factura::getBilantLunarinultimeleNluni()
{
    return this->BilantLunarinultimeleNluni;
}
void Factura::setBilantLunarinultimeleNluni(float *bl,int n)
{
    this->ultimeleNluniBilantLunar=n;
    if(this->BilantLunarinultimeleNluni!=NULL)
        delete [] this->BilantLunarinultimeleNluni;
    this->BilantLunarinultimeleNluni=new float [n];
    for(int i=0; i<n; i++)
        this->BilantLunarinultimeleNluni[i]=BilantLunarinultimeleNluni[i];
}
int Factura::getultimeleNluniBilantLunar()
{
    return ultimeleNluniBilantLunar;
}
void Factura::setultimeleNluniBilantLunar(int ultimeleNluniBilantLunar)
{
    this->ultimeleNluniBilantLunar=ultimeleNluniBilantLunar;
}
float Factura::getCostInterventie()
{
    return CostInterventie;
}

void Factura::setCostInterventie(float CostInterventie)
{
    this->CostInterventie=CostInterventie;
}

Factura::~Factura()
{
    if(this->Data_factura_emisa!=NULL)
        delete [] this->Data_factura_emisa;
    if(this->BilantLunarinultimeleNluni!=NULL)
        delete [] this->BilantLunarinultimeleNluni;
}
istream& operator>>(istream& in, Factura& fact)
{
    cout<<"Numarul facturei este: ";
    in>>fact.Numar_factura;
    cout<<"Data pentru factura: ";
    char s[20];
    in>>s;

    if(fact.Data_factura_emisa!=NULL)
        delete [] fact.Data_factura_emisa;
    fact.Data_factura_emisa=new char [strlen(s)+1];
    strcpy(fact.Data_factura_emisa,s);

    cout<<"Numele beneficiarului este: ";
    in>>fact.Beneficiar;
    cout<<"Numele interventiei: ";
    in>>fact.Nume_interventie;

    cout<<"Bilantul pe ultimele n luni: ";
    in>>fact.ultimeleNluniBilantLunar;
    if(fact.BilantLunarinultimeleNluni!=NULL)
        delete [] fact.BilantLunarinultimeleNluni;
    fact.BilantLunarinultimeleNluni=new float[fact.ultimeleNluniBilantLunar];
    for(int i=0; i<fact.ultimeleNluniBilantLunar; i++)
    {
        in>>fact.BilantLunarinultimeleNluni[i];
        cout<<"Pentru luna "<< i+1<< " am castigat "<<fact.BilantLunarinultimeleNluni[i]<<endl;

    }
    cout<<"Costul pentru interventie este: ";
    in>>fact.CostInterventie;
    cout<<"TVA-ul este: ";
    in>>fact.TVA;

    return in;
}
ostream& operator<<(ostream& out, const Factura& fact )
{
    out<<"Numarul facturei este: "<<fact.Numar_factura<<endl;
    if(fact.Data_factura_emisa!=NULL)
        out<<"Data pentru factura: "<<fact.Data_factura_emisa<<endl;
    else out<<"Nu exista data!\n";

    out<<"Numele beneficiarului este: "<<fact.Beneficiar<<endl;
    out<<"Numele interventiei: "<<fact.Nume_interventie<<endl;
    if(fact.ultimeleNluniBilantLunar>0)
    {
        out<<"Bilantul pe ultimele n luni: "<<fact.ultimeleNluniBilantLunar<<endl;
        for(int i=0; i<fact.ultimeleNluniBilantLunar; i++)
            out<<"Pentru luna "<< i+1<< " am castigat "<<fact.BilantLunarinultimeleNluni[i]<<endl;
    }
    else out<<"Nu exista bilant!\n";


    out<<"Costul pentru interventie este: "<<fact.CostInterventie<<endl;
    out<<"TVA-ul este: "<<fact.TVA<<" %";
    return out;

}
class CabinetVeterinar
{
private:
    char *NumeSocieate;
    int CateAnimale;
    string *ListaAnimale;
    const int idCabinet;
    static int contorId;
    string NumeDoctor;
    string PrenumeDoctor;
    string Locatie;
    int NumarAnimalecapacitate;
    Animal* AnimaleRetinute;
    int NumarAnimaleExistenteInCabinet;
public:

    CabinetVeterinar();
    CabinetVeterinar(char *NumeSocieate,int CateAnimale);
    CabinetVeterinar(char *NumeSocieate,int CateAnimale,string* ListaAnimale);
    CabinetVeterinar(char *NumeSocieate,int CateAnimale,string* ListaAnimale,string NumeDoctor,
                     string PrenumeDoctor, string Locatie,int NumarAnimalecapacitate);

    friend istream& operator>>(istream& in, CabinetVeterinar& cab);
    friend ostream& operator<<(ostream& out, const CabinetVeterinar& cab );
    CabinetVeterinar& operator=(const CabinetVeterinar& cab);
    CabinetVeterinar(const CabinetVeterinar& cab);

    const CabinetVeterinar& operator++();
    CabinetVeterinar operator++(int);
    CabinetVeterinar operator+=(int x);
    CabinetVeterinar operator+(CabinetVeterinar cab);
    friend CabinetVeterinar operator+(int x, CabinetVeterinar cab);
    friend CabinetVeterinar operator+(CabinetVeterinar cab, int x);
    friend CabinetVeterinar operator+(CabinetVeterinar cab, Animal  anim);
    friend CabinetVeterinar operator+( Animal  anim,CabinetVeterinar cab);

    const CabinetVeterinar& operator--();
    CabinetVeterinar operator--(int);
    CabinetVeterinar operator-=(int x);
    CabinetVeterinar operator-(CabinetVeterinar cab);
    friend CabinetVeterinar operator-(int x, CabinetVeterinar cab);
    friend CabinetVeterinar operator-(CabinetVeterinar cab, int x);
    friend CabinetVeterinar operator-(CabinetVeterinar cab, Animal  anim);
    friend CabinetVeterinar operator-( Animal  anim,CabinetVeterinar cab);

    explicit operator float();

    string operator[](int index);

    bool operator==(const CabinetVeterinar& cab);
    bool operator<(const CabinetVeterinar& cab);
    const char* getNumeSocieate();
    int getCateAnimale();
    const string* getListaAnimale();
    string getNumeDoctor();
    string getPrenumeDoctor();
    string getLocatie();
    int getNumarAnimalecapacitate();
    int getNumarAnimaleExistenteInCabinet();
    Animal* getAnimaleRetinute();

    static int getcontorId()
    {
        return CabinetVeterinar::contorId;
    }

    int getidCabinet()
    {
        return this->idCabinet;
    }

    bool  dacaAnimalulSeAflaInListaAnimale(  CabinetVeterinar cab, Animal animal);

    void setNumeSocieate( char* NumarNou, int n);
    void setCateAnimale(int CateAnimale);
    void setListaAnimale( string* ListaAnimale, int n);
    void setNumeDoctor(string NumeDoctor);
    void setPrenumeDoctor(string PrenumeDoctor);
    void setLocatie(string Locatie);
    void setNumarAnimalecapacitate(int NumarAnimalecapacitate);
    void setAnimaleRetinute( Animal* anim, int n);
    void setNumarAnimaleExistenteInCabinet(int NumarAnimaleExistenteInCabinet) ;
    ~CabinetVeterinar();



};
int CabinetVeterinar::getNumarAnimaleExistenteInCabinet()
{
    return NumarAnimaleExistenteInCabinet;
}
Animal* CabinetVeterinar::getAnimaleRetinute()
{
    return this->AnimaleRetinute;
}

 void CabinetVeterinar::setNumarAnimaleExistenteInCabinet(int NumarAnimaleExistenteInCabinet)
  {
      this->NumarAnimaleExistenteInCabinet=NumarAnimaleExistenteInCabinet;
  }
void CabinetVeterinar::setAnimaleRetinute(Animal * anim, int n)/////////////////////////////////////////////////
{
    if(this->AnimaleRetinute!=NULL)
        delete [] this->AnimaleRetinute;
    this->NumarAnimaleExistenteInCabinet=n;
    for(int i=0; i<n; i++)
        this->AnimaleRetinute[i]=anim[i];


}
CabinetVeterinar:: operator float()
{
    return (float)this->NumarAnimalecapacitate;
}

string CabinetVeterinar::operator[](int index)
{
    if(index>=0 &&index <this->CateAnimale)
        return this->ListaAnimale[index];


    return 0;
}
CabinetVeterinar operator-(int x, CabinetVeterinar cab)
{
    cab.NumarAnimalecapacitate=x-cab.NumarAnimalecapacitate;
    return cab;
}

CabinetVeterinar operator-(CabinetVeterinar cab, int x)
{
    cab.NumarAnimalecapacitate=cab.NumarAnimalecapacitate-x;
    return cab;
}
CabinetVeterinar operator-(CabinetVeterinar cab, Animal  anim)
{
    if(cab.dacaAnimalulSeAflaInListaAnimale(cab, anim))
    {
        CabinetVeterinar aux(cab) ;

        if(aux.AnimaleRetinute!=NULL)
            delete [] aux.AnimaleRetinute;
        aux.NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet-1;

        aux.AnimaleRetinute=new Animal [aux.NumarAnimaleExistenteInCabinet];
        int j=0;
        int l=0;

        for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
             if( cab.AnimaleRetinute[i]==anim)
                    l++;
             else   aux.AnimaleRetinute[j++]=cab.AnimaleRetinute[i];

        return aux;
    }
    return cab;
}
CabinetVeterinar operator- (Animal  anim,CabinetVeterinar cab)
{
    if(cab.dacaAnimalulSeAflaInListaAnimale(cab, anim))
    {
        CabinetVeterinar aux(cab) ;

        if(aux.AnimaleRetinute!=NULL)
            delete [] aux.AnimaleRetinute;
        aux.NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet-1;

        aux.AnimaleRetinute=new Animal [aux.NumarAnimaleExistenteInCabinet];
        int j=0;
        int l=0;

        for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
             if( cab.AnimaleRetinute[i]==anim)
                    l++;
             else   aux.AnimaleRetinute[j++]=cab.AnimaleRetinute[i];

        return aux;
    }
    return cab;


}
CabinetVeterinar CabinetVeterinar::operator-(CabinetVeterinar cab)
{
    cab.NumarAnimalecapacitate=cab.NumarAnimalecapacitate-this->NumarAnimalecapacitate;
    return cab;
}
CabinetVeterinar CabinetVeterinar::operator-=(int x)
{
    this->NumarAnimalecapacitate -= x;
    return *this;
}
const CabinetVeterinar& CabinetVeterinar::operator--()
{
    this->NumarAnimalecapacitate--;
    return *this;
}

CabinetVeterinar CabinetVeterinar::operator--(int)
{
    CabinetVeterinar aux(*this);
    this->NumarAnimalecapacitate--;
    return aux;
}
///////////////////////////////////////////////////////
CabinetVeterinar operator+(int x, CabinetVeterinar cab)
{
    cab.NumarAnimalecapacitate=cab.NumarAnimalecapacitate+x;
    return cab;
}

CabinetVeterinar operator+(CabinetVeterinar cab, int x)
{
    cab.NumarAnimalecapacitate=cab.NumarAnimalecapacitate+x;
    return cab;
}
CabinetVeterinar operator+(CabinetVeterinar cab, Animal  anim)
{
    if(cab.dacaAnimalulSeAflaInListaAnimale(cab, anim)==0)
    {
        CabinetVeterinar aux(cab) ;


        if(aux.AnimaleRetinute!=NULL)
            delete [] aux.AnimaleRetinute;

        aux.NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet+1;

        aux.AnimaleRetinute=new Animal [aux.NumarAnimaleExistenteInCabinet];

        for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
            aux.AnimaleRetinute[i]=cab.AnimaleRetinute[i];

        aux.AnimaleRetinute[cab.NumarAnimaleExistenteInCabinet]=anim;
        return aux;
    }
    return cab;


}
CabinetVeterinar operator+( Animal  anim,CabinetVeterinar cab)
{
     if(cab.dacaAnimalulSeAflaInListaAnimale(cab, anim)==0)
    {
        CabinetVeterinar aux(cab) ;


        if(aux.AnimaleRetinute!=NULL)
            delete [] aux.AnimaleRetinute;

        aux.NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet+1;

        aux.AnimaleRetinute=new Animal [aux.NumarAnimaleExistenteInCabinet];

        for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
            aux.AnimaleRetinute[i]=cab.AnimaleRetinute[i];

        aux.AnimaleRetinute[cab.NumarAnimaleExistenteInCabinet]=anim;
        return aux;
    }
    return cab;

}
CabinetVeterinar CabinetVeterinar::operator+(CabinetVeterinar cab)
{
    cab.NumarAnimalecapacitate=cab.NumarAnimalecapacitate+this->NumarAnimalecapacitate;
    return cab;
}
bool CabinetVeterinar::dacaAnimalulSeAflaInListaAnimale( CabinetVeterinar cab, Animal animal)
{   for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
if(cab.AnimaleRetinute[i]==animal)
            return 1;
    return 0;
}
CabinetVeterinar CabinetVeterinar::operator+=(int x)
{
    this->NumarAnimalecapacitate += x;
    return *this;
}
const CabinetVeterinar& CabinetVeterinar::operator++()
{
    this->NumarAnimalecapacitate++;
    return *this;
}

CabinetVeterinar CabinetVeterinar::operator++(int)
{
    CabinetVeterinar aux(*this);
    this->NumarAnimalecapacitate++;
    return aux;
}

CabinetVeterinar::CabinetVeterinar():idCabinet(++contorId)
{
    this->NumeSocieate=NULL;
    this->CateAnimale=0;
    this->ListaAnimale=NULL;
    this->NumeDoctor="None";
    this->PrenumeDoctor="None";
    this->Locatie="None";
    this->NumarAnimalecapacitate=0;
    this->AnimaleRetinute=NULL;
    this->NumarAnimaleExistenteInCabinet=0;
}
CabinetVeterinar::CabinetVeterinar(char *NumeSocieate,int CateAnimale):idCabinet(++contorId)
{
    this->NumeSocieate=new char[strlen(NumeSocieate)+1];
    strcpy(this->NumeSocieate,NumeSocieate);
    this->CateAnimale=CateAnimale;
    this->ListaAnimale=NULL;
    this->NumeDoctor="None";
    this->PrenumeDoctor="None";
    this->Locatie="None";
    this->NumarAnimalecapacitate=0;
    this->AnimaleRetinute=NULL;
    this->NumarAnimaleExistenteInCabinet=0;

}
CabinetVeterinar::CabinetVeterinar(char *NumeSocieate,int CateAnimale,string* ListaAnimale):idCabinet(++contorId)
{
    this->NumeSocieate=new char[strlen(NumeSocieate)+1];
    strcpy(this->NumeSocieate,NumeSocieate);
    this->CateAnimale=CateAnimale;
    this->ListaAnimale=new string [CateAnimale];
    for(int i=0; i<this->CateAnimale; i++)
        this->ListaAnimale[i]=ListaAnimale[i];
    this->NumeDoctor="None";
    this->PrenumeDoctor="None";
    this->Locatie="None";
    this->NumarAnimalecapacitate=0;
    this->AnimaleRetinute=NULL;
    this->NumarAnimaleExistenteInCabinet=0;

}
CabinetVeterinar::CabinetVeterinar(char *NumeSocieate,int CateAnimale,string* ListaAnimale,string NumeDoctor,
                                   string PrenumeDoctor, string Locatie, int NumarAnimalecapacitate):idCabinet(++contorId)
{

    this->NumeSocieate=new char[strlen(NumeSocieate)+1];
    strcpy(this->NumeSocieate,NumeSocieate);
    this->CateAnimale=CateAnimale;
    this->ListaAnimale=new string [CateAnimale];
    for(int i=0; i<this->CateAnimale; i++)
        this->ListaAnimale[i]=ListaAnimale[i];
    this->NumeDoctor=NumeDoctor;
    this->PrenumeDoctor=PrenumeDoctor;
    this->Locatie=Locatie;
    this->NumarAnimalecapacitate=NumarAnimalecapacitate;

    /*this->NumarAnimaleExistenteInCabinet=NumarAnimaleExistenteInCabinet;
    this->AnimaleRetinute= new Animal[NumarAnimaleExistenteInCabinet];
    for(int i=0; i<NumarAnimaleExistenteInCabinet; i++)
        this->AnimaleRetinute[i]=AnimaleRetinute[i];*/
         this->AnimaleRetinute=NULL;
    this->NumarAnimaleExistenteInCabinet=0;


}
const char* CabinetVeterinar::getNumeSocieate()
{
    return this->NumeSocieate;
}
int CabinetVeterinar::getNumarAnimalecapacitate()
{
    return this->NumarAnimalecapacitate;
}
void CabinetVeterinar::setNumarAnimalecapacitate(int NumarAnimalecapacitate)
{
    this->NumarAnimalecapacitate=NumarAnimalecapacitate;
}
void CabinetVeterinar::setNumeSocieate( char* NumeSocieate, int n)
{
    if(this->NumeSocieate!=NULL)
        delete [] this->NumeSocieate;
    this->NumeSocieate=new char [n+1];
    strcpy(this->NumeSocieate,NumeSocieate);
}
int CabinetVeterinar::getCateAnimale()
{
    return this->CateAnimale;
}

const string* CabinetVeterinar::getListaAnimale()
{
    return this->ListaAnimale;
}

void CabinetVeterinar::setListaAnimale( string* ListaAnimale, int n)
{
    this->CateAnimale=n;
    if(this->ListaAnimale!=NULL)
        delete [] this->ListaAnimale;
    this->ListaAnimale=new string[n];
    for(int i=0; i<n; i++)
        this->ListaAnimale[i]=ListaAnimale[i];

}

string CabinetVeterinar::getNumeDoctor()
{
    return NumeDoctor;
}
void CabinetVeterinar::setNumeDoctor(string NumeDoctor)
{
    this->NumeDoctor=NumeDoctor;
}

string CabinetVeterinar::getPrenumeDoctor()
{
    return PrenumeDoctor;
}
void CabinetVeterinar::setPrenumeDoctor(string PrenumeDoctor)
{
    this->PrenumeDoctor=PrenumeDoctor;
}

string CabinetVeterinar::getLocatie()
{
    return Locatie;
}
void CabinetVeterinar::setLocatie(string Locatie)
{
    this->Locatie=Locatie;
}
CabinetVeterinar::~CabinetVeterinar()
{
    if(this->NumeSocieate!=NULL)
        delete [] this->NumeSocieate;
    if(this->ListaAnimale!=NULL)
        delete [] this->ListaAnimale;
    if(this->AnimaleRetinute!=NULL)
        delete [] this->AnimaleRetinute;
}

CabinetVeterinar::CabinetVeterinar(const CabinetVeterinar& cab):idCabinet(contorId)
{
    this->NumeSocieate=new char[strlen(cab.NumeSocieate)+1];
    strcpy(this->NumeSocieate,cab.NumeSocieate);

    this->CateAnimale=cab.CateAnimale;

    this->ListaAnimale=new string[cab.CateAnimale];
    for(int i=0; i<cab.CateAnimale; i++)
        this->ListaAnimale[i]=cab.ListaAnimale[i];

    this->NumeDoctor=cab.NumeDoctor;
    this->PrenumeDoctor=cab.PrenumeDoctor;
    this->Locatie=cab.Locatie;
    this->NumarAnimalecapacitate=cab.NumarAnimalecapacitate;
    this->NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet;

    this->AnimaleRetinute= new Animal [cab.NumarAnimaleExistenteInCabinet];
    for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
        this->AnimaleRetinute[i]=cab.AnimaleRetinute[i];

}
CabinetVeterinar& CabinetVeterinar::operator=(const CabinetVeterinar& cab)
{
    if(this!=&cab)
    {
        if(this->NumeSocieate!=NULL)
            delete [] this->NumeSocieate;
        if(this->ListaAnimale!=NULL)
            delete [] this->ListaAnimale;
        if(this->AnimaleRetinute!=NULL)
            delete [] this->AnimaleRetinute;

            this->NumeSocieate=new char[strlen(cab.NumeSocieate)+1];
        for(int i=0; i<strlen(cab.NumeSocieate)+1; i++)
            this->NumeSocieate[i]=cab.NumeSocieate[i];
        this->CateAnimale=cab.CateAnimale;

        this->ListaAnimale=new string[cab.CateAnimale];
        for(int i=0; i<cab.CateAnimale; i++)
            this->ListaAnimale[i]=cab.ListaAnimale[i];

        this->NumeDoctor=cab.NumeDoctor;
        this->PrenumeDoctor=cab.PrenumeDoctor;
        this->Locatie=cab.Locatie;
        this->NumarAnimalecapacitate=cab.NumarAnimalecapacitate;

        this->NumarAnimaleExistenteInCabinet=cab.NumarAnimaleExistenteInCabinet;

        this->AnimaleRetinute= new Animal [cab.NumarAnimaleExistenteInCabinet];
        for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
            this->AnimaleRetinute[i]=cab.AnimaleRetinute[i];
    }
    return *this;
}
istream& operator>>(istream& in, CabinetVeterinar& cab)
{
    cout<<"Numele societatii este: "  ;
    char s[101];
    in>>s;
    if( cab.NumeSocieate!=NULL)
        delete []cab.NumeSocieate;
    cab.NumeSocieate=new char[strlen(s)+1];
    strcpy(cab.NumeSocieate,s);
    cout<<"Cate tipuri de animale primim: " ;
    in>>cab.CateAnimale;
    cout<<"Acestea sunt: " ;
    if(cab.ListaAnimale!=NULL)
        delete [] cab.ListaAnimale;

    cab.ListaAnimale=new string[cab.CateAnimale];
    for(int i=0; i<cab.CateAnimale; i++)
        in>>cab.ListaAnimale[i];
    cout<<"Numele Doctorului este: "  ;
    in>>cab.NumeDoctor;
    cout<<"Prenumele Doctorului este: "  ;
    in>>cab.PrenumeDoctor;
    cout<<"Locatia este: ";
    in>>cab.Locatie;
    cout<<"Numar maxim animale acceptate: ";
    in>>cab.NumarAnimalecapacitate;
    /*cout<<"Cate animale exista in cabinet: ";

    in>>cab.NumarAnimaleExistenteInCabinet;

    if(cab.AnimaleRetinute!=NULL)
        delete [] cab.AnimaleRetinute;

    cab.AnimaleRetinute= new Animal [cab.NumarAnimaleExistenteInCabinet];

    for(int i=0;i<cab.NumarAnimaleExistenteInCabinet;i++)
        in>>cab.AnimaleRetinute[i];*/
    return in;

}
ostream& operator<<(ostream& out, const CabinetVeterinar& cab )
{
    //out<<"Id cabinet: "<<cab.idCabinet<<endl;
    out<<"Numele societatii este: "<<cab.NumeSocieate<<endl;

    out<<"Cate tipuri de animale primim: "<<cab.CateAnimale<<endl<<"Acestea sunt: "<<endl;

    for(int i=0; i<cab.CateAnimale; i++)
        out<<cab.ListaAnimale[i]<<endl;

    out<<endl;
    out<<"Numele Doctorului este: "<<cab.NumeDoctor<<endl<<"Prenumele Doctorului este: "<<cab.PrenumeDoctor<<endl<<"Locatia este: "<<cab.Locatie<<endl<<"Numar maxim animale acceptate: "<<cab.NumarAnimalecapacitate<<endl;
   out<<"Cate animale sunt in cabinet: "<<cab.NumarAnimaleExistenteInCabinet<<endl ;

    for(int i=0; i<cab.NumarAnimaleExistenteInCabinet; i++)
        out<<cab.AnimaleRetinute[i]<<endl;
    return out;

}

bool CabinetVeterinar::operator==(const CabinetVeterinar& cab)
{
    if(this->CateAnimale==cab.CateAnimale && this->NumarAnimalecapacitate==cab.NumarAnimalecapacitate)
        return true;
    return false;

}
bool CabinetVeterinar::operator<(const CabinetVeterinar& cab)
{

    if (  this->CateAnimale<cab.CateAnimale || this->NumarAnimalecapacitate<cab.NumarAnimalecapacitate)
        return true;
    return false;

}
int CabinetVeterinar::contorId=0;

class Proprietar
{
private:
    int NumarAnimale;
    string NumarTelefon;
    string CNP;
    string NumeProprietar;
    float SumaDePlata;

public:
    Proprietar();
    Proprietar(int NumarAnimale);
    Proprietar(int NumarAnimale,string NumarTelefon);
    Proprietar(int NumarAnimale,string NumarTelefon,string CNP,string NumeProprietar, float  SumaDePlata);

    int getNumarAnimale();
    string getCNP();
    string getNumarTelefon();
    string getNumeProprietar();
    float getSumaDePlata();

    friend istream& operator>>(istream& in, Proprietar& prop);
    friend ostream& operator<<(ostream& out, const Proprietar& prop );
    Proprietar(const Proprietar& prop);
    Proprietar& operator=(const Proprietar& prop);

    const Proprietar& operator++();
    Proprietar operator++(int);
    Proprietar operator+=(int x);
    Proprietar operator+(Proprietar prop);
    friend Proprietar operator+(int x, Proprietar prop);
    friend Proprietar operator+(Proprietar prop, int x);
    friend Proprietar operator+(Proprietar prop, Factura  fact);
    friend Proprietar operator+( Factura  fact,Proprietar prop);

    const Proprietar& operator--();
    Proprietar operator--(int);
    Proprietar operator-=(int x);
    Proprietar operator-(Proprietar prop);
    friend Proprietar operator-(int x, Proprietar prop);
    friend Proprietar operator-(Proprietar prop, int x);
    friend Proprietar operator-(Proprietar prop, Factura  fact);
    friend Proprietar operator-( Factura  fact,Proprietar prop);
    bool operator==(const Proprietar& prop);
    bool operator<(const Proprietar& prop);

    bool verificareDacaProprietarulERoman( Proprietar prop);


    explicit operator int();

    void setNumarAnimale(int NumarAnimale);
    void setCNP( string CNP);
    void setNumarTelefon( string NumarTelefon);
    void setNumeProprietar(string NumeProprietar);
    void setSumaDePlata( float SumaDePlata);
    ~Proprietar();


};
Proprietar::operator int()
{
    return (int)this->SumaDePlata;
}
bool Proprietar::verificareDacaProprietarulERoman( Proprietar prop)
{
    if(prop.CNP.size()==12 && prop.NumarTelefon[0]=='0' &&prop.NumarTelefon[1]=='7' && prop.NumarTelefon.size()==10)
        return true;
    return false;
}
bool Proprietar::operator==(const Proprietar& prop)
{
    if(this-> CNP== prop.CNP)
        return true;
    return false;
}
bool Proprietar::operator<(const Proprietar& prop)
{
    if(this->NumarAnimale<prop.NumarAnimale)
        return true;
    return false;
}
Proprietar operator+(Proprietar prop, Factura  fact)
{

    float suma=fact.getCostInterventie() ;
    prop.SumaDePlata=prop.SumaDePlata+prop.NumarAnimale*suma;

    return prop;
}
Proprietar operator+( Factura  fact,Proprietar prop)
{
    float suma=fact.getCostInterventie() ;
    prop.SumaDePlata=prop.SumaDePlata+prop.NumarAnimale*suma;

    return prop;
}
Proprietar operator-(Proprietar prop, Factura  fact)
{
    Proprietar aux(prop);
    float suma=fact.getCostInterventie() ;
    prop.SumaDePlata=prop.SumaDePlata-prop.NumarAnimale*suma;

    return prop;
}
Proprietar operator-( Factura  fact,Proprietar prop)
{
    float suma=fact.getCostInterventie() ;
    prop.SumaDePlata=prop.NumarAnimale*suma-prop.SumaDePlata;

    return prop;
}
const Proprietar&  Proprietar::operator++()
{
    this->NumarAnimale++;
    return *this;

}
Proprietar Proprietar::operator++(int)
{
    Proprietar aux(*this);
    this->NumarAnimale++;
    return aux;
}
Proprietar Proprietar::operator+=(int x)
{
    this->NumarAnimale+=x;
    return *this;
}
Proprietar Proprietar::operator+(Proprietar prop)
{
    prop.NumarAnimale=prop.NumarAnimale+this->NumarAnimale;
    return prop;
}
Proprietar operator+(int x, Proprietar prop)
{
    prop.NumarAnimale=prop.NumarAnimale+x;
    return prop;

}
Proprietar operator+(Proprietar prop, int x)
{
    prop.NumarAnimale=prop.NumarAnimale+x;
    return prop;
}
/////////////
const Proprietar&  Proprietar::operator--()
{
    this->NumarAnimale--;
    return *this;

}
Proprietar Proprietar::operator--(int)
{
    Proprietar aux(*this);
    this->NumarAnimale--;
    return aux;
}
Proprietar Proprietar::operator-=(int x)
{
    this->NumarAnimale-=x;
    return *this;
}
Proprietar Proprietar::operator-(Proprietar prop)
{
    prop.NumarAnimale=prop.NumarAnimale-this->NumarAnimale;
    return prop;
}
Proprietar operator-(int x, Proprietar prop)
{
    prop.NumarAnimale=x-prop.NumarAnimale;
    return prop;

}
Proprietar operator-(Proprietar prop, int x)
{
    prop.NumarAnimale=prop.NumarAnimale-x;
    return prop;
}

Proprietar::Proprietar()
{
    this->NumarAnimale=0;
    this->NumarTelefon="Nealocat";
    this->CNP="Nealocat";
    this->NumeProprietar="Neexistent";
    this->SumaDePlata=0.0;
}
Proprietar::Proprietar(int NumarAnimale  )
{
    this->NumarAnimale=NumarAnimale;
    this->NumarTelefon="Nealocat";
    this->CNP="Nealocat";
    this->NumeProprietar="Neexistent";
    this->SumaDePlata=0.0;
}
Proprietar::Proprietar(int NumarAnimale,string NumarTelefon  )
{
    this->NumarAnimale=NumarAnimale;
    this->NumarTelefon=NumarTelefon;
    this->CNP="Nealocat";
    this->NumeProprietar="Neexistent";
    this->SumaDePlata=0.0;

}
Proprietar::Proprietar(int NumarAnimale,string NumarTelefon,string CNP,string NumeProprietar, float SumaDePlata=0.0)
{
    this->NumarAnimale=NumarAnimale;
    this->NumarTelefon=NumarTelefon;
    this->CNP=CNP;
    this->NumeProprietar=NumeProprietar;
}
float Proprietar::getSumaDePlata()
{
    return SumaDePlata;
}
void Proprietar::setSumaDePlata(float SumaDePlata)
{
    this->SumaDePlata=SumaDePlata;
}
int Proprietar::getNumarAnimale()
{
    return NumarAnimale;
}
void Proprietar::setNumarAnimale(int NumarAnimale)
{
    this->NumarAnimale=NumarAnimale;
}

string Proprietar::getNumarTelefon()
{
    return NumarTelefon;
}
void Proprietar::setNumarTelefon(string NumarTelefon)
{
    this->NumarTelefon=NumarTelefon;
}

string Proprietar::getCNP()
{
    return this->CNP;
}
void Proprietar::setCNP(string CNP)
{
    this->CNP=CNP;
}
string Proprietar::getNumeProprietar()
{
    return this->NumeProprietar;
}
void Proprietar::setNumeProprietar(string NumeProprietar)
{
    this->NumeProprietar=NumeProprietar;
}
Proprietar& Proprietar::operator=(const Proprietar& prop)
{
    if(this!=&prop)
    {
        this->CNP=prop.CNP;
        this->NumarAnimale=prop.NumarAnimale;
        this->NumarTelefon=prop.NumarTelefon;
        this->NumeProprietar=prop.NumeProprietar;
        this->SumaDePlata=prop.SumaDePlata;

    }
    return *this;

}
Proprietar::Proprietar(const Proprietar& prop)
{
    this->CNP=prop.CNP;
    this->NumarAnimale=prop.NumarAnimale;
    this->NumarTelefon=prop.NumarTelefon;
    this->NumeProprietar=prop.NumeProprietar;
    this->SumaDePlata=prop.SumaDePlata;
}
Proprietar::~Proprietar()
{
}
istream& operator>>(istream& in, Proprietar& prop)
{
    cout<<"CNP-ul propietarului este: ";
    in>>prop.CNP;
    cout<<"Cate animale are propietarul: ";
    in>>prop.NumarAnimale;
    cout<<"Telefonul propietarului este: ";
    in>>prop.NumarTelefon;
    cout<<"Numele propietarului este: ";
    in>>prop.NumeProprietar;
    cout<<"Proprietarul are de plata: "<<prop.SumaDePlata<<endl;
    return in;


}
ostream& operator<<(ostream& out, const Proprietar& prop )
{
    out<<"Propietarul are: "<<prop.NumarAnimale<<" animale"<<endl;
    out<<"Telefonul propietarului este: "<<prop.NumarTelefon<<endl;
    out<<"CNP-ul propietarului este: "<<prop.CNP<<endl;
    out<<"Numele propietarului este: "<<prop.NumeProprietar<<endl;
    out<<"Proprietarul are de plata: "<<prop.SumaDePlata;
    return out;
}
int main()
{
    vector <CabinetVeterinar> listaCabinetVeterinar;
    vector<Animal> listaAnimale;
    vector <Proprietar> listaPropietari;
    vector <Factura> listaFactura;

    int k=1,comanada;
    int contor1=0, contor2=0, contor3=0, contor4;
    while(k==1)
    {
        system("cls");

        cout<<"1-Adaugare Cabinet\n2-Adaugare Animal\n3-Adaugare Proprietar\n4-Adaugare Factura\n5-Stop\n";
        cin>>comanada;


        switch(comanada)
        {
        case 1:
        {
            CabinetVeterinar a;
            cin>>a;
            listaCabinetVeterinar.push_back(a);

            int t=1, comandasub;
            while(t==1)
            {
                cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toate cabinete\n5-Adauga un animal in cabinet\n";
                cin>>comandasub;
                int l=1, operatie;
                switch(comandasub)
                {
                case 1:
                {


                    while(l==1)
                    {
                        cout<<"1-Modificare Nume Cabinet\n2-Modificare cate tipuri de animale primeste cabinetul\n3-Modificare NumeDoctor\n4-Modificare PrenumeDoctor\n5-Modificare Locatie\n6-Modificare Capacitate\n7-Afisare dupa update\n8-Stop\n";
                        cin>>operatie;
                        switch(operatie)
                        {
                        case 1:
                        {
                            cout<<"Introduceti noul nume pentru cabinet: ";
                            char s[100];
                            cin>>s;
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaCabinetVeterinar[contor].setNumeSocieate(s,strlen(s));


                            break;
                        }
                        case 2:
                        {
                            cout<<"Cate animale contine noua lista: \n";
                            int x;
                            cin>>x;
                            cout<<"Noua lista de animale este: \n";
                            string lista[x];
                            for(int contor=0; contor<x; contor++)
                                cin>>lista[contor];
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            listaCabinetVeterinar[contor].setListaAnimale(lista,x);


                            break;
                        }
                        case 3:
                        {
                            cout<<"Noul nume al Doctorului este: \n";
                            string x;
                            cin>>x;
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaCabinetVeterinar[contor].setNumeDoctor(x);
                            break;
                        }
                        case 4:
                        {
                            cout<<"Noul prenume al Doctorului este: \n";
                            string x;
                            cin>>x;
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaCabinetVeterinar[contor].setPrenumeDoctor(x);
                            break;
                        }
                        case 5:
                        {
                            cout<<"Noua locatie a cabinetului este: \n";
                            string x;
                            cin>>x;
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaCabinetVeterinar[contor].setLocatie(x);
                            break;
                        }
                        case 6:
                        {
                            cout<<"Noua capacitate a cabinetului este: \n";
                            int x;
                            cin>>x;
                            cout<<"\n Pentru al catelea cabinet se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaCabinetVeterinar[contor].setNumarAnimalecapacitate(x);
                            break;
                        }
                        case 7:
                        {
                            cout<<"\n Pentru al catelea cabinet se face afisarea dupa update: ";
                            int contor;
                            cin>>contor;
                            cout<<listaCabinetVeterinar[contor]<<endl;
                            break;
                        }
                        case 8:
                        {
                            l=0;
                            break;
                        }
                        default:
                        {
                            cout<<"Ati introdus o valoare gresita!/n";


                            break;


                        }

                        }
                    }
                    break;

                }
                case 2:
                {
                    cout<<"Introduceti  numele cabinetului pentru a-l sterge: ";
                    char s[100];
                    cin>>s;

                    for(int i=0; i<listaCabinetVeterinar.size(); i++)
                        if(strcmp(listaCabinetVeterinar[i].getNumeSocieate(),s)==0)
                            listaCabinetVeterinar.erase(listaCabinetVeterinar.begin()+i);


                    break;
                }
                case 3:
                {
                    t=0;
                    break;
                }
                case 4:
                {
                    for(int i=0; i<listaCabinetVeterinar.size(); i++)
                        cout<<listaCabinetVeterinar[i]<<endl;
                    break;

                }
                case 5:
                {
                        cout<<"Scrieti in care cabinet doriti sa adaugati un animal:  ";
                        int index;
                        cin>>index;
                        cout<<"Scrieti ce animal doriti sa adaugati: ";
                        int index1;
                        cin>>index1;
                        if(listaCabinetVeterinar[index].getNumarAnimalecapacitate()>=listaCabinetVeterinar[index].getNumarAnimaleExistenteInCabinet())
                        listaCabinetVeterinar[index]=listaCabinetVeterinar[index]+ listaAnimale[index1];
                        break;
                }

                default:
                {
                    cout<<"Ati introdus o valoare gresita\n";


                    break;


                }
                }

            }
            break;



        }
        case 2:
        {
            Animal b;
            cin>>b;
            listaAnimale.push_back(b);

            int t=1, comandasub;
            while(t==1)
            {
                cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toate animale\n5-Ultima data cand a fost verificat animalul\n";
                cin>>comandasub;
                int l=1, operatie;
                switch(comandasub)
                {
                case 1:
                {


                    while(l==1)
                    {

                        cout<<"1-Modificare Vaccin\n2-Modificare luna vaccin\n3-Modificare vizite la cabinet si lunile\n4-Modificare Greutate\n5-Modificare Inaltime\n6-Modificare Varsta\n7-Modificare Categorie\n8-Modificare initiala animal\n9-Modificare cnp stapan\n10-Afisare dupa update\n11-Stop\n";
                        cin>>operatie;
                        switch(operatie)
                        {
                        case 1:
                        {
                            cout<<"Modificare Vaccin: ";
                            bool v;
                            cin>>v;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setVaccin(v);

                            break;
                        }
                        case 2:
                        {
                            cout<<"Noua luna in care animalul a fost vaccinat; \n";
                            string s;
                            cin>>s;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setLunaVaccin(s);

                            break;
                        }
                        case 3:
                        {
                            cout<<"Modificare vizite la cabinet si lunile: \n";
                            int x;
                            cin>>x;
                            int* v ;
                            if(v!=NULL)
                                delete [] v;

                            v= new int[x];
                            for(int contor=0; contor<x; contor++)
                                cin>>v[contor];
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setVizitemedicaleinultimeleNluni(v,x);
                            if(v!=NULL)
                                delete [] v;

                            break;
                        }
                        case 4:
                        {
                            cout<<"Noua greutate este: \n";
                            double x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setGreutate(x);
                            break;
                        }
                        case 5:
                        {
                            cout<<"Noua inaltime este: \n";
                            float x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setInaltime(x);
                            break;
                        }
                        case 6:
                        {
                            cout<<"Noua varsta este: \n";
                            int x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setVarsta(x);
                            break;
                        }
                        case 7:
                        {
                            cout<<"Noua categorie este: \n";
                            string x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setCategorie(x);
                            break;
                        }
                        case 8:
                        {
                            cout<<"Noua initiala pentru nume este: \n";
                            char x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setinitialaNume(x);
                            break;
                        }
                        case 9:
                        {
                            cout<<"Noul cnp al stapanului este: \n";
                            string x;
                            cin>>x;
                            cout<<"Pentru al catelea animal se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaAnimale[contor].setCnpStapan(x);
                            break;
                        }

                        case 10:
                        {
                            cout<<"Pentru al catelea animal se face afiarea dupa update: ";
                            int contor;
                            cin>>contor;
                            cout<<listaAnimale[contor]<<endl;
                            break;
                        }
                        case 11:
                        {
                            l=0;
                            break;
                        }
                        default:
                        {
                            cout<<"Ati introdus o valoare gresita!/n";


                            break;


                        }

                        }
                    }
                    break;

                }
                case 2:
                {
                    cout<<"Introduceti cnp-ul stapanului pentru a-l sterge: ";
                    string  cnp,categorie;
                    cin>>cnp;
                    cout<<"Introduceti categoria animalului pentru a-l sterge: ";
                    cin>>categorie;



                    for(int i=0; i<listaAnimale.size(); i++)
                        if(listaAnimale[i].getCnpStapan()==cnp && listaAnimale[i].getCategorie()==categorie)
                            listaAnimale.erase(listaAnimale.begin()+i);


                    break;

                }
                case 3:
                {
                    t=0;
                    break;
                }
                case 4:
                {
                    for(int i=0; i<listaAnimale.size(); i++)
                        cout<<listaAnimale[i]<<endl;
                    break;
                }
                case 5:
                {
                    cout<<"Scriete pentru ce animal doriti sa verificati: ";
                    int index;
                    cin>>index;
                    cout<<"Animalul a fost verificat in: "<<listaAnimale[index].ultimaDataCandaFostVerificat(listaAnimale[index])<<endl;
                    break;
                }
                default:
                {
                    cout<<"Ati introdus o valoare gresita\n";


                    break;


                }
                }

            }

            break;



        }









        case 3:
        {
            Proprietar c;
            cin>>c;
            listaPropietari.push_back(c);

            int t=1, comandasub;
            while(t==1)
            {
                cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toti proprietari\n5-Verificare daca proprietarul e roman\n";
                cin>>comandasub;
                int l=1, operatie;
                switch(comandasub)
                {
                case 1:
                {


                    while(l==1)
                    {

                        cout<<"1-Modificare numar animale\n2-Modificare numar telefon\n3-Modificare Cnp\n4-Modificare nume proprietar\n5-Modificare suma de plata\n6-Afisare dupa update\n7-Stop\n";
                        cin>>operatie;
                        switch(operatie)
                        {
                        case 1:
                        {
                            cout<<"Modificare numar animale: ";
                            int v;
                            cin>>v;
                            cout<<"Pentru al catelea proprietar se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaPropietari[contor].setNumarAnimale(v);

                            break;
                        }
                        case 2:
                        {
                            cout<<"Modificare numar telefon: \n";
                            string s;
                            cin>>s;
                            cout<<"Pentru al catelea proprietar se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaPropietari[contor].setNumarTelefon(s);

                            break;
                        }
                        case 3:
                        {
                            cout<<"Modificare Cnp: \n";
                            string s;
                            cin>>s;
                            cout<<"Pentru al catelea proprietar se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaPropietari[contor].setCNP(s);

                            break;
                        }
                        case 4:
                        {
                            cout<<"Modificare nume proprietar: \n";
                            string s;
                            cin>>s;
                            cout<<"Pentru al catelea proprietar se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaPropietari[contor].setNumeProprietar(s);
                            break;
                        }
                        case 5:
                        {
                            cout<<"Modificare suma de plata: \n";
                            float x;
                            cin>>x;
                            cout<<"Pentru al catelea proprietar se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaPropietari[contor].setSumaDePlata(x);
                            break;
                        }
                        case 6:
                        {
                            cout<<"Pentru al catelea proprietar se afiseaza dupa update: ";
                            int contor;
                            cin>>contor;
                            cout<<listaPropietari[contor]<<endl;

                            break;
                        }


                        case 7:
                        {
                            l=0;
                            break;
                        }
                        default:
                        {
                            cout<<"Ati introdus o valoare gresita!/n";

                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout<<"Introduceti cnp-ul persoanei pentru a o sterge: ";
                    string cnp;
                    cin>>cnp;




                    for(int i=0; i<listaPropietari.size(); i++)

                        if(listaPropietari[i].getCNP()==cnp)
                            listaPropietari.erase(listaPropietari.begin()+i);


                    break;

                }
                case 3:
                {
                    t=0;
                    break;
                }
                case 4:
                {
                    for(int i=0; i<listaPropietari.size(); i++)
                        cout<<listaPropietari[i]<<endl;
                    break;
                }
                case 5:
                    {
                        cout<<"Scriete pentru ce propritar doriti sa vedeti daca este roman: ";
                        int index;
                        cin>>index;
                        if(listaPropietari[index].verificareDacaProprietarulERoman(listaPropietari[index]))
                            cout<<"Propritarul "<< index<<" este roman\n";
                        else cout<<"Alta cetatenie\n";
                        break;
                    }

                default:
                {
                    cout<<"Ati introdus o valoare gresita\n";


                    break;


                }


                }
            }
            break;
        }
        case 4:
        {
            Factura d;
            cin>>d;
            listaFactura.push_back(d);
            int t=1, comandasub;
            while(t==1)
            {
                cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toate facturile\n5-Bilant pentru o factura\n";
                cin>>comandasub;
                int l=1, operatie;
                switch(comandasub)
                {
                case 1:
                {


                    while(l==1)
                    {


                        cout<<"1-Modificare numar factura\n2-Modificare Data_factura_emisa\n3-Modificare Beneficiar\n4-Modificare nume interventie\n5-Modificare ultimeleNluniBilantLunar+ BilantLunarinultimeleNluni\n6-Modificare CostInterventie\n7-Modificare TVA\n8-Afisare dupa update\n9-Stop\n";
                        cin>>operatie;
                        switch(operatie)
                        {
                        case 1:
                        {
                            cout<<"Modificare numar factura: ";
                            string v;
                            cin>>v;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setNumar_factura(v);

                            break;
                        }
                        case 2:
                        {
                            cout<<"Modificare Data_factura_emisa: \n";
                            char s[10];
                            cin>>s;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setData_factura_emisa(s);

                            break;
                        }
                        case 3:
                        {
                            cout<<"Modificare Beneficiar: /n";
                            string x;
                            cin>>x;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setBeneficiar(x);
                            break;
                        }
                        case 4:
                        {
                            cout<<"Modificare nume interventie: \n";
                            string x;
                            cin>>x;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setNume_interventie(x);
                            break;
                        }
                        case 5:
                        {
                            cout<<"Modificare ultimeleNluniBilantLunar+Modificare BilantLunarinultimeleNluni: \n";
                            int x;
                            cin>>x;
                            float* v ;
                            if(v!=NULL)
                                delete [] v;
                            v= new float[x];
                            for(int contor=0; contor<x; contor++)
                                cin>>v[contor];
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setBilantLunarinultimeleNluni(v,x);
                            if(v!=NULL)
                                delete [] v;

                            break;
                        }
                        case 6:
                        {
                            cout<<"Modificare cost interventie: \n";
                            float s;
                            cin>>s;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setCostInterventie(s);
                            break;
                        }

                        case 7:
                        {
                            cout<<"Modificare TVA: \n";
                            float x;
                            cin>>x;
                            cout<<"Pentru care factura se face modificare: ";
                            int contor;
                            cin>>contor;
                            listaFactura[contor].setTVA(x);
                            break;
                        }

                        case 8:
                        {
                            cout<<"Pentru care factura se face afisarea dupa update: ";
                            int contor;
                            cin>>contor;
                            cout<<listaFactura[contor]<<endl;
                            break;
                        }


                        case 9:
                        {
                            l=0;
                            break;
                        }
                        default:
                        {
                            cout<<"Ati introdus o valoare gresita!/n";

                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout<<"Introduceti numarul-ul facturei pentru a o sterge: ";
                    string nrf;
                    cin>>nrf;




                    for(int i=0; i<listaFactura.size(); i++)

                        if(listaFactura[i].getNumar_factura()==nrf)
                            listaFactura.erase(listaFactura.begin()+i);


                    break;

                }
                case 3:
                {
                    t=0;
                    break;
                }
                case 4:
                {
                    for(int i=0; i<listaFactura.size(); i++)
                        cout<<listaFactura[i]<<endl;
                    break;
                }
                case 5:
                    {
                        cout<<"Scriti pentru ce factura doriti sa calculati: ";
                        int index;
                        cin>>index;
                        cout<<"Pentru factura "<< index << " am castigat(cu tot cu TV) :"<<listaFactura[index].ProfitUltimeleNLuni(listaFactura[index])<<endl;
                        break;
                    }

                default:
                {
                    cout<<"Ati introdus o valoare gresita\n";


                    break;


                }


                }
            }


            break;




        }


        case 5:
        {
            k=0;
            break;
        }

        default:
        {
            cout<<"Ati introdus o valoare gresita\n";


            break;


        }
        }}


    return 0;
}
