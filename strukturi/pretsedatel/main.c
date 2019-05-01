#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct grad
{
    char ime[100];
    int brz;
};
struct pretsedatel
{
    char ime[100];
    char prezime[100];
    char partija[100];
};

struct drzava
{
    char ime[100];
    int brdrz;
    struct grad gr;
    struct pretsedatel pr;
}country;
int main()
{
    struct drzava d[20];
    int n;
    int i;
    int max;
    int maxi;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &d[i].ime);
        printf("President:\n");
        scanf("%s", &d[i].pr.ime);
        scanf("%s", &d[i].pr.prezime);
        scanf("%s", &d[i].pr.partija);
        scanf("%d", &d[i].gr.brz);
        scanf("%s", &d[i].gr.ime);
        scanf("%d", &d[i].gr.brz);
    }
    maxi=i;
    max=d[maxi].gr.brz;
    for(i=0; i<n; i++)
    {
        if(d[i].gr.brz>max)
        {
            max=d[i].gr.brz;
            maxi=i;
        }
    }
    printf("Name of the president of the country with the largest capital:", d[maxi].pr.ime);
    return 0;


}
