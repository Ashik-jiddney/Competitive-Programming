
#include<bits/stdc++.h>
#include<graphics.h>

int ellipsee(int xc,int yc,int a, int b){
    int x,y,p;
x=0;
y=b;
 //Region 1
 p=(b*b)-(a*a*b)+(0.25*a*a);
 do
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p<0)
  {
   x=x+1;
   p=p+2*b*b*x+b*b;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p+2*b*b*x-2*a*a*y+b*b;
  }
 }while(2*b*b*x<2*a*a*y);
 //Region 2
 p=(b*b*(x+0.5)*(x+0.5))+((y-1)*(y-1)*a*a-a*a*b*b);
 do
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,BLUE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p>0)
  {
   y=y-1;
   p=p-2*a*a*y+a*a;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p-2*a*a*y+2*b*b*x+a*a;
  }
 }while(y!=0);
}




int main()
{
    int xc,yc,x2,y2,r,d,x,y,a,b;
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");

    setcolor(RED);
    xc=200,yc=100,a=50,b=30;
	for(int i=0;i<=2;i++){
    ellipsee(xc,yc,a,b);

  setfillstyle(SOLID_FILL, RED);
    fillellipse(xc,yc,a,b);
    floodfill(xc,yc,RED);

    xc=xc+50;
    }



	getch();
	closegraph();

}
