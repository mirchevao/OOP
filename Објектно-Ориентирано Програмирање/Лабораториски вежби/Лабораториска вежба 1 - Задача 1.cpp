/*Точка Problem 
Да се надополни програмата со следните барања:

Да се креира структура на точка во тродимензионален простор и да се напише функција која ќе го пресметува растојанието помеѓу две такви точки.
Да се напише функција која како аргумент прима три точки во дводимензионален простор и ќе проверува дали тие точки лежат на иста права.*/
#include <stdio.h>
#include<math.h>
typedef struct tocka2D {
	double x;
	double y;
} tocka2D ;

float rastojanie(tocka2D t1, tocka2D t2) {
	return sqrt ((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

typedef struct tocka3D {
	double x;
    double y;
    double z;
} tocka3D ;

float rastojanie3D(tocka3D t1, tocka3D t2) {
	 return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y)+(t1.z-t2.z)*(t1.z-t2.z));
}

int ista_prava(tocka2D t1, tocka2D t2, tocka2D t3) {
	if((t2.y-t1.y)/(t2.x-t1.x)==(t3.y-t2.y)/(t3.x-t2.x))
      return 1;
    else 
        return 0;
}
int main() {
    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	tocka2D t1 = { x1, y1 };
	tocka2D t2 = { x2, y2 };
	printf("%.2f\n", rastojanie(t1, t2));
    float z1, z2;
    scanf("%f %f", &z1, &z2);
    tocka3D t3 = {x1, y1, z1};
    tocka3D t4 = {x2, y2, z2};
    printf("%.2f\n", rastojanie3D(t3, t4));
    tocka2D t5 = {z1, z2};
    printf("%d\n", ista_prava(t1, t2, t5));
	return 0;
}