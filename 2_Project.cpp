#include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <exception>

using namespace std;

class IOInterface
{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0 ;
};

template< typename T >
class arr
{
private:
    int lg;
    T *myarr;
public:
    arr (int s)
    {
        lg = s;
        myarr = new T [lg];
    }
    void setarr ( int elem, T val)
    {
        myarr[elem] = val;
    }

    void getarr (int n)
    {
        for ( int j = 0; j < n; j++ )
        {
            cout  << myarr[j] << endl;
        }
    }
    T operator[](int index)
    {
        return myarr[index];


    }

};

class Masina: public IOInterface
{
protected:
    string marca;
    string model;
    double pret;
    int anAparitie;
    float greutate;
    int numarLocuri;
    float autonomie;
public:
    Masina();
    Masina(string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri, float autonomie );

    friend istream& operator>>(istream& in, Masina& mas);
    friend ostream& operator<<(ostream& out, const Masina& mas );
    Masina& operator=(const Masina& mas);
    Masina(const Masina& mas);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    string getmodel()
    {
        return this->model;
    }
    template<class T1, class T2>
    friend T1 operator+(T1 masina1, T2 masina2)
    {
        cout<<"asdasdsad";
        cout<<masina1<<endl<<masina2<<endl;
        masina1.pret+=masina2.pret;

        return masina1;
    }

    /*template<class T1,class T2>
     friend T1 operator+(T1 masina1, T2 masina2)
    {
        if(typeid(masina1).name()==typeid(MasinaCuCombustibilFosili).name() || typeid(masina1).name()==typeid(MasinaElectrica).name() || typeid(masina1).name()==typeid(MasinaHibrida).name())
            masina1.pret+=masina2.pret;

        else masina1.pret+= masina2;

        return masina1;
    }*/



    template<class T1>
    friend T1 operator+(T1 masina1, char* x);

    template<class T1>
    friend T1 operator+(char* x,T1 masina1);

    template<class T1>
    friend T1 operator+(T1 masina1, const char* x);

    template<class T1>
    friend T1 operator+(const char* x,T1 masina1);

    template<class T1>
    friend T1 operator+(T1 masina1, string x);

    template<class T1>
    friend T1 operator+(string x,T1 masina1);

    template<class T1>
    friend T1 operator+(T1 masina1, int x);

    template<class T1>
    friend T1 operator+(int  x,T1 masina1);

    template<class T1>
    friend T1 operator+(T1 masina1, double x);

    template<class T1>
    friend T1 operator+(double  x,T1 masina1);

    virtual void calculpretinfunctiedetaxa()=0;
    ~Masina()
    {

    }

};
template<class T1>
T1 operator+(double x,T1 masina1)
{
    masina1.pret+=x ;
    return masina1;
}
template<class T1>
T1 operator+(T1 masina1, double x)
{
    masina1.pret+=x ;
    return masina1;

}
template<class T1>
T1 operator+(int x,T1 masina1)
{
    masina1.pret+=x ;
    return masina1;
}
template<class T1>
T1 operator+(T1 masina1, int x)
{
    masina1.pret+=x ;
    return masina1;

}

template<class T1>
T1 operator+(string x,T1 masina1)
{
    masina1.pret+=x.length();
    return masina1;
}
template<class T1>
T1 operator+(T1 masina1, string x)
{
    masina1.pret+=x.length();
    return masina1;

}

template<class T1>
T1 operator+(T1 masina1, char* x)
{
    masina1.pret+=strlen(x);
    return masina1;
}
template<class T1>
T1 operator+(char* x,T1 masina1)
{
    masina1.pret+=strlen(x);
    return masina1;
}
template<class T1>
T1 operator+(T1 masina1, const char* x)
{
    masina1.pret+=strlen(x);
    return masina1;
}
template<class T1>
T1 operator+(const char* x,T1 masina1)
{
    masina1.pret+=strlen(x);
    return masina1;
}
/*
template<class T>
T operator+(T masina1, T masina2)
{
    masina1.pret+=masina2.pret;
    return masina1;
}*/
Masina& Masina::operator=(const Masina& mas)
{
    if(this!=&mas)
    {
        this->marca=mas.marca;
        this->model=mas.model;
        this->pret=mas.pret;
        this->anAparitie=mas.anAparitie;
        this->greutate=mas.greutate;
        this->numarLocuri=mas.numarLocuri;
        this->autonomie=mas.autonomie;
    }
    return *this;
}
Masina::Masina(const Masina& mas)
{
    this->marca=mas.marca;
    this->model=mas.model;
    this->pret=mas.pret;
    this->anAparitie=mas.anAparitie;
    this->greutate=mas.greutate;
    this->numarLocuri=mas.numarLocuri;
    this->autonomie=mas.autonomie;
}

