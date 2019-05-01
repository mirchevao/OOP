#include<stdio.h>
#include<string.h>
struct karta
{
    char *brojka;
    char *boja;
} aCard;
int main ()
{
    struct karta *cardPtr;
    aCard.brojka="As";
    aCard.boja="Detelina";
    cardPtr=&aCard;
    printf("%s%s%s\n", aCard.brojka, " ", aCard.boja);
    printf("%s%s%s\n", cardPtr->brojka, " ", cardPtr->boja);
    printf("%s%s%s\n", (*cardPtr).brojka, " ", (*cardPtr).boja);
    return 0;
}
