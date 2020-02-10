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
for(int i=0;i<=500;i++)
{

line(0,300,640,300);

circle(100+i,285,15);
circle(200+i,285,15);
circle(100+i,285,5);
circle(200+i,285,5);
line(65+i,285,85+i,285);
line(115+i,285,185+i,285);
line(215+i,285,235+i,285);
line(65+i,285,65+i,260);
line(235+i,285,235+i,260);
line(65+i,260,100+i,255);
line(235+i,260,200+i,255);
line(100+i,255,115+i,235);
line(200+i,255,185+i,235);
line(115+i,235,185+i,235);

delay(5);
cleardevice();
}
    getch();
    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();

    return 0;
}

