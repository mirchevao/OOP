#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct student
{
    char ime[];
    char prezime[];
    int indeks;
    int poeni;
}s[];
typedef struct student student;
void sort (s[], int n)
{
    int i, j;
    student c;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(s[j].poeni>s.poeni[j+i])
            {
                c=s[j];
                s[j]=c[j+1];
                s[j+1]=c;
            }
        }
    }

}
void golema(char *s)
{
    *s=toupper(*s);
    while(*(++s)!='\0')
    {
        *s=*tolower(*s);
    }

}

int main()
{
    student st[50];
    int i, n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &st[i].ime);
        scanf("%s", &st[i].prezime);
        scanf("%d", &st[i].indeks );
        int j, zadaca;
        st[i].poeni=0;
        for(j=0; j<4; j++)
        {
            scanf("%d", &zadaca);
            st[i].poeni+=zadaca;
        }
        golema(st[i].ime);
        golema(st[i].prezime);


    }
    sort(st, n);
    for(i=0; i<n; i++)
    {
        printf("%d. %s\t%s\t%d\%d\n", i+1, st[i].prezime, st[i].ime, st[i].indeks, st[i].poeni);

    }
    return 0;
}
