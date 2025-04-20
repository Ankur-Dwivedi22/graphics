#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc\\BGI");

    int poly[] = {100, 100, 150, 150, 200, 200, 250, 250, 300, 300};
    setcolor(WHITE);
    drawpoly(5, poly);
    setfillstyle(SOLID_FILL, RED);
    floodfill(110, 100, WHITE);
    getch();
    closegraph();
    return 0;
}