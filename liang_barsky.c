#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int xmin = 200, xmax = 400, ymin = 200, ymax = 400;

int cliptest(float p, float q, float *t1, float *t2)
{
    float t;
    if (p < 0.0)
    {
        t = q / p;
        if (t > *t2)
            return 0;
        if (t > *t1)
            *t1 = t;
    }
    else if (p > 0.0)
    {
        t = q / p;
        if (t < *t1)
            return 0;
        if (t < *t2)
            *t2 = t;
    }
    else if (q < 0.0)
    {
        return 0;
    }
    return 1;
}

void liangBarsky(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1, dy = y2 - y1, t1 = 0.0, t2 = 1.0;

    if (cliptest(-dx, x1 - xmin, &t1, &t2))
        if (cliptest(dx, xmax - x1, &t1, &t2))
            if (cliptest(-dy, y1 - ymin, &t1, &t2))
                if (cliptest(dy, ymax - y1, &t1, &t2))
                {
                    int nx1 = x1 + t1 * dx;
                    int ny1 = y1 + t1 * dy;
                    int nx2 = x1 + t2 * dx;
                    int ny2 = y1 + t2 * dy;

                    setcolor(RED);
                    rectangle(xmin, ymin, xmax, ymax);
                    setcolor(GREEN);
                    line(nx1, ny1, nx2, ny2);
                }
                else
                {
                    setcolor(RED);
                    rectangle(xmin, ymin, xmax, ymax);
                }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Try different lines to test all cases
    liangBarsky(100, 100, 500, 500); // Intersecting line

    getch();
    closegraph();
    return 0;
}
