#include<iostream>
#include<string.h>
using namespace std;

class Zichara {
private:
    char *name;
    int price;

public:
    Zichara(const char *name = "", int price = 0) {
        this->name = new char[strlen(name) + 1];
        this->price = price;
    }
    Zichara(const Zichara &from) {
        name = new char[strlen(from.name) + 1];
        price = from.price;
    }
    Zichara& operator = (const Zichara &from) {
    	if(this == &from) return *this;
        delete [] name;
        name = new char[strlen(from.name) + 1];
        price = from.price;
        return *this;
    }
    ~Zichara() {
        delete [] name;
    }

    int getPrice() {
        return price;
    }
};

class PlaninarskiDom {
private:
    char name[15];
    int prices[2];
    char star;
    bool isZichara;
    Zichara *zich;

public:
    PlaninarskiDom() {}
    PlaninarskiDom(const char *nm, int prices[], char klasa) {
        strcpy(name, nm);
        this->star = klasa;
        this->prices[0] = prices[0];
        this->prices[1] = prices[1];
        isZichara = 0;
        zich = 0;
    }
    PlaninarskiDom(const PlaninarskiDom &from) {
        strcpy(name, from.name);
        star = from.star;
        isZichara = from.isZichara;
        for(int i = 0; i < 2; i++) {
            prices[i] = from.prices[i];
        }
        zich = new Zichara(*from.zich);
    }

    void setZichara(Zichara &z) {
        if(isZichara == 0) {
            zich = new Zichara(z);
            isZichara = 1;
        }
    }

    void presmetajDnevenPrestoj(int day, int month, int &price) {
        if(day < 0 || day > 31 || month < 0 || month > 12) {
            throw 99;
        }
        else if(month >= 4&&month <= 8) {
            price = prices[0];
        }
        else {
            price = prices[1];
        }
        if(isZichara) {
            price += zich->getPrice();
        }
    }
    void operator --() {
        if((int)star >= 65&&(int)star <= 70) {
            ++star;
            if((int)star == 69) {
                ++star;
            }
            if((int)star == 71) {
                --star;
            }
        }
    }

    bool operator <= (char c) {
        return star >= c;
    }

    ~PlaninarskiDom() {
    }
    friend ostream& operator << (ostream &, const PlaninarskiDom &);
};

ostream& operator << (ostream &os, const PlaninarskiDom &rhs) {
    if(rhs.isZichara) {
        cout << rhs.name << " klasa:" << rhs.star << " so Zichara" << endl;
    }
    else if(!(rhs.isZichara)) {
        cout << rhs.name << " klasa:" << rhs.star << endl;
    }
    return os;
}

int main(){

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15],mestoZichara[30],klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin>>imePlaninarskiDom;
    for (int i=0;i<2;i++) cin>>ceni[i];
    cin>>klasa;
    cin>>daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin>>mestoZichara>>dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
        Zichara r(mestoZichara,dnevnakartaZichara);
        pom.setZichara(r);
        p=pom;
    }
    else{
        PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
        p=*pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den,mesec;
    cin>>den>>mesec;
    try{
        p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout<<"Informacii za PlaninarskiDomot:"<<endl;
        cout<<p;
        if (p<='D')
            cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
    }
    catch (int){
        cout<<"Mesecot ili denot e greshno vnesen!";
    }
}


