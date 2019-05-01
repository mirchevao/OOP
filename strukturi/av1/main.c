#include<stdio.h>
struct date {
    int den;
    int mesec;
    int godina;
}datum;
typedef struct date dat;
int input(dat y, dat m, dat d)
{
    scanf("%d%d%d", datum.godina, datum.mesec, datum.den);
}
int sporedba(dat d1, dat d2)
{
    if(d1.godina>d2.godina) return 1;
    else if(d1.godina<d2.godina) return -1;
    else
    {
        if(d1.mesec>d2.mesec) return 1;
        else if(d1.mesec<d2.mesec) return -1;
        else
        {
            if(d1.den>d2.den) return 1;
            else if(d1.den<d2.den) return -1;
        }
    }
}
int razlika(dat d1, dat d1)
{
    int denovi;
    denovi=d1.den-d2.den;
    denovi+=(d1.mesec-d2.mesec)*30;
    denovi+=(d1.godina-d2.godina)*365;
}
int main ()
{
    int s, int r;
    printf("Vnesete dva datuma.\n");
    input(dat);
    s=sporedba(dat d1, dat d2);
    r=razlika(dat d1, dat d2);
    printf("%d%d", s, r);
    return 0;


}
