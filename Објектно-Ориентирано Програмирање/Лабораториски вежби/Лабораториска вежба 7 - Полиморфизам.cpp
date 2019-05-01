/*
Возило Problem 1 (0 / 0)
Да се дефинира класа Vozilo која ќе содржи информација за неговата маса (децимален број), ширина и висина (цели броеви).

Од оваа класа да се изведе класата Автомобил во која како дополнителна информација се чува информацијата за бројот на врати (цел број).

Од класата возило да се изведе и класата Автобус во која се чуваат информации и за бројот на патници кои може да ги пренесува.

Од класата возило да се изведе класата Камион во која се чуваат информации и за максималната маса која може да се товари на него (децимална вредност).

За сите класи да се креираат погодни контруктори, како и set и get функции.

Да се дефинира класа ParkingPlac за која се чува динамичко алоцирано поле од покажувачи кон Vozilo, како и бројот на елементи во полето. Во оваа класа да се дефинираат:

конструктор
деструктор
операторот += за додавање на ново возило (аргументот е покажувач кон Vozilo)
функција float presmetajVkupnaMasa() со која се пресметува вкупната маса на сите возила во паркинг плацот
функција int brojVozilaPoshirokiOd(int l) со која се пресметува бројот на возила кои се пошироки од дадената вредност
функција void pecati() со која се печати: Broot na avtomobili e X, brojot na avtobusi e Y i brojot na kamioni e Z.
функција int pogolemaNosivostOd(Vozilo& v) во која се враќа бројот на сите камиони кои имаат носивост поголема од масата на возилото предадено како аргумент.
Да се дефинира виртуелна функција int vratiDnevnaCena() во класата Vozilo и истата да се преоптовари во сите изведени класи. За секој автомобил со помалку од 5 врати дневната цена е 100, а инаку е 130 денари. За секој камион цената се пресметува со формулата: (masa+nosivost)*0.02. За секој автобус цената е 5 денати по лице кое може да се пренесува.

Во класата ParkingPlac да се додаде следната функција: - функција int vratiDnevnaZarabotka() со која се враќа дневната заработка од сите возила на паркингот.

Sample input
5
1 1300 3 2 3
2 4500 10 4 45
3 6000 8 5 2000
1 2100 3 3 5
2 4200 9 5 52

Sample output:
Broot na avtomobili e 2, brojot na avtobusi e 2 i brojot na kamioni e 1.

Zarabotkata e 875
Vkupnata masa e 18100
Brojot poshiroki od 5 e 3
Brojot na kamioni so nosivost pogolema od avtomobilot e 1
*/

#include <iostream>
#include <string.h>
using namespace std;
 
 
class Vozilo{
protected:
    double masa;
    int sirina,visina;
public:
    Vozilo(){}
    Vozilo(double m,int s,int v){
        masa=m;
        sirina=s;
        visina=v;
    }
    double get_masa(){return masa;}
    int get_sirina(){ return sirina;}
    int get_visina(){ return visina;}
    void set_masa(double m){ masa=m;}
    void set_sirina(int s){ sirina=s;}
    void set_visina(int v){ visina=v;}
 
    virtual int vratiDnevnaCena()=0;};
 
class Avtobus:public Vozilo{
protected:
    double broj_patnici;
public:
    Avtobus(){}
    Avtobus(double m,int s,int v,double b)
    :Vozilo(m,s,v){ broj_patnici=b;}
    double get_broj_patnici(){ return broj_patnici;}
    int vratiDnevnaCena()    {
        return broj_patnici*5;
    }
};
 
class Avtomobil:public Vozilo{
protected:
    int broj_vrati;
public:
    Avtomobil(){}
    Avtomobil(double m,int s,int v,int b)
    :Vozilo(m,s,v){ broj_vrati=b;}
    int get_broj_vrati(){ return broj_vrati;}
 
    int vratiDnevnaCena(){
        if(broj_vrati<5)
            return 100;
        return 130;
    }
};
 
class Kamion: public Vozilo{
protected:
    double maks_tezina;
public:
    Kamion(){}
    Kamion(double m,int s,int v,double mt)
    :Vozilo(m,s,v){ maks_tezina=mt;}
    double get_maks_tezina(){ return maks_tezina;}
    int vratiDnevnaCena()    {
        return (masa+maks_tezina)*0.02;
    }
};
 
class ParkingPlac{
private:
    Vozilo **v;
    int broj;
public:
    ParkingPlac(){
        v=new Vozilo*[100];
        broj=0;
    }
    ParkingPlac(Vozilo **vv, int b){
        broj=b;
        v=new Vozilo*[broj];
        for(int i=0;i<broj;i++)
            v[i]=vv[i];
    }
    ~ParkingPlac(){
        for(int i=0;i<broj;i++)
            delete v[i];
    }
    ParkingPlac &operator+=(Vozilo *v1){
        v[broj++]=v1;
        return *this;
    }
    float presmetajVkupnaMasa(){
        float n=0.0;
        for(int i=0;i<broj;i++)
            n+=v[i]->get_masa();
        return n;
    }
    float brojVozilaPoshirokiOd(int n){
        int c=0;
        for(int i=0;i<broj;i++)
            if(v[i]->get_sirina()>n)
                c++;
        return c;
    }
    int vratiDnevnaZarabotka(){
        int c=0;
        for(int i=0;i<broj;i++)
            c+=v[i]->vratiDnevnaCena();
        return c;
    }
    void pecati(){
            int x=0,y=0,z=0;
            for(int i=0;i<broj;i++){
                Avtomobil *a=dynamic_cast<Avtomobil*>(v[i]);
                if(a!=0)
                    x++;
                Avtobus *s=dynamic_cast<Avtobus*>(v[i]);
                if(s!=0)
                    y++;
                Kamion *b=dynamic_cast<Kamion*>(v[i]);
                if(b!=0)
                    z++;
            }
            cout << "Broot na avtomobili e "<< x <<", brojot na avtobusi e "<<y<<" i brojot na kamioni e "<<z<<"."<<endl;
        }
    int pogolemaNosivostOd(Vozilo& m){
        int c=0;
        for(int i=0;i<broj;i++){
            Kamion *b=dynamic_cast<Kamion*>(v[i]);
                if(b!=0)
                    if(m.get_masa()<v[i]->get_masa())
                        c++;
        }
        return c;
    }
 
};
 
 
int main(){
    ParkingPlac p;
 
    int n;
    cin>>n;
    int shirina,visina, broj;
    float masa,nosivost;
    for (int i=0;i<n;i++){
        int type;
        cin>>type;
        if(type==1){
            cin>>masa>>shirina>>visina>>broj;
            Avtomobil *a=new Avtomobil(masa,shirina,visina,broj);
            p+=a;
        }
        if(type==2){
            cin>>masa>>shirina>>visina>>broj;
            p+=new Avtobus(masa,shirina,visina,broj);
        }
        if(type==3){
            cin>>masa>>shirina>>visina>>nosivost;
            p+=new Kamion(masa,shirina,visina,nosivost);
        }
    }
    p.pecati();
 
    cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
    cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
    cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
    Avtomobil a(1200,4,3,5);
    cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl;
    return 0;
}