istream& Masina::read(istream& in)
{
    cout<<"Marca masinii este: ";
    in>>this->marca;
    cout<<"Modelul masinii este: ";
    in>>this->model;
    cout<<"Cat costa  masina: ";
    in>>this->pret;
    cout<<"Cand a aparut masina: ";
    in>>this->anAparitie;
    cout<<"Ce greutate are masina: ";
    in>>this->greutate;
    cout<<"Ce autonomie are masina: ";
    in>>this->autonomie;
    cout<<"Cate locuri are masina: ";
    in>>this->numarLocuri;

    return in;

}
ostream& Masina::write(ostream& out) const
{
    out<<"Marca masinii este: "<<this->marca<<endl;
    out<<"Modelul masinii este: "<<this->model<<endl;
    out<<"Masina costa: "<<this->pret<<endl;
    out<<"Cand a aparut masina: "<<this->anAparitie<<endl;
    out<<"Ce greutate are masina: "<<this->greutate<<endl;
    out<<"Ce autonomie are masina: "<<this->autonomie<<endl;
    out<<"Cate locuri are masina: "<<this->numarLocuri<<endl;
    return out;
}
Masina::Masina()
{
    this->marca="None";
    this->model="None";
    this->pret=0.0;
    this->anAparitie=0;
    this->greutate=0.0;
    this->autonomie=0;
    this->numarLocuri=0;
}
Masina::Masina(string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri, float autonomie )
{
    this->marca=marca;
    this->model=model;
    this->pret=pret;
    this->anAparitie=anAparitie;
    this->greutate=greutate;
    this->numarLocuri=numarLocuri;
    this->autonomie=autonomie;

}
istream& operator>>(istream& in, Masina& mas)
{
    return mas.read(in);
}
ostream& operator<<(ostream& out, const Masina& mas )
{
    return mas.write(out);
}

class MasinaCuCombustibilFosili: public virtual Masina
{
protected:
    int taxapoluare;
public:

    MasinaCuCombustibilFosili();
    MasinaCuCombustibilFosili(string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri,float autonomie,
                              int taxapoluare);
    friend istream& operator>>(istream& in, MasinaCuCombustibilFosili& mf);
    friend ostream& operator<<(ostream& out, const MasinaCuCombustibilFosili& mf );
    MasinaCuCombustibilFosili& operator=(const MasinaCuCombustibilFosili& mf);
    MasinaCuCombustibilFosili(const MasinaCuCombustibilFosili& mf);

    istream& read(istream& in);
    ostream& write(ostream& out) const;
    void calculpretinfunctiedetaxa( );

    ~MasinaCuCombustibilFosili() {}

};

void MasinaCuCombustibilFosili::calculpretinfunctiedetaxa( )
{
    cout<<"Pretul masinii pe combustibil fosili este: "<<(this->taxapoluare*this->pret)/100+this->pret<<endl;
    cout<<"Autonomia masinii este: "<<this->autonomie+0.2*this->autonomie<< "km"<<endl;
}
MasinaCuCombustibilFosili::MasinaCuCombustibilFosili():Masina()
{
    this->taxapoluare=0;
}
MasinaCuCombustibilFosili::MasinaCuCombustibilFosili(string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri,float autonomie,
        int taxapoluare):Masina(marca,model,pret,anAparitie,greutate, numarLocuri,autonomie)
{
    this->taxapoluare=taxapoluare;
}
MasinaCuCombustibilFosili& MasinaCuCombustibilFosili::operator=(const MasinaCuCombustibilFosili& mf)
{
    if(this!=&mf)
    {
        Masina::operator=(mf);
        this->taxapoluare=mf.taxapoluare;
    }
    return *this;
}
MasinaCuCombustibilFosili::MasinaCuCombustibilFosili(const MasinaCuCombustibilFosili& mf):Masina(mf)
{
    this->taxapoluare=mf.taxapoluare;
}

istream& MasinaCuCombustibilFosili::read(istream& in)
{
    Masina::read(in);
    cout<<"Taxa care se adauga la pret este: ";
    in>>this->taxapoluare;
    return in;
}
ostream& MasinaCuCombustibilFosili::write(ostream& out) const
{
    Masina::write(out);
    out<<"Taxa care se adauga la pret este: "<<this->taxapoluare<<endl;
    return out;
}
istream& operator>>(istream& in, MasinaCuCombustibilFosili& mf)
{
    /* in>>(Masina&)mf;
    cout<<"Taxa care se adauga la pret este: ";
    in>>mf.taxapoluare;
    return in;*/
    return mf.read(in);

}
ostream& operator<<(ostream& out, const MasinaCuCombustibilFosili& mf )
{
    /*out<<(Masina&)mf;
    out<<"Taxa care se adauga la pret este: "<<mf.taxapoluare<<endl;
    return out;*/
    return mf.write(out);

}
class MasinaElectrica: public virtual Masina
{

protected:
    float cupluNewton;
public:
    MasinaElectrica();
    MasinaElectrica(  string marca,string model, double pret, int anAparitie, float greutate, int numarLocuri, float autonomie,
                      float cupluNewton);
    friend istream& operator>>(istream& in, MasinaElectrica& me);
    friend ostream& operator<<(ostream& out, const MasinaElectrica& me );
    MasinaElectrica& operator=(const MasinaElectrica& me);
    MasinaElectrica(const MasinaElectrica& me);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    void calculpretinfunctiedetaxa( );
    float pretcalc(MasinaElectrica& mas);

