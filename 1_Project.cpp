#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class IOInterface
{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0 ;
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
    virtual void calculpretinfunctiedetaxa()=0;
    ~Masina()
    {

    }

};

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

    ~MasinaElectrica()
    {
    }
};
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
    string* modeleDeMasini;
public:
    Reprezentanta();
    Reprezentanta(string nume, string locatie, int numarModele,string* modeleDeMasini);
    friend istream& operator>>(istream& in, Reprezentanta& ser);
    friend ostream& operator<<(ostream& out, const Reprezentanta& ser );
    Reprezentanta& operator=(const Reprezentanta& ser);
    Reprezentanta(const Reprezentanta& ser);
    void  LocatiaReprezentanteiCareAreModelulDeMasinaDorit(const Reprezentanta& rep,string model);
    ~Reprezentanta();

};
void  Reprezentanta::LocatiaReprezentanteiCareAreModelulDeMasinaDorit(const Reprezentanta& rep, string model)
{
    bool ok=0;
    for(int i=0; i<rep.numarModele; i++)
        if(rep.modeleDeMasini[i]==model)
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
    this-> modeleDeMasini=NULL;
}

Reprezentanta::Reprezentanta(string nume, string locatie, int numarModele, string* modeleDeMasini):idReprezentanta(++contorId)
{
    this->nume=nume;
    this->locatie=locatie;
    this-> numarModele=numarModele;
    this->modeleDeMasini=new string[numarModele];
    for(int i=0; i<numarModele; i++)
        this->modeleDeMasini[i]=modeleDeMasini[i];
}
Reprezentanta::~Reprezentanta()
{
    if(this->modeleDeMasini!=NULL)
        delete [] this->modeleDeMasini;
}

istream& operator>>(istream& in, Reprezentanta& ser)
{
    cout<<"Reprezentanta se numeste: ";

    in>>ser.nume;

    cout<<"Locatia este: ";
    in>>ser.locatie;
    cout<<"Cate modele de masini sunt: ";
    if(ser.modeleDeMasini!=NULL)
        delete [] ser.modeleDeMasini;
    in>>ser.numarModele;
    cout<<"Acestea sunt: "<<endl;
    ser.modeleDeMasini=new string[ser.numarModele];
    for(int i=0; i<ser.numarModele; i++)
        in>>ser.modeleDeMasini[i];

    return in;
}
ostream& operator<<(ostream& out, const Reprezentanta& ser )
{
    out<<"Reprezentanta se numeste: "<<ser.nume<<endl;
    out<<"Locatia unde este reprezentanta se afla la adresa: "<<ser.locatie<<endl;
    out<<"Cate modele de masini sunt:  "<<ser.numarModele<<endl;
    out<<"Acestea sunt: "<<endl;
    for(int i=0; i<ser.numarModele; i++)
    {
        out<<ser.modeleDeMasini[i];
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
        if(this->modeleDeMasini!=NULL)
            delete [] this->modeleDeMasini;

        this->modeleDeMasini=new string[ser.numarModele];
        for(int i=0; i<ser.numarModele; i++)
            this->modeleDeMasini[i]=ser.modeleDeMasini[i];
    }
    return *this;
}
Reprezentanta::Reprezentanta(const Reprezentanta& ser):idReprezentanta(contorId)
{
    this->nume=ser.nume;
    this->locatie=ser.locatie;
    this->numarModele=ser.numarModele;
    this->modeleDeMasini=new string[ser.numarModele];
    for(int i=0; i<ser.numarModele; i++)
        this->modeleDeMasini[i]=ser.modeleDeMasini[i];
}

int main()
{

    vector <Reprezentanta> listaReprezentate;
    vector<Masina*> listaMasini;
    int k=1,comanada;
    while(k==1)
    {
        cout<<"1-Adaugare Reprezentanta\n2-Adaugare Masina\n3-Stop\n";
        cin>>comanada;
        switch(comanada)
        {
        case 1:
        {
            Reprezentanta a;
            cin>>a;
            listaReprezentate.push_back(a);
            int t=1, comandasub;
            while(t==1)
            {
                cout<<"1-Update\n2-Delete\n3-Meniu\n4-Afisare toate reprezentantele\n5-Verificati daca modelul de masina se afla in reprezentanta\n";
                cin>>comandasub;

                switch(comandasub)
                {
                case 1:
                {
                    Reprezentanta b;
                    cin>>b;
                    cout<<"Introduceti numarul pentru ce reprezentanta doriti sa faceti update-ul: ";
                    int care;
                    cin>>care;
                    listaReprezentate[care]=b;
                    break;
                }
                case 2:
                {
                    cout<<"Introduceti numarul pentru ce reprezentanta doriti sa faceti stergerea: ";
                    int i;
                    cin>>i;
                    listaReprezentate.erase(listaReprezentate.begin()+i);
                    break;
                }
                case 3:
                {
                    t=0;
                    break;
                }
                case 4:
                {
                    for(int i=0; i<listaReprezentate.size(); i++)
                        cout<<listaReprezentate[i];
                    break;
                }
                case 5:
                {
                    cout<<"Scrieti modelul dorit: ";
                    string s;
                    cin>>s;
                    for(int i=0; i<listaReprezentate.size(); i++)
                    {
                        cout<<"Modelul dorit se afla la locatia: ";
                        listaReprezentate[i].LocatiaReprezentanteiCareAreModelulDeMasinaDorit(listaReprezentate[i],s);
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
        case 2:
        {

            int tip,t=1;
            while(t==1)
            {
                cout<<"1-Adauga masina cu combustibili fosili\n2-Adauga masina electrica\n3-Adauga masina hibrida\n4-Meniu\n5-Afiseaza toate masinile\n6-Update\n7-Delete\n8-Calculeaza pret\n";
                cin>>tip;
                switch(tip)
                {
                case 1:
                {
                    MasinaCuCombustibilFosili a;
                    cin>>a;
                    listaMasini.push_back(new MasinaCuCombustibilFosili(a));
                    break;
                }
                case 2:
                {
                    MasinaElectrica a;
                    cin>>a;
                    listaMasini.push_back(new MasinaElectrica(a));
                    break;
                }
                case 3:
                {
                    MasinaHibrida a;
                    cin>>a;
                    listaMasini.push_back(new MasinaHibrida(a));
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
                    delete listaMasini[nr];
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
                    listaMasini.erase(listaMasini.begin()+nr);
                    break;

                }
                case 8:
                {
                    cout<<"Introduceti numarul masinii pe care doriti sa calculati pretul: ";
                    int nr;
                    cin>>nr;
                    listaMasini[nr]->calculpretinfunctiedetaxa();
                    cout<<endl;
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




        return 0;

}
