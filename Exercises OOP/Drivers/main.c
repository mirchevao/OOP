#include <stdio.h>
#include <string.h>

typedef struct Driver {
    char name[100];
    int timeSec;
}driver;

typedef struct Race {
    char location[100];
    int nrDrivers;
    driver drivers[100];
}race;

void printMinSec(int inputSeconds) {
    int min = inputSeconds / 60;
    int sec = inputSeconds % 60;
    if(min >= 10) {
        printf("%d:%02d\n", min, sec);
    }
    else if(min < 10) {
        printf(" %d:%02d\n", min, sec);
    }
}


int main()
{
    int n, timeS;
    char name[100];
    race r[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", r[i].location);
        scanf("%d", &r[i].nrDrivers);
        for(int j = 0; j < r[i].nrDrivers; j++) {
            scanf("%s", r[i].drivers[j].name);
            scanf("%d", &r[i].drivers[j].timeSec);
        }
    }

    int swapped;
    while(1) {
        swapped = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < r[i].nrDrivers - 1; j++) {
                if(r[i].drivers[j].timeSec > r[i].drivers[j + 1].timeSec) {
                    int temp = r[i].drivers[j].timeSec;
                    char tempo[50];
                    strcpy(tempo, r[i].drivers[j].name);

                    r[i].drivers[j].timeSec = r[i].drivers[j + 1].timeSec;
                    strcpy(r[i].drivers[j].name, r[i].drivers[j + 1].name);

                    r[i].drivers[j + 1].timeSec = temp;
                    strcpy(r[i].drivers[j + 1].name, tempo);
                    swapped = 1;
                }
            }
        }

        if(swapped == 0) {
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%s (%d Drivers)\n", r[i].location, r[i].nrDrivers);
        for(int j = 0; j < 3; j++) {
            printf("%d. %s ", j + 1, r[i].drivers[j].name);
            printMinSec(r[i].drivers[j].timeSec);
        }
    }

}