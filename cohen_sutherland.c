#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int getCode(int x, int y)
{
    int code = 0;
    if (x < xmin)
        code |= LEFT;
    if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    if (y > ymax)
        code |= TOP;
    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = getCode(x1, y1);
    int code2 = getCode(x2, y2);
    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int codeOut;
            int x, y;

            codeOut = code1 ? code1 : code2;

            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = getCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = getCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        setcolor(RED);
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(GREEN);
        line(x1, y1, x2, y2);
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

    // Example: Change to test different cases
    cohenSutherland(50, 120, 350, 320); // Intersecting case

    getch();
    closegraph();
    return 0;
}
