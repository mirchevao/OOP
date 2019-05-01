/*Пресек на отсечки Problem 2 (2 / 2) 
Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки).
 Потоа да се напише функција која ќе проверува дали две отсечки се сечат.*/
 
 #include <stdio.h>
typedef struct tocka {
    float x;
    float y;
} tocka;
typedef struct otsecka {
    tocka prva;
    tocka vtora;
} otsecka;
 
int se_secat(otsecka o1, otsecka o2) {
        int seSecat = 0;
    float  k1 = (o1.prva.y - o1.vtora.y)/(o1.prva.x - o1.vtora.x);
    float k2 = (o2.prva.y - o2.vtora.y)/(o2.prva.x - o2.vtora.x);
    float b1 = o1.prva.y - k1*o1.prva.x;
    float b2 = o2.vtora.y - k2*o2.vtora.x;
    if(k1 == k2)
    {
        float levaTocka = o1.prva.x;
        float des = o2.vtora.x;
        return levaTocka >= des;
    }
    float finalno_k = k1-k2;
    float finalno_b = b1-b2;
    float res = -finalno_b/finalno_k;
    seSecat = ((res>=o1.prva.x&&res <= o1.vtora.x)&&(res>= o2.prva.x && res <= o2.vtora.x));
    return seSecat;
}
 
int main() {
    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    tocka t1 = { x1, y1 };
    tocka t2 = { x2, y2 };
    otsecka o1 = { t1, t2 };
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    t1.x = x1;
    t1.y = y1;
        t2.x = x2;
    t2.y = y2;
     
    otsecka o2 = { t1, t2 };
    printf("%d", se_secat(o1, o2));
    return 0;
}