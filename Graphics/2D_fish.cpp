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


    ellipse(200, 200, 0, 360, 200, 80);

    ellipse(80, 168, 200, 240, 100, 50);
    circle(70,180,10);
    ellipse(100, 180, 290, 35, 50, 100);

    line(400,200,500,100);
    line(500,100,500,300);
    line(500,300,400,200);
    getch();

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();

    return 0;
}

