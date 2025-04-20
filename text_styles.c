#include <graphics.h>
#include <conio.h>

int main(){
    int gd = DETECT , gm;
    initgraph(&gd, &gm , "C:\\Turboc3\\BGI");

    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(100,200,"Default font size 1");

    setcolor(YELLOW);
    settextstyle(SANS_SERIF_FONT, VERT_DIR, 2);
    outtextxy(100, 200, "Sans font size 2");

    getch();
    closegraph();
    return 0;
}