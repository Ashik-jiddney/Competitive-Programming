#include<bits/stdc++.h>
#include<graphics.h>

int main(){
    int x0=200,y0=200,r=10,c=5,d,x,y;
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    circle(300,100,35);
    circle(290,99,5);
    circle(311,99,5);
    ellipse(300, 110, 210, 330, 20, 15);

    line(300,105,300,115);
    line(300,135,300,300);
    line(300,180,230,230);
    line(300,180,370,230);
    line(300,300,230,360);
    line(300,300,370,360);

	getch();
	closegraph();

}

