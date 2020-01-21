#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    double x1,x2,y1,y2,m;

    int gd=DETECT,gm;

    initgraph(&gd,&gm," ");

    cout << "Enter the x1 and y1 : ";
    cin >> x1 >> y1 ;

    cout << "Enter the x2 y2 : ";
    cin >> x2 >> y2;

    m = (y2-y1)/(x2-x1);

    if(m<=1.0 && m>=-1.0){
        for(int  i=x1 ; i<=x2; i++)
        {
            putpixel(i,y1,10);

            y1+=m;
        }
    }

    else {
    for(int i=y1;i<=y2;i++)
    {
        putpixel(x1,i,10);
        x1+=(1/m);
    }
    }

    getch();
}
