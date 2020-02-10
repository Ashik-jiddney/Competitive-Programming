#include<bits/stdc++.h>
#include<graphics.h>
int orbital(int x1,int y1,int r1){
int x0=x1,y0=y1,r=r1,d,x,y;
x=0;
y=r;
d=1-r;
while(y>x)
{
        if(d<0)
        {
            d+=2*x+3;
        }

        else
            {
                d+=2*(x-y)+5;
                y=y-1;
            }
            x=x+1;


    putpixel(x0+x,y0+y,15);
	putpixel(x0+x,y0-y,15);
	putpixel(x0-x,y0+y,15);
	putpixel(x0-x,y0-y,15);
	putpixel(x0+y,y0+x,15);
	putpixel(x0+y,y0-x,15);
	putpixel(x0-y,y0+x,15);
	putpixel(x0-y,y0-x,15);

}
}
int main(){
    int x0=200,y0=200,r=10,d,x,y;
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    for(int i=0;i<=7;i++){orbital(x0,y0,r);r=r+10;}
    //planet
    circle(207,207,5);
    setfillstyle(SOLID_FILL,RED);
    floodfill(209,209,15);
    floodfill(206,206,15);

    circle(187,187,5);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(188,188,15);
    floodfill(185,185,15);

    circle(223,182,5);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(224,183,15);
    floodfill(225,182,15);

    circle(223,182,5);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(224,183,15);
    floodfill(225,182,15);

    circle(172,230,5);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(172,231,15);
    floodfill(172,228,15);

    circle(201,150,5);
    setfillstyle(SOLID_FILL,3);
    floodfill(202,151,15);

    circle(201,260,5);
    setfillstyle(SOLID_FILL,5);
    floodfill(202,261,15);

    circle(270,200,5);
    setfillstyle(SOLID_FILL,12);
    floodfill(271,201,15);

    circle(120,200,5);
    setfillstyle(SOLID_FILL,13);
    floodfill(121,201,15);


	getch();
	closegraph();

}
