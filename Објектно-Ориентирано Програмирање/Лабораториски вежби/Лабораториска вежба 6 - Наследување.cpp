/* ZADACA 1 */
/*
Недвижнина Problem 1 (0 / 0)
Да се развие класа Nediviznina за коjа се чуваат следниве информации:

адреса (динамички алоцирана низа од знаци)
квадратура (цел боj)
цена за квадрат (цел боj)
За оваа класа да се имплементираат соодветните конструктори и следните методи:

cena() коj ќе jа ваќа цената на недвижнината (квадратура * цена-за-квадрат)
pecati() коj ќе ги испечати сите информации за истата
danokNaImot() коj го ваќа данокот што се плаќа за недвижнината, а истиот се пресметува како 5% од цената на недвижнината.
Од оваа класа да се изведе класа Vila за коjа дополнително се чува данок на луксуз (цел боj, пр. 10%). За оваа класа да се преоптоварат методите:

pecati()
danokNaImot() со тоа што пресметаниот данок се зголемува процентуално за данокот на луксуз.
И за двете класи треба да се преоптовари operator >>.

Sample input:
Kukja_vo_Centar
60
850
Vila_na_Vodno
110
1120
10

Sample output:
Kukja_vo_Centar, Kvadratura: 60, Cena po Kvadrat: 850
Danok za: Kukja_vo_Centar, e: 2550
Vila_na_Vodno, Kvadratura: 110, Cena po Kvadrat: 1120, Danok na luksuz: 10
Danok za: Vila_na_Vodno, e: 18480
*/

#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina{
protected:
    char *adresa;
    int kvadratura;
    int cena;
public:
    Nedviznina(char *a="", int k=0,int c=0){
    adresa=new char[strlen(a)+1];
    strcpy(adresa,a);
    kvadratura=k;
    cena=c;
}
Nedviznina(const Nedviznina &n){
    adresa=new char[strlen(n.adresa)+1];
    strcpy(adresa,n.adresa);
    kvadratura = n.kvadratura;
    cena = n.cena;
}
char *getAdresa(){
	return adresa;
}
int getKvadratura(){
	return kvadratura;
}
int getCena(){
	return cena;
}
~Nedviznina(){
	delete [] adresa;
}
Nedviznina &operator=(const Nedviznina &n){
    if(this!=&n){
        delete [] adresa;
        adresa = new char [strlen(n.adresa)+1];
        strcpy(adresa,n.adresa);
        kvadratura = n.kvadratura;
        cena = n.cena;
    }
    return *this;
}
float cenaN(){
	return kvadratura * cena;
}
float danokNaImot(){
	return kvadratura * cena * 0.05;
}
void pecati(){
	cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cena << endl;
}
friend istream &operator >> (istream &in, Nedviznina &n){
    in >> n.adresa;
    in >> n.kvadratura;
    in >> n.cena;
    return in;
}
};
class Vila: public Nedviznina{
private:
	int danokl;
public:
    Vila(char *a="",int k=0, int c=0, int d=0):Nedviznina(a,k,c){
    danokl=d;
}
float danokNaImot(){
	return Nedviznina::danokNaImot()+(kvadratura*cena*danokl)/100.00;
}
void pecati(){
	cout << adresa << ", Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cena << ", Danok na luksuz: " << danokl << endl;
}
friend istream &operator>>(istream&in,Vila &v){
    in >> v.adresa;
    in >> v.kvadratura;
    in >> v.cena;
    in >> v.danokl;
    return in;
}
};
 
int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}

/* ZADACA 2 */
/*
Спортски екипи Problem 2 (0 / 0)
Да се дефинира класа Ekipa за коjа се чуваат следниве информации:

името на екипата (низа од наjмногу 15 знаци)
броj на порази
броj на победи
За оваа класа да се дефинира метод pecati() коjа ги печати податоците за екипаta. Од оваа класа да се изведe новa класa, FudbalskaEkipa.

За фудбалската екипа дополнително се чуваат информации за:

вкупниот броj на црвени картони
вкупниот броj жолти картони
броjот на нерешени натпревари
За фудбалската екипа да се преоптовари методот pecati(), така што покрај останатите информации, ќе се испечатат и бројот на нерешени резултати и вкупен број на поени во формат: Име на екипа, броj на победи, броj на порази, броj на нерешени натпревари и вкупен броj на поени (за победа фудбалската екипа добива 3 поени, додека за нерешен резултата, 1 поен); 

Sample input:
Fudbaleri
5
4
3
7
6

Sample output:
Ime: Fudbaleri Pobedi: 5 Porazi: 4 Nereseni: 6 Poeni: 21
*/

#include <iostream>
#include <cstring>

using namespace std;

class Ekipa{
protected:
    char ime[15];
    int porazi;
    int pobedi;
public:
    Ekipa(char *i=" ",int por=0,int pob=0){
    strncpy(ime,i,14);
    ime[14]='0';
    porazi = por;
    pobedi = pob;
}
virtual void pecati()=0;
};
class FudbalskaEkipa: public Ekipa{
private:
    int crveni;
    int zolti;
    int nereseni;
public:
    int poeni(){
        int poeni;
        poeni=3*pobedi+1*nereseni;
        return poeni;
}
FudbalskaEkipa(char*i="0",int pob=0,int por=0,int c=0,int z=0, int n=0):
Ekipa(i,por,pob),crveni(c),zolti(z),nereseni(n){}
void pecati(){
	cout << "Ime: " << ime << " Pobedi: " << pobedi << " Porazi: " << porazi << " Nereseni: " << nereseni << " Poeni: " << poeni() << endl;
}
};
class KosarkarskaEkipa : public Ekipa{
private:
    int greski;
    int obidi;
public:
    KosarkarskaEkipa(char *i, int pob, int por, int g, int o):Ekipa(i,por,pob),greski(g),obidi(o){}
    float Uspesnost(){
        float u;
        u=(100*pobedi)/(porazi+pobedi*1.00);
        return u;
}
void pecati(){
	cout << "Ime: " << ime << " Pobedi: " << pobedi << " Porazi: " << porazi << " Licni: " << greski << " Obidi: " << obidi << " Uspesnost: " << Uspesnost() << "%" << endl;
}
};
void statistika(Ekipa **ekipi, int vkupno){
	for(int i=0;i<vkupno;i++){
		(*ekipi[i]).pecati();
	}
}

int main(){
    char ime[15];
    int pob,por,ck,zk,ner;
    cin>>ime>>pob>>por>>ck>>zk>>ner;
    FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
    f1.pecati();
    return 0;
}