#include<graphics.h>
#include<bits/stdc++.h>

int main()
{
    int gd = DETECT,gm;
//    char data[] ="C:\\MinGW\\lib\\libbgi.a";

    initgraph(&gd,&gm,NULL);
     setcolor(WHITE);

    circle(320,240,150);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(320,240,WHITE);

    setcolor(BLACK);
    //eyes
    circle(280,200,30);
    circle(360,200,30);
    floodfill(280,200,BLACK);
    floodfill(360,200,BLACK);

    //iris
   
    ellipse(280,224,0,180,15,15);
    ellipse(360,224,0,180,15,15);

     setcolor(WHITE);
    // ears
    ellipse(185,170,45,250,60,70);
    ellipse(455,170,290,135,60,70);

     setcolor(BLACK);
    //mouth
    ellipse(315,300,180,360,60,50);
    // line(220,310,420,310);
    getch();
    //delay(500000000);

    closegraph();
    return 0;
}