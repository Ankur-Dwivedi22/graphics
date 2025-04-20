#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    circle(200, 200, 50);
    ellipse(300, 200, 0, 360, 300, 200);
    line(200, 200, 300, 300);

    for (int r = 60; r <= 120; r += 20)
    {
        circle(0, 0, r);
    }
    getch();
    closegrpah();
    return 0;
}