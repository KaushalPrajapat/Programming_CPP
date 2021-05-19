#include<graphics.h>
#include<conio.h>
//#include<stdio.h>
#include<time.h>
int main()
{
int gd=DETECT,gm = DETECT;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(1);
line(0,400,640,400);
setcolor(2);
circle(175,375,25);
circle(325,375,25);
setfillstyle(1,2);
floodfill(175,375,2);
floodfill(325,375,2);
setcolor(9);
line(205,375,295,375);
ellipse(175,375,0,180,30,30);
ellipse(325,375,0,180,30,30);
line(170,275,335,275);
line(145,375,130,375);
line(355,375,390,375);
ellipse(175,375,90,180,45,100);
ellipse(325,375,0,90,65,100);
setfillstyle(11,3);
floodfill(200,320,9);
//line(190,255,320,255);
//line(175,275,190,255);
setcolor(7);
rectangle(180,255,325,275);    //rectangle up on car
ellipse(180,275,90,182,15,20); //ellipse up side  rectangle
ellipse(325,275,-5,90,15,20);
setfillstyle(7,12);
floodfill(324,274,7);
rectangle(180,263,325,269);
getch();
closegraph();
}

