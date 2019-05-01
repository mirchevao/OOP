#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct rekviziti
{
    int baloni;
    float litrialkohol;
    float kgjadenje;
    int loncinja;
    int tanjircinja;
};

struct poganenje
{
    char *parovi[100];
    char *mestazapoganenje[50]; //primer: peralna, umivalnik..
    char *poganiigri[50]; //flip the cup, kings cup..


};

int main()
{
    struct rekviziti *rek;
    struct poganenje *pog;
    char *pesni[100];
    char imeprezime[100];

    printf("Hello Sandra. Welcome to your birthday structure.\n I hope you'll have fun playing with it, like I like playing with sticks :).\n Please follow the instructions carefully.\n I wish you a happy birthday, let the fun begin.\n");
    printf("Please enter the following party supplies in the exact same order: Number of balloons (int), liters of alcohol (float), kilograms of food(float), number of cups/LONCINJA (int), number of plates(int)");
    scanf("%d%f%f%d%d", &rek->baloni, &rek->litrialkohol, &rek->kgjadenje, &rek->loncinja, &rek->tanjircinja);
    printf("Balloons: %d\nLiters of alcohol: %f\nKG food: %f\nLONCINJA: %d\nPIJATCA: %d\n", rek->baloni, rek->litrialkohol, rek->kgjadenje, rek->loncinja, rek->tanjircinja);
    printf("Now enter the names and surnames of your guests. When you are finished just press enter.\n");
    gets(imeprezime);
    puts(imeprezime);
    printf("Now enter the dirty stuff that you are going to do.\n Enter the couples that are playing these games (int), enter the places that they are going to do the dirty stuff (washing machine, sink..) and finally enter the dirty games that you are going yo play (flip the cup, kings cup...)\n ");
    gets(pog->parovi);
    puts(pog->parovi);
    printf("Places:\n");
    gets(pog->mestazapoganenje);
    puts(pog->mestazapoganenje);
    printf("Games:\n");
    gets(pog->poganiigri);
    puts(pog->poganiigri);
    printf("Now enter the names of the songs\n");
    gets(pesni);
    puts(pesni);
    return 0;


}

