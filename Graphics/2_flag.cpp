#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    rectangle(100,100,380,300);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(101,101,15);

    circle(240,200,50);
    setfillstyle(SOLID_FILL,RED);
    floodfill(240,240,15);


    getch();
    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();

    return 0;
}

