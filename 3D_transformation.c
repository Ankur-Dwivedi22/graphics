#include <graphics.h>
#include <conio.h>

void drawCube(int x, int y, int size)
{
    rectangle(x, y, x + size, y + size);
    rectangle(x + 20, y - 20, x + size + 20, y + size - 20);
    line(x, y, x + 20, y - 20);
    line(x + size, y, x + size + 20, y - 20);
    line(x, y + size, x + 20, y + size - 20);
    line(x + size, y + size, x + size + 20, y + size - 20);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    drawCube(100, 100, 100); // Original cube
    drawCube(150, 150, 100); // Translated cube

    getch();
    closegraph();
    return 0;
}
