/*Купувачка кошничка Problem 3 (2 / 37) 
Да се напише програма во која од стандарден влез се вчитува N (бројот на производи), 
а потоа се вчитуваат податоците за N производи (име, цена, количина). 
Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати во следниот облик (пример):*/



#include <stdio.h>

typedef struct proizvod
{
    char ime[100];
    int cena;
    int kolicina;
}proizvod ;
int main()
{
    int i,n;
    proizvod p[50];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s",&p[i].ime);
        scanf("%d",&p[i].cena);
        scanf("%d",&p[i].kolicina);
    }
              float vkupno=0;
                  for(i=0; i<n; i++)
              {
                  vkupno+=p[i].kolicina*p[i].cena;
              }
     int b=1;
    for(i=0; i<n; i++)
    {
       
        printf("%d. %s\t%.2f x %d = %.2f\n",b,p[i].ime, (float)p[i].cena,p[i].kolicina, (float)p[i].cena*p[i].kolicina);
        b++;
    }
    printf("Total: %.2f\n",vkupno);
              return 0;
              }