    ~MasinaElectrica()
    {
    }
};
float MasinaElectrica::pretcalc(MasinaElectrica& mas)
{
    float pret=((90*mas.pret)/100+mas.pret)-0.1*((0.9*mas.pret)/100+mas.pret);
    return pret;
}
void MasinaElectrica::calculpretinfunctiedetaxa( )
{
    cout<<"Pretul masinii pe curent electric este: "<<this->pret-0.2*this->pret<<endl;
    cout<<"Autonomia masinii electrice este: "<<this->autonomie-0.4*this->autonomie<< "km"<<endl;

}
MasinaElectrica::MasinaElectrica():Masina()
{
    this->cupluNewton=0;
}
MasinaElectrica::MasinaElectrica(  string marca,string model, double pret, int anAparitie, float greutate, int numarLocuri,float autonomie,
                                   float cupluNewton):Masina(  marca,   model,   pret,   anAparitie,   greutate,   numarLocuri,autonomie
                                                                )
{
    this->cupluNewton=cupluNewton;
}
MasinaElectrica& MasinaElectrica::operator=(const MasinaElectrica& me)
{
    if(this!=&me)
    {
        Masina::operator=(me);
        this->cupluNewton=me.cupluNewton;
    }
    return *this;
}
MasinaElectrica::MasinaElectrica(const MasinaElectrica& me):Masina(me)
{
    this->cupluNewton=me.cupluNewton;
}

istream& MasinaElectrica::read(istream& in)
{
    Masina::read(in);
    cout<<"Cuplul Newton este: ";
    in>>this->cupluNewton;
    return in;

}
ostream& MasinaElectrica::write(ostream& out) const
{
    Masina::write(out);

    out<<"Cuplul Newton este: "<<this->cupluNewton<<endl;
    return out;
}
istream& operator>>(istream& in, MasinaElectrica& me)
{

    return me.read(in);

}
ostream& operator<<(ostream& out, const MasinaElectrica& me )
{

    return me.write(out);

}


