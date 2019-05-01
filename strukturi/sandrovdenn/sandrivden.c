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
struct gosti
{
    char *imeprezime[50];
};
struct poganenje
{
    int parovi;
    char *mestazapoganenje[50]; //primer: peralna, umivalnik..
    char *poganiigri[50]; //flip the cup, kings cup..


};
struct playlist
{
    int br;
    char *pesni[1000];
    char *zanr[30];
};

int main()
{
    struct rekviziti *rek;
    struct gosti *gost;
    struct poganenje *pog;
    struct playlist *play;

    printf("Hello Sandra. Welcome to your birthday structure.\n I hope you'll have fun playing with it, like I like playing with sticks :).\n Please follow the instructions carefully.\n I wish you a happy birthday, let the fun begin.\n");
    printf("Please enter the following party supplies in the exact same order: Number of balloons (int), liters of alcohol (float), kilograms of food(float), number of cups/LONCINJA (int), number of plates(int)");
    scanf("%d%f%f%d%d", &rek->baloni, &rek->litrialkohol, &rek->kgjadenje, &rek->loncinja, &rek->tanjircinja);
    printf("Balloons: %d\nLiters of alcohol: %f\nKG food: %f\nLONCINJA: %d\nPIJATCA: %d\n", rek->baloni, rek->litrialkohol, rek->kgjadenje, rek->loncinja, rek->tanjircinja);

    printf("Now, enter your guest list.\n");
    int i, n;
    printf("Enter how many guests are you expecting.");
    scanf("%d", &n);
    printf("Now enter the names and surnames of your guests.\n");
    for(i=0; i<n; i++)
        scanf("%s", &(gost+i)->imeprezime);
    for(i=0; i<n; i++)
        printf("%s", (gost+i)->imeprezime);
    printf("Now enter the dirty stuff that you are going to do.\n Enter the couples that are playing these games (int), enter the places that they are going to do the dirty stuff (washing machine, sink..) and finally enter the dirty games that you are going yo play (flip the cup, kings cup...)\n ");
    printf("Enter how many couples are going to play, who are the couples, how many dirty places you've come up with and of course how many games will be played.\n");
    int brparoviii;
    scanf("%d", &brparoviii);
    printf("Couples:\n");
    for(i=0; i<brparoviii; i++)
        scanf("%s", &(pog+i)->parovi);
    printf("Places:\n");
    scanf("%s", &pog->mestazapoganenje);
    printf("Games:\n");
    scanf("%s", &pog->poganiigri);
    for(i=0; i<brparoviii; i++)
        printf("%s\n", (pog+i)->parovi);
    printf("Places: %s\nGames: %s\n", pog->mestazapoganenje, pog->poganiigri);
    printf("Finally enter some songs that you would like to hear on your birthday. Enter the number of songs, the genre and the song name.\n");
    int numsong;
    printf("Enter how many songs you are going to enter.\n");
    scanf("%d", &numsong);
    printf("Now enter the names of the songs\n");
    for(i=0; i<numsong; i++)
        scanf("%s", &(play+i)->pesni);
    printf("Here are your songs.\n");
    for(i=0; i<numsong; i++)
        printf("%s", (play+i)->pesni);
    printf("Okay now, you have filled the structures that I have prepared.\nNow it is time to make it even more fun.\nLet us imagine some situations.\n");
    printf("To be continued.. I will finish it when I learn about classes!");




    return 0;


}

