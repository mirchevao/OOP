#include <iostream>
#include <cstring>
using namespace std;

class List {
private:
    int *niza;
    int size;

    void copy(const List &from) {
        size = from.size;
        niza = new int[size];
        for(int i = 0; i < size; i++) {
            niza[i] = from.niza[i];
        }
    }
public:
    List() {
        size = 0;
        niza = new int[size];
    }
    List(int *niz, int s) {
        size = s;
        niza = new int[size];
        for(int i = 0; i < size; i++) {
            niza[i] = niz[i];
        }
    }
    List(const List &from) {
        copy(from);
    }
    ~List() {
        delete [] niza;
    }
    List& operator = (const List &from) {
        if(this == &from) return *this;
        delete [] niza;
        copy(from);
        return *this;
    }

    int sum() {
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += niza[i];
        }
        return sum;
    }
    double average() {
        return sum() * 1.0 / size;
    }

    void pecati() {
        cout << size << ": ";
        for(int i = 0; i < size; i++) {
            cout << niza[i] << " ";
        }
        cout << "sum: " << sum() << " " << "average: " << average() << endl;
    }

    int numElements() {
        return size;
    }
};

class ListContainer {
private:
    List *listi;
    int n;
    int brObidi;
    int failedAttempt;
    int successAttempt;

    void copy(const ListContainer &from) {
        n = from.n;
        listi = new List[n];
        for(int i = 0; i < n; i++) {
            listi[i] = from.listi[i];
        }
        brObidi = from.brObidi;
        failedAttempt = from.failedAttempt;
        successAttempt = from.successAttempt;
    }

public:
    ListContainer() {
        n = 0;
        brObidi = 0;
        successAttempt = 0;
        failedAttempt = 0;
        listi = new List[n];
    }
    ListContainer(const ListContainer &from) {
        copy(from);
    }
    ~ListContainer() {
        delete [] listi;
    }

    ListContainer& operator = (const ListContainer &from) {
        if(this == &from) return *this;
        delete [] listi;
        copy(from);
        return *this;
    }

    void print() {
        if(n == 0) cout << "The list is empty" << endl;
        else {
            for (int i = 0; i < n; i++) {
                cout << "List number: " << i + 1 << " List info: ";
                listi[i].pecati();
            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
            cout << "Successful attempts: " << successAttempt << " Failed attempts: " << failedAttempt << endl;
        }
    }

    void addNewList(List l) {
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(l.sum() == listi[i].sum()) {
                index = 1;
                failedAttempt++;
                break;
            }
        }
        if(index == 0) {
            List *temp = listi;
            listi = new List[n + 1];
            for(int i = 0; i < n; i++) {
                listi[i] = temp[i];
            }
            listi[n] = l;
            ++n;
            successAttempt++;
            delete [] temp;
        }
    }

    int sum() {
        int suma = 0;
        for(int i = 0; i < n; i++) {
            suma += listi[i].sum();
        }
        return suma;
    }
    double average() {
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += listi[i].numElements();
        }
        return sum() / (total * 1.0);
    }
};


int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;

    }
    else {
        lc.print();
    }
}
