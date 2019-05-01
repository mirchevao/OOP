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
    return v1.x * v2.x + v1.y * v2.y + v1.z + v2.z;
}
float vectorski(vector v1, vector v2)
{
    vector v;
    v.x = v1.y * v2.y + v1.z * v2.z;
    v.y = v1.x * v2.x + v1.z * v2.z;
    v.z = v1.x * v2.x + v1.y * v2.y;
    return v;
}
int main ()
{
    vector v1;
    vector v2;
    vector v=vektorski(v1, v2);
    printf("Vektorksi proizvod: %2.f %2.f %2.f", v.x, v.y, v.z );
    printf("Skalaren proizvod: %2.f", skalar(v1, v2));
    return 0;

}
