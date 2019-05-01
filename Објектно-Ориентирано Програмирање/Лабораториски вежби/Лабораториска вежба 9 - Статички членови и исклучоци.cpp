/*
Сите елементи кои ги превезуваат камионите имаат одредена маса. Имплементирајте апстрактна класа ImaMasa од која што ќе наследуваат сите класи кои имаат маса. Во оваа класа треба да се дефинираат методите:

double vratiMasa() враќа маса изразена во kg
void pecati() печати информации за соодветниот објект
Нека еден камион превезува пијалоци и тоа: пакет сокови и пакет вина. Да се дефинираат класите PaketSok и PaketVino кои ги имплементираат методите од апстрактната класа ImaMasa. При тоа да се земе предвид дека класите PaketSok и PaketVino се изведени од класата PaketPijalok. Притоа да се земат дадените податоци:

Класа PaketPijalok:

членови:
volumenEden double
kolicina int
методи:
double vratiMasa()
void pecati()
int getKolicina()
Класа PaketSok:

членови:
volumenEden double
kolicina int
daliGaziran bool
методи:
double vratiMasa()
void pecati()
Класа PaketVino:

членови:
volumenEden double
kolicina int
procentAlkohol double
методи:
double vratiMasa()
double getProcentAlkohol()
void pecati()
Еден пијалок има маса пресметана како производ на волуменот и густината (0.8kg/dm3) и масата на амбалажата (0.2kg). Овие податоци за густината и за масата на амбалажата да се стават како статички податоци за класата PaketPijalok. Масата на пакетот е производ на масата на еден пијалок и количината на пијалоци која ја има во пакетот. Соковите кои не се газирани имаат дополнителна маса од 0.1kg по пијалок. За вината, масата се добива како производ од масата на пакетот пресметан по правилата за секој пијалок помножен со коефициентот: (0.9+procentAlkohol).

Покрај овие класи, да се имплементира класата Kamion. За еден камион се чуваат информации за:

регистрацијата char*
возачот char*
елементите кои ги превезува камионот (низа од покажувачи од ImaMasa)
Во класата Kamion покрај методите set и get дефинирајте ги и следните методи:

-Kamion(char* , char* ) конструктор со кој се генерира празен камион (без товар) - void dodadiElement(ImaMasa) се додава нов елемент во камионот - double vratiVkupnaMasa() се враќа вкупната маса на товарот кој го пренесува камионот - void pecati() се печатат сите елементи во камионот заедно со регистрацијата и името на возачот - Kamion pretovar(char* , char* ) се врши претовар во нов камион, но во новиот покрај тоа што се менуваат регистрацијата и името на возачот (аргументи), се отстранува пакетот со најголема маса.

Со помош на правилата за справување со исклучоци да се модифицира програмата така што ќе се запазат следните правила:

Регистрацијата има 8 карактери, така што првите два и последните два мора да бидат букви. Онаму каде што ќе се фати исклучокот, ќе се отпечати "Pogresno vnesena registracija!" и нема да може да се креира објект од тип на камион.
Процентот на алкохол е меѓу 0 и 1. Онаму каде што ќе биде фрлен исклучокот да се фати така што ќе се отпечати "Pogresno vnesen procent na alkohol!" и притоа истиот ќе го постави на 0.

Sample input:
SK3456RG
Ljupcho
1 20
1
3 45
0.7
2 10
0.12
0.5 50
0
5 12
0.8
BT1234GH
Petko

Sample output:
Kamion so registracija SK3456RG i vozac Ljupcho prenesuva: 
Paket sok
kolicina 20, so po 0.8 l(dm3)
Paket vino
kolicina 45, 70% alkohol od po 2.4 l(dm3)
Paket vino
kolicina 10, 12% alkohol od po 1.6 l(dm3)
Paket sok
kolicina 50, so po 0.4 l(dm3)
Paket vino
kolicina 12, 80% alkohol od po 4 l(dm3)
Vkupna masa: 346.24
Kamion so registracija BT1234GH i vozac Petko prenesuva: 
Paket sok
kolicina 20, so po 0.8 l(dm3)
Paket vino
kolicina 10, 12% alkohol od po 1.6 l(dm3)
Paket sok
kolicina 50, so po 0.4 l(dm3)
Paket vino
kolicina 12, 80% alkohol od po 4 l(dm3)
Vkupna masa: 159.04
*/

#include<iostream>
#include<cstring>
using namespace std;

class ImaMasa {
public:
    virtual double vratiMasa()=0;
    virtual void pecati()=0;
};
class PaketPijalok {
protected:
    double volumenEden;
    int kolicina;
public:
    static const double ambalaza=0.2;
    static const double gustina=0.8;
    PaketPijalok(double vol,int kol) {
        volumenEden=vol;
        kolicina=kol;
	}
    int getKolicina() {
        return kolicina;
    }
    double vratiMasa() {
        return (volumenEden*gustina+ambalaza)*getKolicina();
    }
    double getVolumen() {
        return volumenEden;
    }
    double getGustina() {
        return gustina;
    }
    void pecati() {
        cout<<"kolicina "<<kolicina;
    }
};

