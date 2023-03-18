#include <iostream>
#include "graphics2.h"
#include <cmath>
#include <time.h>
#include <windows.h>
using namespace std;

const DWORD screen_width=GetSystemMetrics(SM_CXSCREEN);
const DWORD screen_height=GetSystemMetrics(SM_CYSCREEN);
const double rad=(3.14/180);

int n,lg,color,angle=0;
int driver, mod;

void dragon(int,int,int);
int main()
{
    srand(time(NULL));
    initgraph(&driver, &mod, "Dragon's Curve", screen_width, screen_height);
    setbkcolor(BLACK);
    cleardevice();
    int midx=getmaxx()/2, midy=getmaxy()/2;
    settextstyle(7,0,10);
    outtextxy(midx-500,midy-500,"Dragon's Curve");
    n=18; lg=2;
    moveto(midx-500,midy-200);
    dragon(0,1,1);
    while(!kbhit());
    closegraph();
    return 0;
}
void dragon(int k, int semn, int dir)
{
    setcolor(rand()%16+1);
    double pozx, pozy;
    //cout<<k<<' ';
    if(k<n)
    {
        if(dir==1)
        {
            dragon(k+1,1,1);
            angle+=(semn*90);
            dragon(k+1,-1,2);
            pozx=sin(angle*rad);
            pozy=cos(angle*rad);
            linerel(pozx*lg,pozy*lg); //Sleep(1000);
            angle+=(semn*90);
        }
        else if(dir==2)
        {
            angle+=(semn*90);
            pozx=sin(angle*rad);
            pozy=cos(angle*rad);
            linerel(pozx*lg,pozy*lg); //Sleep(1000);
            dragon(k+1,1,1);
            angle+=(semn*90);
            dragon(k+1,-1,2);
        }
    }
}
