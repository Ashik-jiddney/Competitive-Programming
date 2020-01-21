#include<bits/stdc++.h>
#include <graphics.h>

using namespace std;

void midPointCircle(int x1, int y1, int r)
{
    int x=0, y=r, d=1-r;

    putpixel(x,y,10);

    while(y>x)
    {
        cout << x+x1 << " " << y+y1 << "\n";
        if(d<0){
            d += 2*x + 3; ///select S
        }
        else {
            d += 2*(x-y)+5;
            y--;
        }
        x++;
        putpixel(x,y,10);
    }

    return;
}

int main()
{
    int centerX,centerY,radius,gd=DETECT,gm;

    initgraph(&gd,&gm," ");

    cout << "Enter the Center co-ordinate and radius of the circle : ";

    cin >> centerX >> centerY >> radius;

    midPointCircle(centerX,centerY,radius);

    getch();
}