class PaketSok:public PaketPijalok,public ImaMasa {
private:
	bool daliGaziran;
public:
	PaketSok(double vol,int kol, bool gaziran):PaketPijalok(vol,kol) {
		daliGaziran=gaziran;
	}
    
double vratiMasa() {
    if(daliGaziran==true) {
    return PaketPijalok::vratiMasa();
	}
	else {
		return PaketPijalok::vratiMasa()+0.1*PaketPijalok::getKolicina();
	}
}
    
void pecati() {
    cout<<"Paket sok"<<endl;
    cout<<"kolicina "<<kolicina<<", so po "<<getVolumen()*getGustina()<<" l(dm3)"<<endl;
}
};

class PaketVino:public PaketPijalok,public ImaMasa {
private:
	double procent_alkohol;
public:
	PaketVino(double vol,int kol,double pro):PaketPijalok(vol,kol) {
        try {
            procent_alkohol=pro;
            if(procent_alkohol<0 || procent_alkohol>1)
            throw 1;
        }
        catch (int) {
            cout<<"Pogresno vnesen procent na alkohol!"<<endl;
            procent_alkohol=0;
        }
}
double getProcentAlkohol() {
	return procent_alkohol;
}
double vratiMasa() {
	return PaketPijalok::vratiMasa()*(0.9+procent_alkohol);
}
void pecati() {
    cout<<"Paket vino"<<endl;
    cout<<"kolicina "<<kolicina<<", "<<procent_alkohol*100<<"% alkohol od po "<<getVolumen()*getGustina()<<" l(dm3)"<<endl;
}
};

class Kamion {
private:
    char registracija[9];
    char vozac[50];
    ImaMasa ** niza;
    int broj_elementi;
public:
	Kamion(char *reg,char *voz) {
        if(!(isalpha(reg[0]) && isalpha(reg[1]) && isalpha(reg[7]) && isalpha(reg[6])))
        throw 0;
        strcpy(registracija,reg);
        strcpy(vozac,voz);
        niza=new ImaMasa*[10];
        broj_elementi=0;
}
void setRegistracija(char* r) {
	strcpy(registracija, r);
}
void setVozac(char* v) {
	strcpy(vozac, v);
}
void setBroj(int b) {
	broj_elementi= b;
}
Kamion(char *reg,char *voz,ImaMasa ** m,int broj) {
    niza=new ImaMasa*[broj];
    for(int i=0;i<broj;i++)
    niza[i]=m[i];
    broj_elementi=broj;
}
void dodadiElement(ImaMasa *n) {
    ImaMasa ** pom=new ImaMasa*[broj_elementi+1];
    for(int i=0;i<broj_elementi;i++) {
    	pom[i]=niza[i];
    }
    pom[broj_elementi]=n;
    broj_elementi++;
    niza=new ImaMasa*[broj_elementi];
    for(int i=0;i<broj_elementi;i++) {
    	niza[i]=pom[i];
    }
}
double vratiVkupnaMasa() {
    double vkupno=0;
    for(int i=0;i<broj_elementi;i++) {
    	vkupno+=niza[i]->vratiMasa();
    }
    return vkupno;
}
void pecati() {
    cout<<"Kamion so registracija "<<registracija<<" i vozac "<< vozac<<" prenesuva: "<<endl;
    for(int i=0;i<broj_elementi;i++) {
    	niza[i]->pecati();
    }
}
Kamion pretovar(char *reg,char * voz) {
    Kamion nov(reg,voz);
    int max_i=0;
    double max_masa=niza[0]->vratiMasa();
    for(int i=0;i<broj_elementi;i++) {
        if(niza[i]->vratiMasa()>max_masa) {
            max_masa=niza[i]->vratiMasa();
            max_i=i;
        }
    }
    for(int i=0;i<broj_elementi;i++) {
        if(i!=max_i)
        nov.dodadiElement(niza[i]);
    }
    return nov;
    }
};

int main() {
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;
try {
    cin>>reg;
    cin>>ime;
    Kamion A(reg, ime);
    ImaMasa **d = new ImaMasa*[5];
    cin>>vol>>kol;
    cin>>g;
    d[0] = new PaketSok(vol, kol, g);
    cin>>vol>>kol;
    cin>>proc;
    d[1] = new PaketVino(vol, kol, proc);
    cin>>vol>>kol;
    cin>>proc;
    d[2] = new PaketVino(vol, kol, proc);
    cin>>vol>>kol;
    cin>>g;
    d[3] = new PaketSok(vol, kol, g);
    cin>>vol>>kol;
    cin>>proc;
    d[4] = new PaketVino(vol, kol, proc);
    A.dodadiElement(d[0]);
    A.dodadiElement(d[1]);
    A.dodadiElement(d[2]);
    A.dodadiElement(d[3]);
    A.dodadiElement(d[4]);
    A.pecati();
    cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
    cin>>reg;
    cin>>ime;
    Kamion B = A.pretovar(reg, ime);
    B.pecati();
    cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;
}
catch(int) {
	cout<<"Pogresno vnesena registracija"<<endl;
}
}