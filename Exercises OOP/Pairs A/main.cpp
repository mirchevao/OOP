#include <iostream>
#include <cstring>
using namespace std;


class Pair {
private:
    char *key;
    float value;

public:
    Pair(char *key = (char *) "", float value = 0.0) {
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
        this->value = value;
    }
    Pair(const Pair &pa) {
        value = pa.value;
        this->key = new char[strlen(pa.key) + 1];
        strcpy(this->key, pa.key);
    }
    Pair& operator = (Pair& p) {
        if(this == &p) return *this;
        this->value = p.value;
        this->key = new char[strlen(p.key) + 1];
        strcpy(this->key, p.key);

        return *this;
    }
    ~Pair() {
        delete [] key;
    }

    Pair& operator ++() { // Pre Increment Operator Overload
        value++;
        return *this;
    }
    Pair operator ++(int i) { // Post Increment Operator Overload
        value++;
        return *this;
    }

    char *getKey() {
        return key;
    }
    float getValue() {
        return value;
    }

    friend Pair operator +(Pair &, Pair &);
    friend class Collection;
    friend ostream& operator << (ostream &os, const Pair &rhs);
};

class Collection {
private:
    Pair *p;
    int size;

public:
    Collection(int size = 0, Pair *p = 0) {
        this->size = size;
        this->p = new Pair[size];
        for(int i = 0; i < size; i++) {
            this->p[i] = p[i];
        }
    }
    Collection(const Collection &c) {
        this->size = c.size;
        this->p = new Pair[size];
        for(int i = 0; i < size; i++) {
            this->p[i] = c.p[i];
        }
    }
    Collection& operator = (const Collection &c) {
        if(this != &c) {
            this->size = c.size;
            delete [] this->p;
            this->p = new Pair[size];
            for(int i = 0; i < size; i++) {
                this->p[i] = c.p[i];
            }
        }
        return *this;
    }
    ~Collection() {
        delete [] p;
    }

    Collection& operator += (Pair pair) {
        Pair *tmp = new Pair[size + 1];
        for(int i = 0; i < size; i++) {
            tmp[i] = p[i];
        }
        tmp[size++] = pair;
        delete [] p;
        p = tmp;
        return *this;
    }

    bool operator == (Collection &c) {
        if(this->size == c.size) {
            for(int i = 0; i < size; i++) {
                if(this->p->getValue() == c.p->getValue()) {
                    if(strcmp(this->p->getKey(), c.p->getKey()) == 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    Pair* find(const char* key) {
        for(int i = 0; i < size; i++) {
            if( (strcmp(p[i].getKey(), key) == 0) ) {
                return (p + i);
            }
        }
        return NULL;
    }

    friend ostream& operator << (ostream &os, const Collection &c);
};

Pair operator +(Pair &lhs, Pair &rhs) {
    Pair res;
    if( strlen(lhs.getKey()) > strlen(rhs.getKey()) ) {
        res.key = lhs.getKey();
        res.value = lhs.getValue() + rhs.getValue();
    }
    else if( strlen(lhs.getKey()) < strlen(rhs.getKey()) ) {
        res.key = rhs.getKey();
        res.value = lhs.getValue() + rhs.getValue();
    }
    else {
        res.key = lhs.getKey();
        res.value = lhs.getValue() + rhs.getValue();
    }
    return res;
}

ostream& operator << (ostream &os, const Collection &c) { // Collection OStream Overload
    cout << "Size: " << c.size << endl;
    for(int i = 0; i < c.size; i++) {
        cout << "('" << c.p[i].getKey() << "', " << c.p[i].getValue() << ")" << endl;
    }
    return os;
}

ostream& operator << (ostream &os, const Pair &rhs) { // Pair OStream Overload
    cout << "('" << rhs.key << "', " << rhs.value << ")" << endl;
    return os;
}

void read(char *k, float *v) {
    cin >> k;
    cin >> *v;
}
int main() {
    char key[50];
    float value;
    cout << "----- class Pair -----" << endl;
    read(key, &value);
    cout << "----- constructor -----" << endl;
    Pair p1(key, value);
    read(key, &value);
    Pair p2(key, value);
    Pair p3(p1);
    cout << "----- operator << -----" << endl;
    cout << p1;
    cout << p2;
    cout << "----- operator ++(int) -----" << endl;
    cout << p1;
    cout << p1++;
    cout << "----- operator ++ -----" << endl;
    cout << ++p2;
    cout << "----- operator + -----" << endl;
    Pair p = p1 + p2;
    cout << "----- operator = -----" << endl;
    p3 = p;
    cout << p3;

    cout << "----- class Collection -----" << endl;
    cout << "----- constructor -----" << endl;
    Collection k;
    cout << "----- operator += -----" << endl;
    k += p1;
    k += p2;
    k += p3;
    cout << "----- operator << -----" << endl;
    cout << k;
    cout << "----- copy constructor -----" << endl;
    Collection k2(k);
    cout << "----- operator == -----" << endl;
    if(k == k2) {
        cout << "k == k2" << endl;
    }
    k2 += p1;
    if(k == k2) {
        // not equal
        cout << "k == k2" << endl;
    }
    cout << "----- find -----" << endl;
    Pair* f = k.find(key);
    cout << *f;
    strcat(key, "other");
    f = k.find(key);
    if(f == NULL) {
        cout << key << " not found" << endl;
    }
    return 0;
}