class MasinaHibrida:   public  MasinaCuCombustibilFosili,  public     MasinaElectrica
{
protected:
    float distantaParcursaCuCombustibiliFosili;
    float distantaParcursaCuCurent;
public:
    MasinaHibrida();
    MasinaHibrida( string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri,float autonomie,  int taxapoluare,
                   float cupluNewton,float distantaParcursaCuCombustibiliFosili,float distantaParcursaCuCurent);
    friend istream& operator>>(istream& in, MasinaHibrida& mh);
    friend ostream& operator<<(ostream& out, const MasinaHibrida& mh );
    MasinaHibrida& operator=(const MasinaHibrida& mh);
    MasinaHibrida(const MasinaHibrida& mh);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    void calculpretinfunctiedetaxa( );
    ~MasinaHibrida() {}

};
MasinaHibrida::MasinaHibrida():Masina(),MasinaCuCombustibilFosili(),MasinaElectrica()
{
    this->distantaParcursaCuCombustibiliFosili=0;
    this->distantaParcursaCuCurent=0;
}
MasinaHibrida::MasinaHibrida( string marca, string model, double pret, int anAparitie, float greutate, int numarLocuri,float autonomie,   int taxapoluare,float cupluNewton,
                              float distantaParcursaCuCombustibiliFosili,float distantaParcursaCuCurent):
    Masina(marca,model,pret,anAparitie, greutate, numarLocuri,autonomie),
    MasinaCuCombustibilFosili(marca,model,pret,anAparitie, greutate, numarLocuri,autonomie,taxapoluare),
    MasinaElectrica(    marca,model,   pret,   anAparitie,   greutate,   numarLocuri,autonomie,
                        cupluNewton)
{
    this->distantaParcursaCuCombustibiliFosili=distantaParcursaCuCombustibiliFosili;
    this->distantaParcursaCuCurent=distantaParcursaCuCurent;
}
MasinaHibrida& MasinaHibrida::operator=(const MasinaHibrida& mh)
{
    if(this!=&mh)
    {
        MasinaCuCombustibilFosili::operator=(mh);
        MasinaElectrica::operator=(mh);
        this->distantaParcursaCuCombustibiliFosili=mh.distantaParcursaCuCombustibiliFosili;
        this->distantaParcursaCuCurent=mh.distantaParcursaCuCurent;
    }
    return *this;
}
MasinaHibrida::MasinaHibrida(const MasinaHibrida& mh):Masina(mh),MasinaCuCombustibilFosili(mh),MasinaElectrica(mh)
{
    this->distantaParcursaCuCombustibiliFosili=mh.distantaParcursaCuCombustibiliFosili;
    this->distantaParcursaCuCurent=mh.distantaParcursaCuCurent;
}
istream& MasinaHibrida::read(istream& in)
{
    Masina::read(in);
    cout<<"Taxa care se adauga la pret este: ";
    in>>this->taxapoluare;
    cout<<"Cuplul Newton este: ";
    in>>this->cupluNewton;
    cout<<"Distanta pe care o poti parcurge cu combustibil fosil este: ";
    in>>this->distantaParcursaCuCombustibiliFosili;
    cout<<"Distanta pe care o poti parcurge cu curent este: ";
    in>>this->distantaParcursaCuCurent;
    return in;

}
ostream& MasinaHibrida::write(ostream& out) const
{
    Masina::write(out);
    out<<"Taxa care se adauga la pret este: "<<this->taxapoluare<<endl;
    out<<"Cuplul Newton este: "<<this->cupluNewton<<endl;
    out<<"Distanta pe care o poti parcurge cu combustibil fosil este: "<<this->distantaParcursaCuCombustibiliFosili<<endl;
    out<<"Distanta pe care o poti parcurge cu curent este: "<<this->distantaParcursaCuCurent<<endl;
    return out;

}
void MasinaHibrida::calculpretinfunctiedetaxa( )
{

    cout<<"Pretul masinii hibrid este: "<<((this->taxapoluare*this->pret)/100+this->pret)-0.1*this->pret<<endl;
    cout<<"Autonomia masinii este: "<<this->distantaParcursaCuCombustibiliFosili+distantaParcursaCuCombustibiliFosili*0.1+0.1*this->distantaParcursaCuCurent+distantaParcursaCuCurent<< "km"<<endl;

}
istream& operator>>(istream& in, MasinaHibrida& mh)
{
    return mh.read(in);
}
ostream& operator<<(ostream& out, const MasinaHibrida& mh )
{
    return mh.write(out);
}
class Reprezentanta
{
private:
    string nume;
    const int idReprezentanta;
    static int contorId;
    string locatie;
    int numarModele;
    set <string> modeleDeMasini;
public:
    Reprezentanta();
    Reprezentanta(string nume, string locatie, int numarModele,set <string> modeleDeMasini);
    friend istream& operator>>(istream& in, Reprezentanta& ser);
    friend ostream& operator<<(ostream& out, const Reprezentanta& ser );
    Reprezentanta& operator=(const Reprezentanta& ser);
    Reprezentanta(const Reprezentanta& ser);
    void  LocatiaReprezentanteiCareAreModelulDeMasinaDorit(const Reprezentanta& rep,string model);
    bool operator<(const Reprezentanta& rep);
    int getnumarModele()
    {
        return this->numarModele;
    }

    ~Reprezentanta();

};
bool Reprezentanta::operator<(const Reprezentanta& rep)
{
    if(this->numarModele< rep.numarModele)
    {
        //cout<<*this<<endl<<rep<<endl;

        return true;
    }
    return false;

}

void  Reprezentanta::LocatiaReprezentanteiCareAreModelulDeMasinaDorit(const Reprezentanta& rep, string model)
{
    bool ok=0;
    set<string >::iterator it ;
    for (it = rep.modeleDeMasini.begin() ; it != rep.modeleDeMasini.end() ; it++ )
        if((*it)==model)
            cout<<rep.locatie<<endl,ok=1;
    if(ok==0)
        cout<< "Neexistent"<<endl;

}
int Reprezentanta::contorId=0;
Reprezentanta::Reprezentanta():idReprezentanta(++contorId)
{
    this->nume="None";
    this->locatie="None";
    this-> numarModele=0;
    this-> modeleDeMasini= {};

}

Reprezentanta::Reprezentanta(string nume, string locatie, int numarModele, set <string> modeleDeMasini):idReprezentanta(++contorId)
{
    this->nume=nume;
    this->locatie=locatie;
    this-> numarModele=numarModele;
    this->modeleDeMasini=modeleDeMasini;

}
Reprezentanta::~Reprezentanta()
{
}

