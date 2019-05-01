#include<iostream>
#include<cstring>
using namespace std;

class Patnik{
private:
    char name[100];
    int klasa;
    bool bike;
    void copy(const Patnik &from) {
        strcpy(name, from.name);
        klasa = from.klasa;
        bike = from.bike;
    }
public:
    Patnik(const char *name = "", int k = 0, bool b = 0) {
        strcpy(this->name, name);
        klasa = k;
        bike = b;
    }
    Patnik(const Patnik &from) {
        copy(from);
    }
    ~Patnik() {}

    char *getName() {
        return name;
    }
    int getKlasa() {
        return klasa;
    }
    bool getBike() {
        return bike;
    }

    friend class Voz;
    friend ostream& operator << (ostream &, const Patnik &);
};

class Voz{
private:
    char destination[100];
    Patnik *pat;
    int n;
    int maxBikers;
    void copy(const Voz &from) {
        strcpy(destination, from.destination);
        n = from.n;
        maxBikers = from.maxBikers;
        pat = new Patnik[n];
        for(int i = 0; i < n; i++) {
            pat[i] = from.pat[i];
        }
    }

public:
    Voz(const char *destination = "", int nrBikers = 0) {
        strcpy(this->destination, destination);
        this->maxBikers = nrBikers;
        n = 0;
        pat = 0;
    }
    Voz(const Voz &from) {
        copy(from);
    }
    ~Voz() {
        delete [] pat;
    }

    Voz& operator += (Patnik &p) {
        if(p.getBike()) {
            if (maxBikers > 0) {
                Patnik *temp = pat;
                pat = new Patnik[n + 1];
                for (int i = 0; i < n; i++) {
                    pat[i] = temp[i];
                }
                pat[n] = p;
                ++n;
                delete[] temp;
            }
        }
        else {
            Patnik *temp = pat;
            pat = new Patnik[n + 1];
            for (int i = 0; i < n; i++) {
                pat[i] = temp[i];
            }
            pat[n] = p;
            ++n;
            delete[] temp;
        }
        return *this;
    }

    void patniciNemaMesto() {

        int withBikeFirst = 0, withBikeSecond = 0;
        int remainingBikeSpots = 0; int temp = 0, temp1 = 0, noEntrySecond = 0, noEntryFirst = 0;

        for(int i = 0; i < n; i++) {
            if(pat[i].bike&&pat[i].klasa == 1) {
                withBikeFirst++;
            }
            else if(pat[i].bike && pat[i].klasa == 2) {
                withBikeSecond++;
            }
        }

        remainingBikeSpots = maxBikers - withBikeFirst;
        temp = remainingBikeSpots - withBikeSecond;
        if(temp < 0) {
            while(temp < 0) {
                noEntrySecond++;
                temp++;
            }
        }
        temp1 = maxBikers - withBikeFirst;
        if(temp1 < 0) {
            while(temp1 < 0) {
                noEntryFirst++;
                temp1++;
            }
            noEntrySecond = withBikeSecond;
        }

        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << noEntryFirst << endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: " << noEntrySecond << endl;
    }

    friend ostream& operator << (ostream &, Voz &);
};

ostream& operator << (ostream &os, Voz &rhs) {
    cout << rhs.destination << endl;
    for(int i = 0; i < rhs.n; i++) {
        cout << rhs.pat[i].getName() << endl;
        cout << rhs.pat[i].getKlasa() << endl;
        cout << rhs.pat[i].getBike() << endl;
        cout << endl;
    }
    return os;
}

ostream& operator << (ostream &os, const Patnik &rhs) {
    cout << rhs.name << endl;
    cout << rhs.klasa << endl;
    cout << rhs.bike << endl;
    return os;
}

int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}

