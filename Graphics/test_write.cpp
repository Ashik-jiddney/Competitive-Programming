// C++ implementation for
// settextstyle() function
#include <graphics.h>

// driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading
    // a graphics driver from disk
    initgraph(&gd, &gm, "");

    // location of text
    int x0 = 150, x1 = 200;
    int y0 = 150, y1 = 200;

    // font style
    int font1 = 8, font2 = 9;

    // font direction #  For the horizontal direction, value zero (0) and the value one (1) is passed for the vertical direction.
    int direction = 0;

    // font size
    int font_size1 = 5, font_size2 = 10;

    // for setting text style
    settextstyle(font1, direction, font_size1);
    //for color of
    setcolor(5);
    // for printing text in graphics window
    outtextxy(x0, y0, "Ashik");


    // for setting text style
    settextstyle(font2, direction, font_size2);
    //for color of
    setcolor(10);
    // for printing text in graphics window
    outtextxy(x1, y1, "Ashik");
    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by graphics
    // system .
    closegraph();

    return 0;
}
