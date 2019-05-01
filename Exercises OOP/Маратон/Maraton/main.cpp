#include <iostream>
#include <cstring>
using namespace std;

class Ucesnik {
private:
    char *name;
    bool sex;
    int age;
    void copy(const Ucesnik &from) {
        name = new char[strlen(from.name) + 1];
        strcpy(name, from.name);
        sex = from.sex;
        age = from.age;
    }

public:
    Ucesnik(const char *nm = "", bool sex = 0, int age = 0) {
        name = new char[strlen(nm) + 1];
        strcpy(name, nm);
        this->sex = sex;
        this->age = age;
    }
    Ucesnik(const Ucesnik &from) {
        copy(from);
    }
    Ucesnik& operator = (const Ucesnik &from) {
        if(this != &from) {
            delete [] name;
            copy(from);
            return *this;
        }
        return *this;
    }

    bool operator > (const Ucesnik &rhs) {
        return age > rhs.age;
    }

    int getAge() {
        return age;
    }
    char *getName() {
        return name;
    }
    bool getSex() {
        return sex;
    }

    friend ostream& operator << (ostream &, const Ucesnik &);

    ~Ucesnik() {
        delete [] name;
    }
};

class Maraton {
private:
    char location[100];
    Ucesnik *uces;
    int nrParticipants;
    void copy(const Maraton &from) {
        strcpy(location, from.location);
        nrParticipants = from.nrParticipants;
        uces = new Ucesnik[nrParticipants];
        for(int i = 0; i < nrParticipants; i++) {
            uces[i] = from.uces[i];
        }
    }

public:
    Maraton(const char *loc = "") {
        strcpy(location, loc);
        nrParticipants = 0;
        uces = NULL;
    }
    Maraton(const Maraton &from) {
        copy(from);
    }
    Maraton& operator = (const Maraton &from) {
        if(this != &from) {
            delete [] uces;
            copy(from);
            return *this;
        }
        return *this;
    }

    Maraton& operator += (Ucesnik &u) {
        Ucesnik *temp = uces;
        uces = new Ucesnik[nrParticipants + 1];
        for(int i = 0; i < nrParticipants; i++) {
            uces[i] = temp[i];
        }
        uces[nrParticipants] = u;
        nrParticipants++;
        delete [] temp;
        return *this;
    }

    void prosecnoVozrast() {
        float total = 0.0;
        for(int i = 0; i < nrParticipants; i++) {
            total += uces[i].getAge();
        }
        cout << total / (float) nrParticipants << endl;
    }

    void pecatiPomladi(Ucesnik &u) {
        for(int i = 0; i < nrParticipants; i++) {
            if(uces[i].getAge() < u.getAge()) {
                cout << uces[i].getName() << endl;
                if(uces[i].getSex()) {
                    cout << "mashki" << endl;
                }
                else {
                    cout << "zhenski" << endl;
                }
                cout << uces[i].getAge() << endl;
            }
        }
    }

    ~Maraton() {
        delete [] uces;
    }
};

ostream& operator << (ostream &os, const Ucesnik &rhs) {
    cout << rhs.name << endl;
    if(rhs.sex) {
        cout << "mashki" << endl;
    }
    else {
        cout << "zhenski" << endl;
    }
    cout << rhs.age << endl;
    return os;
}

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    m.prosecnoVozrast();
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
