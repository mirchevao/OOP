#include<stdio.h>
enum months {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
typedef enum months month
int main ()
{
    typedef enum months month;
    const char *monthName[]={" ", "Janurary", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(month=JAN; month<=DEC; month ++)
        printf("%2d%11s", month, monthName[month]);
    return 0;
}
