#include <iostream>
#include <cstring>
using namespace std;

enum tip {pop = 0, rap = 1, rok = 2};

class Pesna {
private:
    char *name;
    int minutes;
    tip t;
    void copy(const Pesna &from) {
        name = new char[strlen(from.name) + 1];
        strcpy(name, from.name);
        minutes = from.minutes;
        t = from.t;
    }

public:
    Pesna(const char *nm = "", int minutes = 0, tip t = pop ) {
        name = new char[strlen(nm) + 1];
        strcpy(name, nm);
        this->minutes = minutes;
        this->t = t;
    }
    Pesna(const Pesna &from) {
        copy(from);
    }
    Pesna& operator = (const Pesna &from) {
        if(this == &from) return *this;
        delete [] name;
        copy(from);
        return *this;
    }

    void pecati() {
        cout << "\"" << name << "\"-" << minutes << "min" << endl;
    }
    int getMinutes() {
        return minutes;
    }

    ~Pesna() {
        delete [] name;
    }
    friend class CD;
};

class CD {
private:
    Pesna *pesni;
    int nrPesni;
    int maxLength;
    void copy(const CD &from) {
        nrPesni = from.nrPesni;
        maxLength = from.maxLength;
        pesni = new Pesna[nrPesni];
        for(int i = 0; i < nrPesni; i++) {
            pesni[i] = from.pesni[i];
        }
    }

public:
    CD(int maxLength) {// MAY NEED TO CHANGE
        this->maxLength = maxLength;
        nrPesni = 0;
        pesni = NULL;
    }
    CD(const CD &from) {
        copy(from);
    }
    ~CD() {
        delete [] pesni;
    }
    CD& operator = (const CD &from) {
        if(this == &from) return *this;
        delete [] pesni;
        copy(from);
        return *this;
    }

    void dodadiPesna(Pesna &p) {
        int howManySongs = 0, howLongTime = 0;
        for(int i = 0; i < nrPesni; i++) {
            howLongTime += pesni[i].minutes;
            howManySongs++;
        }
        if( (maxLength - howLongTime >= p.minutes)&&howManySongs < 10) {
            Pesna *temp = pesni;
            pesni = new Pesna[nrPesni + 1];
            for(int i = 0; i < nrPesni; i++) {
                pesni[i] = temp[i];
            }
            pesni[nrPesni] = p;
            ++nrPesni;
            delete [] temp;
            howManySongs = 0;
            howLongTime = 0;
        }
    }

    void pecatiPesniPoTip(tip ti) {
        for(int i = 0; i < nrPesni; i++) {
            if(pesni[i].t == ti) {
                pesni[i].pecati();
            }
        }
    }
    Pesna getPesna(int n) {
        return pesni[n];
    }
    int getBroj() {
        return nrPesni;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}
