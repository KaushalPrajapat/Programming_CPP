
#include <windows.h>
#include<stdio.h>                  
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include<utilapiset.h>  

void rating_app();

struct rating
{
	int rate;
	char name[22];
}rt;
int main()
{
    rating_app();
	getch()	;
}

void rating_app()
{
	FILE *fp;
	Beep(900,500);
	system("cls");
	char wl[50] = "******************> HOME <******************";
	//gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	//delay(10);
    }
    //gotoxy(15,4);
    printf("\nRate Our Application");
    //gotoxy(15,6);
    printf("\nEnter Your Name");
    gets(rt.name);
    printf("\n0 for Bad and 10 for best");
    scanf("%d",&rt.rate);
    
	
	fp = fopen("rating.txt","ab+");
    	fseek(fp,0,SEEK_SET);
    	fwrite(&rt,sizeof(rt),1,fp);
    	fclose(fp);
    	//gotoxy(15,9);
    	printf("Successfully Saved !......");

}
