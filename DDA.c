#include <graphics.h>
#include <conio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2){
    float dx = x2-x1 , dy = y2-y1;
    float steps = max(fabs(dx) , fabs(dy));
    float xinc = dx / steps;
    float yinc = dy / steps;

    float x = x1 , y = y1;
    for(int i=0; i<= steps; i++){
        putpixel(round(x),round(y),WHITE);
        x += xinc;
        y += yinc;
    }
}

int main(){
    int gd = DETECT , gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    DDA(100,200,300,400);
    getch();
    closegraph();

    return 0;
}
