#include<iostream>
using namespace std;
struct bigone
{
    int key;
    char text[1000];
}bo={123, "This is a big structure."};
void valfun (bigone v1);
void ptrfun(bigone *p1);
void reffun(bigone &r1);

int main ()
{
    valfun(bo);
    ptrfun(&bo);
    reffun(bo);
    return 0;
}
//---pass by value
void valfun(bigone v1);
{
    cout<<endl<<v1.key;
    cout<<endl<<v1.text;
}
//---pass by pointer
void ptrfun(bigone *p1)
{
    cout<<endl<<p1->key;
    cout<<endl<<p1->text;
}
//---pass by reference
void reffun(bigone &r1)
{
    cout<<endl<<r1.key;
    cout<<endl<<r1.text;
}
