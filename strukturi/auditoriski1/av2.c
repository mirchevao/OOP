#include<stdio.h>
struct vector
{
    float x;
    float y;
    float z;
};
typedef struct vector vector;
float skalar(vector v1, vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
vector vektorski(vector v1, vector v2)
{
    vector v;
    v.x = v1.y * v2.y + v1.z * v2.z;
    v.y = v1.x * v2.x + v1.z * v2.z;
    v.z = v1.x * v2.x + v1.y * v2.y;

    return v ;
}
int main ()
{
    vector v1;
    vector v2;
    scanf("%f%f%f", &v1.x, &v1.y, &v1.z);
    scanf("%f%f%f", &v2.x, &v2.y, &v2.z);
    vector v=vektorski(v1, v2);
    printf("Vektorskior prozivod iznesuva: %.2f\t%.2f\t%.2f\n", v.x, v.y, v.z);
    printf("Skalarniot prozivod iznesuva: %.2f", skalar(v1, v2));
    return 0;
}
