#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc\\BGI");

    setcolor(WHITE);
    circle(100, 100, 50);
    setfillstyle(SOLID_FILL, RED);
    floodfill(100, 100, WHITE);
    getch();
    closegraph();
    return 0;
}