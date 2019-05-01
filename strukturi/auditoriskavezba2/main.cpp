#include<iostream>
using namespace std;

struct Person {
char ime[80], adresa[90];
double plata;
};
Person Vraboten[50];

void printperson(Person const &p) {
cout << "Imeto na vraboteniot e:" << p.ime << "a, negovata adresa e:"
<< p.adresa << endl;
}

Person const &ZemiVraboten(int index) {
 return (Vraboten[index]);
}
int main() {
Person Rakovoditel;
printperson(Rakovoditel);

printperson(ZemiVraboten(5));
return (0);
}