istream& operator>>(istream& in, Reprezentanta& ser)
{
    cout<<"Reprezentanta se numeste: ";

    in>>ser.nume;

    cout<<"Locatia este: ";
    in>>ser.locatie;
    cout<<"Cate modele de masini sunt: ";

    in>>ser.numarModele;
    cout<<"Acestea sunt: "<<endl;

    for(int i=0; i<ser.numarModele; i++)
    {
        string s;
        in>>s;
        ser.modeleDeMasini.insert(s);


    }

    //ser.numarModele=ser.modeleDeMasini.size();

    return in;
}
ostream& operator<<(ostream& out, const Reprezentanta& ser )
{
    out<<"Reprezentanta se numeste: "<<ser.nume<<endl;
    out<<"Locatia unde este reprezentanta se afla la adresa: "<<ser.locatie<<endl;
    out<<"Cate modele de masini sunt:  "<<ser.numarModele<<endl;
    out<<"Acestea sunt: "<<endl;
    set<string >::iterator it ;
    for (it = ser.modeleDeMasini.begin() ; it != ser.modeleDeMasini.end() ; it++ )
    {
        out<<*it;
        out<<endl;
    }

    return out;
}
Reprezentanta& Reprezentanta::operator=(const Reprezentanta& ser)
{
    if(this!=&ser)
    {

        this->nume=ser.nume;
        this->locatie=ser.locatie;
        this->numarModele=ser.numarModele;

        this->modeleDeMasini=ser.modeleDeMasini;
    }
    return *this;
}
Reprezentanta::Reprezentanta(const Reprezentanta& ser):idReprezentanta(contorId)
{
    this->nume=ser.nume;
    this->locatie=ser.locatie;
    this->numarModele=ser.numarModele;
    this->modeleDeMasini=ser.modeleDeMasini;
}
int nrmasinicucombfosil, nrmasinielectr,nrmasinihib;
arr <MasinaCuCombustibilFosili> VectorcuMasinacucom(100);
arr <MasinaElectrica> VectorcuMasinaelect(100);
arr <MasinaHibrida> VectorcuMasinahibrid(100);

