#include <iostream>
#include <cstring>
using namespace std;

class Pica {
private:
    char name[15];
    int price;
    char *ingredients;
    int discount;

public:
    Pica(const char *name = "", int price = 0, const char *ing = "", int discount = 0) {
        strcpy(this->name, name);
        this->price = price;
        ingredients = new char[strlen(ing) + 1];
        strcpy(ingredients, ing);
        this->discount = discount;
    }
    Pica(const Pica &from) {
        strcpy(name, from.name);
        price = from.price;
        ingredients = new char [strlen(from.ingredients) + 1];
        strcpy(ingredients, from.ingredients);
        discount = from.discount;
    }
    ~Pica() {
        delete [] ingredients;
    }

    Pica& operator = (const Pica &from) {
        if(this != &from) {
            strcpy(name, from.name);
            price = from.price;
            delete [] ingredients;  // POTENTIAL ERROR BEWARE!!!
            ingredients = new char[strlen(from.ingredients) + 1];
            strcpy(ingredients, from.ingredients);
            discount = from.discount;
        }
        return *this;
    }

    void pecati() {
        cout << name << " - " << ingredients << ", " << price << endl;
    }

    bool istiSe(Pica p) {
        return strcmp(ingredients, p.ingredients) == 0;
    }

    friend class Picerija;
};

class Picerija {
private:
    char name[15];
    Pica *pic;
    int amount;

public:
    Picerija(const char *name = "", Pica *p = 0, int amount = 0) {
        strcpy(this->name, name);
        this->amount = amount;
        pic = new Pica[amount];
        for(int i = 0; i < amount; i++) {
            pic[i] = p[i];
        }
    }
    Picerija(const Picerija &from) {
        strcpy(name, from.name);
        amount = from.amount;
        pic = new Pica[amount];
        for(int i = 0; i < amount; i++) {
            pic[i] = from.pic[i];
        }
    }
    ~Picerija() {
        delete [] pic;
    }

    Picerija& operator = (const Picerija &from) {
        strcpy(name, from.name);
        amount = from.amount;
        delete [] pic;  // POTENTIAL ERROR BEWARE !!!
        pic = new Pica[amount];
        for(int i = 0; i < amount; i++) {
            pic[i] = from.pic[i];
        }
        return *this;
    }

    void dodadi(Pica p) {
        int condition = 0;
        for(int i = 0; i < amount; i++) {
            if(strcmp(pic[i].ingredients, p.ingredients) == 0) {
                condition = 1;
                break;
            }
        }
        if(condition == 0) {
            Pica *temp = new Pica[amount + 1];
            for(int i = 0; i < amount; i++) {
                temp[i] = pic[i];
            }
            temp[amount++] = p;
            delete [] pic;  // POTENTIAL ERROR BEWARE !!!
            pic = temp;
        }
    }

    void piciNaPromocija() {
        for(int i = 0; i < amount; i++) {
            if(pic[i].discount > 0) {
                cout << pic[i].name << " - " << pic[i].ingredients << ", " << pic[i].price << " " << pic[i].price - ((pic[i].discount * 0.01) * (pic[i].price)) << endl;
            }
        }
    }

    void setIme(const char *name) {
        strcpy(this->name, name);
    }
    char *getIme() {
        return name;
    }
};



int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

    return 0;
}
