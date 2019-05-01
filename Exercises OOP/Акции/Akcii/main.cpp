#include<iostream>
#include<cstring>
using namespace std;

class StockRecord {
private:
    char ID[12];
    char companyName[50];
    double originalStockPrice;
    double currentStockPrice;
    int shares;
    void copy(const StockRecord &from) {
        strcpy(ID, from.ID);
        strcpy(companyName, from.companyName);
        originalStockPrice = from.originalStockPrice;
        currentStockPrice = from.currentStockPrice;
        shares = from.shares;
    }

public:
    StockRecord(const char *ID = "", const char *cName = "", double sPrice = 0.0, int sBought = 0) {
        strcpy(this->ID, ID);
        strcpy(companyName, cName);
        originalStockPrice = sPrice;
        currentStockPrice = 0.0;
        shares = sBought;
    }
    StockRecord(const StockRecord &from) {
        copy(from);
    }
    StockRecord& operator = (const StockRecord &from) {
        if(this == &from) return *this;
        copy(from);
        return *this;
    }

    void setNewPrice(double c) {
        currentStockPrice = c;
    }

    double value() {
        return shares * currentStockPrice;
    }
    double profit() {
       return shares * (currentStockPrice - originalStockPrice);
    }
    char *getCompanyName() {
        return companyName;
    }
    double getOGPrice() {
        return originalStockPrice;
    }
    double getCurrPrice() {
        return currentStockPrice;
    }
    int getShares() {
        return shares;
    }


    ~StockRecord() {}


    friend ostream& operator << (ostream &, StockRecord &);
};

class Client {
private:
    char nameSurname[60];
    int IDsmetka;
    StockRecord *owned;
    int n;
    void copy(const Client &from) {
        strcpy(nameSurname, from.nameSurname);
        IDsmetka = from.IDsmetka;
        n = from.n;
        owned = new StockRecord[n];
        for(int i = 0; i < n; i++) {
            owned[i] = from.owned[i];
        }
    }

public:
    Client(const char *ns = "", int ID = 0) {
        strcpy(nameSurname, ns);
        IDsmetka = ID;
        n = 0;
        owned = 0;
    }
    Client(const Client &from) {
        copy(from);
    }
    ~Client() {
        delete [] owned;
    }

    Client& operator = (const Client &from) {
        if(this == &from) return *this;
        delete [] owned;
        copy(from);
        return *this;
    }

    double totalValue() {
        double total = 0.0;
        if(n > 0) {
            for(int i = 0; i < n; i++) {
                total += owned[i].value();
            }
        }
        return total;
    }

    Client& operator += (StockRecord &s) {
        StockRecord *temp = owned;
        owned = new StockRecord[n + 1];
        for(int i = 0; i < n; i++) {
            owned[i] = temp[i];
        }
        owned[n] = s;
        ++n;
        delete [] temp;
        return *this;
    }

    friend ostream& operator << (ostream &, Client &);
};

ostream& operator << (ostream &os, Client &rhs) {
    cout << rhs.IDsmetka << " " << rhs.totalValue() << endl;
    for(int i = 0; i < rhs.n; i++) {
        cout << rhs.owned[i].getCompanyName() << " " << rhs.owned[i].getShares() << " " << rhs.owned[i].getOGPrice() << " " << rhs.owned[i].getCurrPrice() << " "
                                                                                                                                                 << rhs.owned[i].profit() << endl;
    }
    return os;
}

ostream& operator << (ostream &os, StockRecord &rhs) {
    cout << rhs.companyName << " " << rhs.shares << " " << rhs.originalStockPrice << " " << rhs.currentStockPrice
         << " " << rhs.profit() << endl;
    return os;
}

// ne menuvaj vo main-ot

int main(){

    int test;
    cin >> test;

    if(test == 1){
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}
