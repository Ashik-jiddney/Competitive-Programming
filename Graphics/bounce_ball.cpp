#include<stdio.h>
#include<graphics.h>
int main()
{
	int gd,gm,x,y,r,i,j=0,maxx,maxy,high;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

	//road
	setcolor(WHITE);
	line(0,401,639,401);

	//ball color & size
	x=20;
	y=380;
	r=20;
	setcolor(RED);
	circle(x,y,r);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(x,y,RED);
	high=300;//max height

	while(high>=0)
	{

		//fall
		for(i=high;i>=0;i--)
		{
			cleardevice();
			setcolor(WHITE);
			line(0,401,639,401);
			if(i%4==0)
				j++;
			x=20+j;
			y=380-i;
			setcolor(WHITE);
			circle(x,y,r);
			floodfill(x,y,WHITE);
			delay(1);
		}
				//jump
		for(i=0;i<=high;i++)
		{
			cleardevice();
			setcolor(WHITE);
			line(0,401,639,401);
			if(i%4==0)
				j++;
			x=20+j;
			y=380-i;              //liner er upor ase drop korbe
			setcolor(WHITE);
			circle(x,y,r);
			floodfill(x,y,WHITE);
			delay(3);
		}
		high=high-50;
	}
	getch();
	closegraph();
	return 0;
}

