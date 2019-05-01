#include<iostream>
#include<cstring>

struct student
{
    char ime[];
    char prezime[];
    int indeks;
    int totalpts;
    void print();
    void read();
}s;
void print(student &t)
    {
        cout<<t.ime<<endl<<t.prezime<<endl<<t.indeks<<endl<<t.totalpts<<endl;
    }
void normalize(char *ime, bool uppercase=false)
{
    *ime=toupper(*ime);
    ++ime;
    while(*ime)
    {
        if(uppercase)
        {
            *ime=toupper(*ime);
        }
        else
        {
            *ime=tolower(*ime);
        }
        ++ime;
    }
}
void read(student &s)
{
    cin>>s.ime>>s.prezime;
    normalize(ime);
    normalize(prezime);
    cin>>s.indeks;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    s.totalpts=a+b+c+d;
}
void sort (student a[], int n)
{
    for(int i=0; ki<n; ++i)
    {
        for(int j=0; j<n-1; ++j)
        {
            if(a[j].totalpts<a[j+1].totalpts)
            {
                student tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}
int main ()
{
    student niza[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        read[niza[i];
    }
    sort(niza, n);
    cout<<"ORDERED\n";
    for(int i=0; i<n; i++)
    {
        niza[i].print();
    }
    return 0;
}