template <class T>
T maxim(list<T> a)
{
    int ok;

    typename std::list<T>::iterator i;
    i = a.begin();
    T mn;

    while (i != a.end())
    {
        if(!(*i<mn))
            mn=*i;
        advance(i, 1);
    }
    cout<<mn;


}
template <class T>
T minim(list<T> a)
{
    int ok;

    typename std::list<T>::iterator i;
    i = a.begin();
    T mn;

    while (i != a.end())
    {
        if(*i<mn)
            mn=*i;
        advance(i, 1);
    }
    cout<<mn;


}
class MeniuInteractiv
{
private:
    static MeniuInteractiv *obiect;
    MeniuInteractiv() {}
    MeniuInteractiv& operator=(const MeniuInteractiv& meniu)=delete;
    //~MeniuInteractiv()=delete;
public:
    static MeniuInteractiv* getInstance()
    {
        if(!obiect)
            obiect=new MeniuInteractiv();


        return obiect;
    }
    static MeniuInteractiv* deletemeniu()
    {
        if(obiect!=0)
            delete [] obiect;
    }
    void meniu()
    {
        list <Reprezentanta> listaReprezentate;
        vector<Masina*> listaMasini;
        vector<Masina*> listaMasiniDownCasting;
        int k=1,comanada;
        while(k==1)
        {
            cout<<"1-Adaugare Reprezentanta\n2-Adaugare Masina\n3-Stop\n";
            cin>>comanada;
            switch(comanada)
            {
            case 1:
            {
                int t=1, comandasub;
                try
                {
                    Reprezentanta a;

                    cin>>a;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        throw "eror";

                    }
                    else listaReprezentate.push_back(a);
                }
                catch(...)
                {
                    cout<<endl;
                    cout<<"Eroare la citire(date introduse incorect) RECITITI\n";
                }

                while(t==1)
                {
                    cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toate reprezentantele\n5-Verificati daca modelul de masina se afla in reprezentanta\n6-Reprezentanta cu numarul maxim de masine\n7-Reprezentanta cu numarul minim de masini\n";
                    cin>>comandasub;

                    switch(comandasub)
                    {
                    case 1:
                    {
                        Reprezentanta b;
                        cin>>b;
                        cout<<"Introduceti numarul pentru ce reprezentanta doriti sa faceti update-ul: ";
                        int index;
                        cin>>index;
                        int it=0;
                        int ok=0;
                        list<Reprezentanta>::iterator i;
                        i = listaReprezentate.begin();
                        while (i != listaReprezentate.end())
                        {
                            if(it== index)
                            {
                                *i=b;
                                ok=1;
                            }

                            advance(i, 1);
                            it++;
                        }
                        try
                        {
                            if(ok==0)
                                throw    std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            break;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }
                        break;
                    }
                    case 2:
                    {
                        cout<<"Introduceti numarul pentru ce reprezentanta doriti sa faceti stergerea: ";
                        int index;
                        cin>>index;
                        int it=0;
                        int ok=0;
                        list<Reprezentanta>::iterator i;
                        i = listaReprezentate.begin();
                        while (i != listaReprezentate.end())
                        {
                            if(it== index)
                            {
                                listaReprezentate.erase(i);
                                ok=1;
                                break;
                            }

                            advance(i, 1);
                            it++;
                        }
                        try
                        {
                            if(ok==0)
                                throw    std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            break;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }
                        break;
                    }
                    case 3:
                    {
                        t=0;
                        break;
                    }
                    case 4:
                    {
                        list<Reprezentanta>::iterator i;
                        i = listaReprezentate.begin();
                        while (i != listaReprezentate.end())
                        {
                            cout << (*i)<<endl;
                            advance(i, 1);
                        }


                        break;
                    }
                    case 5:
                    {
                        cout<<"Scrieti modelul dorit: ";
                        string s;
                        cin>>s;
                        list<Reprezentanta>::iterator i;
                        i = listaReprezentate.begin();
                        while (i != listaReprezentate.end())
                        {
                            cout<<"Modelul dorit se afla la locatia: ";
                            (*i).LocatiaReprezentanteiCareAreModelulDeMasinaDorit(*i,s);
                            advance(i, 1);
                        }
                        /* for(int i=0; i<listaReprezentate.size(); i++)
                         {
                             cout<<"Modelul dorit se afla la locatia: ";
                             listaReprezentate[i].LocatiaReprezentanteiCareAreModelulDeMasinaDorit(listaReprezentate[i],s);
                         }*/
                        break;
                    }
                    case 6:
                    {
                        maxim<Reprezentanta>(listaReprezentate);
                        break;
                    }
                    case 7:
                    {
                        minim<Reprezentanta>(listaReprezentate);
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

                int tip,t=1;
                while(t==1)
                {
                    cout<<"1-Adauga masina cu combustibili fosili\n2-Adauga masina electrica\n3-Adauga masina hibrida\n4-Meniu\n5-Afiseaza toate masinile\n6-Update\n7-Delete\n8-Calculeaza pret\n9-Calculeaza pret pentru masina vintage\n10-Aduna doua masini\n11-Afiseaza masini dupa categorie\n12-Grupare masini dupa model si afisare cate sunt\n13-Introducere masina downcasting:\n";
                    cin>>tip;
                    switch(tip)
                    {
                    case 1:
                    {



                        try
                        {
                            MasinaCuCombustibilFosili a;

                            cin>>a;
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                throw "eror";

                            }
                            else
                            {
                                listaMasini.push_back(new MasinaCuCombustibilFosili(a));
                                VectorcuMasinacucom.setarr(nrmasinicucombfosil++,a);
                            }
                        }
                        catch(...)
                        {
                            cout<<endl;
                            cout<<"Eroare la citire(date introduse incorect) RECITITI\n";

                        }


                        break;
                    }
                    case 2:
                    {
                        try
                        {
                            MasinaElectrica a;

                            cin>>a;
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                throw "eror";

                            }
                            else listaMasini.push_back(new MasinaElectrica(a)),VectorcuMasinaelect.setarr(nrmasinielectr++,a);
                        }
                        catch(...)
                        {
                            cout<<endl;
                            cout<<"Eroare la citire(date introduse incorect) RECITITI\n";
                        }
                        break;
                    }
                    case 3:
                    {
                        try
                        {
                            MasinaHibrida a;

                            cin>>a;
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                throw "eror";

                            }
                            else listaMasini.push_back(new MasinaHibrida(a)),VectorcuMasinahibrid.setarr(nrmasinihib++,a);
                        }
                        catch(...)
                        {
                            cout<<endl;
                            cout<<"Eroare la citire(date introduse incorect) RECITITI\n";
                        }
                        break;
                    }
                    case 4:
                    {
                        t=0;
                        break;
                    }
                    case 5:
                    {
                        for(int i=0; i<listaMasini.size(); i++)
                            cout<<*listaMasini[i];
                        break;
                    }
                    case 6:
                    {
                        cout<<"Introduceti numarul pentru care doriti sa se faca update-ul: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasini.size())
                                delete listaMasini[nr];
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            break;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }


                        cout<<"Cu ce tip de masina doriti sa inlocuiti?\n1-Cu masina cu combustibili fosili\n2-Cu masina electrica\n3-Cu masina hibrida\n";
                        int tip;
                        cin>>tip;
                        switch(tip)
                        {
                        case 1:
                        {
                            MasinaCuCombustibilFosili a;
                            cin>>a;
                            listaMasini[nr]=new MasinaCuCombustibilFosili(a);
                            break;

                        }
                        case 2:
                        {
                            MasinaElectrica a;
                            cin>>a;
                            listaMasini[nr]=new MasinaElectrica(a);
                            break;

                        }
                        case 3:
                        {
                            MasinaHibrida a;
                            cin>>a;
                            listaMasini[nr]=new MasinaHibrida(a);
                            break;
                        }

                        }
                        break;
                    }
                    case 7:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa o stergeti: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasini.size())
                                listaMasini.erase(listaMasini.begin()+nr);
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }

                        break;

                    }
                    case 8:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa calculati pretul: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasini.size())
                                listaMasini[nr]->calculpretinfunctiedetaxa();
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }
                        break;
                    }
                    case 9:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa calculati pretul: ";
                        int nr;
                        cin>>nr;
                        try
                        {

                            MasinaElectrica& b=dynamic_cast<MasinaElectrica&>(*listaMasini[nr]);
                            cout<<"Pretul pentru o masina cu combustibili fosili vintage este: "<<b.pretcalc(b)<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }

                        break;
                    }
                    case 10:

                    {
                        int index1,index2;
                        //VectorcuMasinacucom.getarr(nrmasinicucombfosil);
                        //VectorcuMasinaelect.getarr(nrmasinielectr);

                        int tp,adun=1;
                        while(adun==1)
                        {
                            cout<<"Introduceti:\n1-Pentru a alege o masina cu combustibil fosil\n2-Pentru a alege o masina electrica\n3-Pentru a alege o masina hibrida\n4-Stop\n";

                            cin>>tp;

                            if(tp==1)
                            {
                                cout<<"Introduceti numarul primei masini: ";
                                cin>>index1;
                                cout<<"Introduceti:\n1-Pentru a alege o masina cu combustibil fosil\n2-Pentru a alege o masina electrica\n3Pentru a alege o masina hibrida\n";
                                cin>>tp;

                                if(tp==1)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinacucom[index1]+VectorcuMasinacucom[index2]<<endl;

                                }
                                else if(tp==2)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinacucom[index1]+VectorcuMasinaelect[index2]<<endl;


                                }
                                else
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinacucom[index1]+VectorcuMasinahibrid[index2]<<endl;

                                }
                            }
                            else if(tp==2)
                            {
                                cout<<"Introduceti numarul primei masini: ";
                                cin>>index1;
                                cout<<"Introduceti:\n1-Pentru a alege o masina cu combustibil fosil\n2-Pentru a alege o masina electrica\n3Pentru a alege o masina hibrida\n";
                                cin>>tp;

                                if(tp==1)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinaelect[index1]+VectorcuMasinacucom[index2]<<endl;

                                }
                                else if(tp==2)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinaelect[index1]+VectorcuMasinaelect[index2]<<endl;


                                }
                                else
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinaelect[index1]+VectorcuMasinahibrid[index2]<<endl;

                                }

                            }
                            else if(tp==3)
                            {
                                cout<<"Introduceti numarul primei masini: ";
                                cin>>index1;
                                cout<<"Introduceti:\n1-Pentru a alege o masina cu combustibil fosil\n2-Pentru a alege o masina electrica\n3Pentru a alege o masina hibrida\n";
                                cin>>tp;

                                if(tp==1)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinahibrid[index1]+VectorcuMasinacucom[index2]<<endl;

                                }
                                else if(tp==2)
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinahibrid[index1]+VectorcuMasinaelect[index2]<<endl;


                                }
                                else
                                {
                                    cout<<"Introduceti numarul pentru a doua masina: ";
                                    cin>>index2;
                                    cout<<VectorcuMasinahibrid[index1]+VectorcuMasinahibrid[index2]<<endl;

                                }

                            }
                            else if(tp==4)
                            {
                                adun=0;

                            }
                            else
                            {
                                cout<<"Valoare gresita\n";
                            }
                        }





                        break;
                    }
                    case 11:
                    {
                        int tp,ls=1;
                        while(ls)
                        {
                            cout<<"Introduceti:\n1-Pentru a afisa doar masini cu combustibil fosil\n2-Pentru a afisa doar masini electrice\n3-Pentru a afisa doar masini hibride\n4-Stop\n";
                            cin>>tp;
                            if(tp==1)

                                VectorcuMasinacucom.getarr(nrmasinicucombfosil);

                            else if(tp==2)
                                VectorcuMasinaelect.getarr(nrmasinielectr);
                            else if(tp==3)
                                VectorcuMasinahibrid.getarr(nrmasinihib);
                            else if(tp==4)
                                ls=0;
                            else
                            {
                                cout<<"Valoare gresita\n";
                            }

                        }
                        break;
                    }
                    case 12:
                    {
                        int tp,ls=1;
                        while(ls)
                        {
                            cout<<"Introduceti:\n1-Pentru a afisa cate masini cu combustibil fosil exista\n2-Pentru a afisa cate masini electrice exista\n3-Pentru a afisa cate masini hibride exista\n4-Stop\n";
                            cin>>tp;
                            if(tp==1)
                            {
                                map<string, int> numara;
                                for(int i=0; i<nrmasinicucombfosil; i++)
                                    numara[VectorcuMasinacucom[i].getmodel()]++;

                                map<string, int>::iterator itr;
                                for (itr = numara.begin(); itr != numara.end(); ++itr)
                                {
                                    cout << " "<< itr->first << " "<< itr->second
                                         << '\n';
                                }
                            }


                            else if(tp==2)
                            {
                                map<string, int> numara;
                                for(int i=0; i<nrmasinielectr; i++)
                                    numara[VectorcuMasinaelect[i].getmodel()]++;

                                map<string, int>::iterator itr;
                                for (itr = numara.begin(); itr != numara.end(); ++itr)
                                {
                                    cout << " "<< itr->first << " "<< itr->second
                                         << '\n';
                                }
                            }


                            else if(tp==3)
                            {
                                map<string, int> numara;
                                for(int i=0; i<nrmasinihib; i++)
                                    numara[VectorcuMasinahibrid[i].getmodel()]++;

                                map<string, int>::iterator itr;
                                for (itr = numara.begin(); itr != numara.end(); ++itr)
                                {
                                    cout << " "<< itr->first << " "<< itr->second
                                         << '\n';
                                }
                            }

                            else if(tp==4)
                                ls=0;
                            else
                            {
                                cout<<"Valoare gresita\n";
                            }

                        }

                        break;
                    }
                    case 13:
                    {

                        int l=1,cmd;
                        while(l)
                        {
                            cout<<"1-Adauga masina cu combustibili fosili\n2-Adauga masina electrica\n3-Adauga masina hibrida\n4-Meniu\n5-Afiseaza masini\n5-Afiseaza toate masinile\n6-Update\n7-Delete\n8-Calculeaza pret\n9-Calculeaza pret pentru masina vintage\n";
                            cin>>cmd;
                            switch(cmd)
                            {
                            case 1:
                            {
                                Masina* mas=new MasinaCuCombustibilFosili;
                                cin>>dynamic_cast<MasinaCuCombustibilFosili&>(*mas);
                                listaMasiniDownCasting.push_back(mas);
                                break;

                            }
                            case 2:
                            {
                                Masina* mas=new MasinaElectrica;
                                cin>>dynamic_cast<MasinaElectrica&>(*mas);
                                listaMasiniDownCasting.push_back(mas);

                                break;
                            }
                            case 3:
                            {
                                Masina* mas=new MasinaHibrida;
                                cin>>dynamic_cast<MasinaHibrida&>(*mas);
                                listaMasiniDownCasting.push_back(mas);

                                break;
                            }
                            case 4:
                            {
                                l=0;
                                break;
                            }
                            case 5:
                            {
                                for(int i=0; i<listaMasiniDownCasting.size(); i++)
                                    cout<<*listaMasiniDownCasting[i];
                                break;
                            }

                            case 6:
                    {
                        cout<<"Introduceti numarul pentru care doriti sa se faca update-ul: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasiniDownCasting.size())
                                delete listaMasiniDownCasting[nr];
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            break;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }

s
                        cout<<"Cu ce tip de masina doriti sa inlocuiti?\n1-Cu masina cu combustibili fosili\n2-Cu masina electrica\n3-Cu masina hibrida\n";
                        int tip;
                        cin>>tip;
                        switch(tip)
                        {
                        case 1:
                        {
                            MasinaCuCombustibilFosili a;
                            cin>>a;
                            listaMasiniDownCasting[nr]=new MasinaCuCombustibilFosili(a);
                            break;

                        }
                        case 2:
                        {
                            MasinaElectrica a;
                            cin>>a;
                            listaMasiniDownCasting[nr]=new MasinaElectrica(a);
                            break;

                        }
                        case 3:
                        {
                            MasinaHibrida a;
                            cin>>a;
                            listaMasiniDownCasting[nr]=new MasinaHibrida(a);
                            break;
                        }

                        }
                        break;
                    }
                    case 7:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa o stergeti: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasiniDownCasting.size())
                                listaMasiniDownCasting.erase(listaMasiniDownCasting.begin()+nr);
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }

                        break;

                    }
                    case 8:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa calculati pretul: ";
                        int nr;
                        cin>>nr;
                        try
                        {
                            if(0<=nr && nr<listaMasiniDownCasting.size())
                                listaMasiniDownCasting[nr]->calculpretinfunctiedetaxa();
                            else throw  std::out_of_range("Bad idex");
                            cout<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }
                        break;
                    }
                    case 9:
                    {
                        cout<<"Introduceti numarul masinii pe care doriti sa calculati pretul: ";
                        int nr;
                        cin>>nr;
                        try
                        {

                            MasinaElectrica& b=dynamic_cast<MasinaElectrica&>(*listaMasiniDownCasting[nr]);
                            cout<<"Pretul pentru o masina cu combustibili fosili vintage este: "<<b.pretcalc(b)<<endl;
                        }
                        catch(exception &e)
                        {

                            cout<<e.what();
                            cout<<endl;
                            //cout<<"\nAm prins exceptie de runTime\n";

                        }

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
                k=0;
                break;
            }
            default:
            {
                cout<<"Ati introdus o valoare gresita\n";
                break;
            }
            }
        }

    }
};
MeniuInteractiv* MeniuInteractiv::obiect=0;

int main()
{
     MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
     meniulMeu->meniu();

   // Masina *a=new MasinaHibrida;

    //cin>>dynamic_cast<MasinaHibrida&>(*a);



    return 0;
}




