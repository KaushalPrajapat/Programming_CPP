#include<stdio.h>
#include<graphics.h>

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	
	circle(100,100,20);
	//fillcolor(12);
	getch();
	closegraph();
	
}
