#include<iostream>
#include<cstring>
using namespace std;
struct Person
{
    char ime[80], adresa[80];
    void printperson(void);
};
void Person :: printperson()
{
    cout<<"Imeto na vraboteniot e: "<<ime<<" a, negovata adresa e: "<<adresa<<endl;
}
int main ()
{
    cout<<"Vnesete ime i adresa na vraboteni."<<endl;
    Person Vraboten;
    Person Rakovoditel;
    cin>>Vraboten.ime>>Vraboten.adresa;
    cin>>Rakovoditel.ime>>Rakovoditel.adresa;
    Vraboten.printperson();
    Rakovoditel.printperson();
    return 0;
}
