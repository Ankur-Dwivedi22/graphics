#include <graphics.h>
#include <conio.h>

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

int main(){
    int gd = DETECT , gm ;
    initgraph(&gd, &gm, "C:\\Turboc3\\BIG");

    int x1 = 100 , y1 = 100, x2 = 150 , y2 = 100, x3 = 125, y3 = 50;
    drawtriangle(x1,y1,x2,y2,x3,y3);

    drawtriangle(x1+50,y1+50,x2+50,y2+50,x3+50,y3+50);

    float angle = 45 * 3.14 / 180;
    int xr1 = x1 * cos(angle) - y1 * sin(angle);
    int yr1 = x1 * sin(angle) + y1 * cos(angle);
    int xr2 = x2 * cos(angle) - y2 * sin(angle);
    int yr2 = x2 * sin(angle) + y2 * cos(angle);
    int xr3 = x3 * cos(angle) - y3 * sin(angle);
    int yr3 = x3 * sin(angle) + y3 * cos(angle);
    drawtriangle(xr1,yr1,xr2,yr2,xr3,yr3);

    getch();
    closegraph();
    return 0;
}
