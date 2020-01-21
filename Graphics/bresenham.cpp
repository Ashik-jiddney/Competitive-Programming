#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2)
{
    int dy,dx,incE,incNE,d,x,y=y1;
    dy = (y2-y1);
    dx = (x2-x1);
    d = 2*dy - dx;
    incE = 2*dy;
    incNE = 2*(dy-dx);

    for(x=x1;x<=x2;x++)
    {
        putpixel(x,y,10);
        cout << x << " " << y << '\n';

        if(d>0)
        {
           d = d+incNE;
           y++;
        }
        else d = d+incE;

    }
    return;
}

int main()
{
    int x1,x2,y1,y2,gd=DETECT,gm;

    initgraph(&gd,&gm," ");

    cout << "Enter the starting co-ordinate : ";
    cin >> x1 >> y1 ;

    cout << "Enter the Second Co-ordinate : ";
    cin >> x2 >> y2;

    bresenham(x1,y1,x2,y2);

    getch();
}
