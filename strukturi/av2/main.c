#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct grad
{
    char ime[100];
    int br;
}g;
struct pretsedatel
{
    char ime[100];
    char prezime[100];
    char partija[100];

}p;
struct drzava
{
    char ime[100];
    struct pretsedatel p;
    struct grad g;
    int br;

};
int main ()
{
    int i, n;
    struct drzava d[100];
    printf("Vnesete so kolku drzavi ke rabotime.\n");
    scanf("%d", &n);
    printf("Vnesuvajte podatoci pocnuvajci od ime na drzavata.\n");
    for(i=0; i<n; i++)
    {
        scanf("%s",&d[i].ime);
        scanf("%s", &d[i].p.ime);
        scanf("%s", &d[i].p.prezime);
        scanf("%s", &d[i].p.partija);
        scanf("%s", &d[i].g.ime);
        scanf("%d", &d[i].g.br);
        scanf("%d", &d[i].br);
    }
    int max, maxi;
    printf("Ispituvame maksimum:\n");
    maxi=0;
    max=d[maxi].g.br;
    for(i=0; i<n; i++)
    {
        if(d[i].g.br>max)
        {
            max=d[i].g.br;
            maxi=i;
        }

    }
    printf("Ime na pretsedatel so najgolem broj na ziteli. %s", d[maxi].p.ime);
    return 0;

}
