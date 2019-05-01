#include<stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
typedef struct date date;
int compare (date d1, date d2)
{
    if(d1.year>d2.year) return 1;
    else if(d1.year<d2.year) return -1;
    else return 0;
    if(d1.month>d2.month) return 1;
    else if(d1.month<d2.month) return -1;
    else return 0;
    if(d1.day>d2.day) return 1;
    else if(d1.day<d2.day) return -1;
    else return 0;

}
int sub(date d1, date d2)
{
    int days=d1.day-d2.day;
    days+=(d1.month-d2.month)*30;
    days+=(d1.year-d2.year)*365;
    return days;
}
void read(date *d)
{
    scanf("%d.%d.%d", &d->day, &d->month, &d->year);
}

int main ()
{
    date d1;
    date d2;
    read(&d1);
    read(&d2);
    int result=compare(d1, d2);
    if(result==0)
        printf("The dates are equal");
    else if(result==1)
        printf("The difference in dates is %d", sub(d1, d2));
    else printf("The difference in dates id %d", sub(d2, d1));
    return 0;


}
