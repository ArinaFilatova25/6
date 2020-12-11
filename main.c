#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <locale.h>

void osn(float x1,float y1,float x2,float y2, float rec){

float ax,by,cx,dy;
ax=2*x1/3+x2/3;
cx=x1/3+2*x2/3;
by=2*y1/3+y2/3;
dy=y1/3+2*y2/3;
rectangle(x1,y1,x2,y2);

if (rec>0) {
osn(x1, y1, ax, by, rec-1);
osn(ax, y1, cx, by, rec-1);
osn(cx, y1, x2, by, rec-1);
osn(x1, by, ax, dy, rec-1);
osn(cx, by, x2, dy, rec-1);
osn(x1, dy, ax, y2, rec-1);
osn(ax, dy, cx, y2, rec-1);
osn(cx, dy, x2, y2, rec-1);
}
}

int main()
{ setlocale(LC_ALL,"Rus");
int rec;

printf("¬ведите глубину рекурсии:\n");
scanf("%d", &rec);
int gd = CUSTOM;
int gm = CUSTOM_MODE(600,600);
initgraph(&gd, &gm,"");

setbkcolor(11);
cleardevice();

setlinestyle(0,0,4);
setcolor(13);
osn(100, 100, 500, 500,rec);
readkey();
closegraph();

return 0;
}
