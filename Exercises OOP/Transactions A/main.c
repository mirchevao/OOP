#include <stdio.h>
#include <string.h>

typedef struct Transaction {
    int day, month, year, amount;
    char currency[3];
}transac;

int main() {
    transac t[500];
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int d, m, y, amount;
        char curr[3];
        scanf("%d%*c", &d);    scanf("%d%*c", &m);    scanf("%d%*c", &y);
        scanf("%d%*c%*c", &amount);
        gets(curr);
        t[i].amount = amount;
        t[i].day = d;
        t[i].month = m;
        t[i].year = y;
        strcpy(t[i].currency, curr);

    }

    int nr = 1, total = 0;
    for(int i = 0; i < n; i++) {
        if(t[i].amount > 1000 && (strcmp(t[i].currency, "KD") == 0)) {
            if(t[i].year >= 2013 && t[i].year <= 2015) {
                printf("%d. %02d/%02d/%d %d M%s\n", nr++, t[i].day, t[i].month, t[i].year, t[i].amount, t[i].currency);
                total += t[i].amount;
            }
        }
    }
    printf("Total: %d MKD", total);

}