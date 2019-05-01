#include <iostream>
#include <cstring>
using namespace std;


class Pasta {
private:
    char *name;
    float price;
    int discount;
    int calories;

public:
    Pasta(const char *n = "", float price = 0.0, int calories = 0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        this->price = price;
        this->calories = calories;
        discount = 0;
    }

    Pasta(Pasta &p) {
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
        price = p.price;
        discount = p.discount;
        calories = p.calories;
    }
    Pasta& operator = (Pasta &p) {
        if(this != &p) {
            delete [] name;
            name = new char[strlen(p.name) + 1];
            strcpy(name, p.name);
            price = p.price;
            calories = p.calories;
            discount = p.discount;
        }
        return *this;
    }
    ~Pasta() {
        delete [] name;
    }

    Pasta& operator --() {
        int result = 0.05 * 100;
        discount -= result;
        return *this;
    }

    Pasta& operator - (int cal) {
        Pasta temp;
        strcpy(temp.name, name);
        name = new char[strlen(name) + 7];
        strcpy(name, temp.name);
        char light[6] = "Light";
        strcat(name, light);
        calories -= cal;
        price -= (0.2 * price);
        discount = 0;

        return *this;
    }

    void setDiscount(int discount) {
        this->discount = discount;
    }

    void setName(char* name) {
        delete [] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    friend ostream& operator << (ostream &os, const Pasta &p);
};

class ItalianRestaurant {
private:
    char name[50];
    Pasta *pa;
    int size;

public:
    ItalianRestaurant(char *name = (char *) "", Pasta *p = 0, int size = 0) {
        strcpy(this->name, name);
        this->size = size;
        pa = new Pasta[size];
        for(int i = 0; i < size; i++) {
            pa[i] = p[i];
        }
    }
    ItalianRestaurant(ItalianRestaurant &t) {
        strcpy(name, t.name);
        size = t.size;
        delete [] pa;
        pa = new Pasta[size];
        for(int i = 0; i < size; i++) {
            pa[i] = t.pa[i];
        }
    }
    ItalianRestaurant operator = (ItalianRestaurant &t) {
        if (this != &t) {
            strcpy(name, t.name);
            size = t.size;
            delete[] pa;
            pa = new Pasta[size];
            for (int i = 0; i < size; i++) {
                pa[i] = t.pa[i];
            }
        }
        return *this;
    }
    ~ItalianRestaurant() {
        delete [] pa;
    }

    ItalianRestaurant operator += (Pasta p) {
        size += 1;
        pa[size++] = p;
        return *this;
    }

    void setPasta(int i, Pasta &p) {
        pa[i] = p;
    }

    friend ostream& operator << (ostream &os, const ItalianRestaurant &t);
};

ostream& operator << (ostream &os, const ItalianRestaurant &t) {
    cout << t.name << endl;
    for(int i = 0; i < t.size; i++) {
        cout << t.pa[i] << endl;
    }
    return os;
}

ostream& operator << (ostream &os, const Pasta &p) {
    cout << p.name << " " << p.calories << " " << p.price << " ";
    if(p.discount > 0) {
        float discounted = p.price;
        discounted -= (p.discount * 0.01 * discounted);
        cout << "(" << discounted << ")";
    }
    return os;
}


int main() {
    char name[100];
    float price;
    int discount;
    int calories;

    int testCase;

    cin >> testCase;

    if(testCase == 1) {
        cout << "====== TESTING Pasta CLASS ======" << endl;
        cin >> name;
        cin >> price;
        cin >> discount;
        cin >> calories;
        cout << "CONSTRUCTOR" << endl;
        Pasta c1(name, price, calories);
        c1.setDiscount(discount);
        cin >> name;
        cin >> price;
        cin >> discount;
        cin >> calories;
        Pasta c2(name, price, calories);
        c2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << c1 << endl;
        cout << c2 << endl;
        cout << "OPERATOR --" << endl;
        --c1;
        cout << c1 << endl;
        cout << "OPERATOR -" << endl;
        int ca;
        cin >> ca;
        Pasta c3 = c1 - ca;
        cout << c3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING Pasta CONSTRUCTORS ======" << endl;
        cin >> name;
        cin >> price;
        cin >> discount;
        cin >> calories;
        cout << "CONSTRUCTOR" << endl;
        Pasta c1(name, price, calories);
        cout << c1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        Pasta c2(c1);
        cin >> name;
        c2.setName(name);
        cout << c1 << endl;
        cout << c2 << endl;
        cout << "OPERATOR =" << endl;
        c1 = c2;
        cin >> name;
        c2.setName(name);
        cout << c1 << endl;
        cout << c2 << endl;
        cout << "TESTING EXCEPTION" << endl;

        // YOUR CODE FOR EXCEPTION HANDLING HERE
        try {
            cin >> discount;
            if(discount < 0 || discount > 100) {
                throw 99;
            }
            c1.setDiscount(discount);
        }
        catch(int x) {
            cout << "Invalid discount value: " << discount << endl;
        }


    } else if(testCase == 3) {
        cout << "====== TESTING Italian Restaurant ======" << endl;
        char csName[50];
        cin >> csName;
        cout << "CONSTRUCTOR" << endl;
        ItalianRestaurant cs(csName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin >> name;
            cin >> price;
            cin >> calories;
            Pasta c(name, price, calories);
            cs += c;
        }
        cout << cs;
    } else if(testCase == 4) {
        cout << "====== TESTING Italian Restaurant CONSTRUCTORS ======" << endl;
        char csName[50];
        cin >> csName;
        ItalianRestaurant cs(csName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> name;
            cin >> price;
            cin >> calories;
            Pasta c(name, price, calories);
            cs += c;
        }
        Pasta x("Funghi", 260, 275);
        ItalianRestaurant cp = cs;
        cs.setPasta(0, x);
        cout << cs << endl;
        cout << cp << endl;
    }


    return 0;
}