#include <windows.h>
#include<stdio.h>
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include<stdlib.h>
#include<iostream>
//#include<utilapiset.h>              //contains BEEP function

using namespace std;
char findbook;
    //bookData-- id,author,title,Quantity,price,dateofAddingLibrary
FILE *fp,*fp1, *fd;

struct book_Data{
int book_id,book_Quantity;
float book_price;
char book_author[20], book_title[20];
}book,book1;

//All Needed Basics Function

    void gotoxy(int , int);         //Placeement of Text at specific (x,y) position two argument of int
    void delay(unsigned int);       //Make Delay in next execution step, one argument of unsigned int
    //void mainmenu();                //Main menu of the Program or Interface page
    void topLine(char headLine[]);  //Heading line of each Part eg:- ***mainMenu***  Mid text as argument
    void dateTime();                //Real Time Date and time
    void exit(char[]);              //Exit the Program  argument a text where to you wanna exit
    void returnfunc(char[]);

//All Function for Librarian
//addNewBook
void addNewBook();
//removeBook
void removeBook();
//update/editBook
void editBookData();
//searchBook
void searchBook();
//allBooks
void viewAllBook();
//History
//mainMenuLibrarian
void mainMenuLibrary();


//All Function to Store and Manage Student Data
//NewStudent
//RemoveStudent
//EditDataStudent
//SearchA Student
//ShowListByBranch
//mainMenuStudent

int main()
{
//	password();
//    returnfunc("Hello");
    mainMenuLibrary();
}
void mainMenuLibrary()
{
    char line[20] = "MainMenu-Library";
    topLine(line);

    gotoxy(15,4);
    cout<<">>> 1.Add New Book\n";
    gotoxy(15,6);
	cout<<">>> 2.Remove A Book\n";
    gotoxy(15,8);
	cout<<">>> 3.Edit/Update A Book\n";
    gotoxy(15,10);
	cout<<">>> 4.View All Book List\n";
    gotoxy(15,12);
    cout<<">>> 5.Search A Book\n";
	gotoxy(15,14);
	cout<<">>> 6.Library History\n";
	gotoxy(15,16);
	cout<<">>> 7.Exit From Library\n";
	gotoxy(15,19);
	cout<<"Enter Your Choice : ";

	switch(getch())
	{
    case '1':
        addNewBook();
        break;
    case '2':
        removeBook();
        break;
    case '3':
        editBookData();
    case '4':
        viewAllBook();
        break;
    case '5':
        searchBook();
        break;
	  default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		mainMenuLibrary();
    }
}

void addNewBook()
{

    SYSTEMTIME stime;
    GetSystemTime(&stime);
    char addBook[30] = "Add-New-Book-Library";
    topLine(addBook);
	Beep(523,500);
    gotoxy(15,3);
	printf("Give The Details : ");
	gotoxy(10,4);
	printf("Book ID : ");
	scanf("%d",&book.book_id);
	fp = fopen("Lib_Book_Data.txt","r");
    rewind(fp);
    while(fread(&book1,sizeof(book1),1,fp)==1)
    if(book1.book_id==book.book_id)
    {
    	gotoxy(15,25);
    	printf("Book already exist");
        char menuLib[] = "Main-Menu-Library";
        gotoxy(70,25);
        returnfunc(menuLib);
        mainMenuLibrary();
    }
	fclose(fp);

   	fflush(stdin);
	gotoxy(10,5);
	printf("Book Name : ");
	gets(book.book_title);
	gotoxy(10,6);
	printf("Book Author : ");
	gets(book.book_author);
	gotoxy(10,7);
	printf("Book Price : ");
	scanf("%f",&book.book_price);
	gotoxy(10,8);
	printf("Book Quantity : ");
	scanf("%d",&book.book_Quantity);
	gotoxy(10,9);
	dateTime();
    system("cls");
    gotoxy(10,3);
    printf("Entered Book Details Are Under : ");
    gotoxy(10,4);
    printf("Book ID   Book Name     Book Author    Price     Quantity   GrandTotal     Date");
    gotoxy(10,5);
	printf("%d",book.book_id);
	gotoxy(20,5);
	puts(book.book_title);
	gotoxy(35,5);
	puts(book.book_author);
	gotoxy(50,5);
	printf("%.2f",book.book_price);
	gotoxy(60,5);
	printf("%d",book.book_Quantity);
	gotoxy(70,5);
	printf("%.2f",(book.book_price)*(book.book_Quantity));
	gotoxy(85,5);
	dateTime();
	gotoxy(10,7);
	printf("Do You Wanna Save Book Data(y/n) : ");

    if(getch()=='y')
    {
    	fp = fopen("Lib_Book_Data.txt","ab+");
    	fseek(fp,0,SEEK_SET);
    	fwrite(&book,sizeof(book),1,fp);
        fwrite(&stime,sizeof(stime),1,fp);
    	fclose(fp);
    	gotoxy(15,9);
    	printf("Successfully Saved !......");

    	gotoxy(10,10);
    	printf("Wanna Save More Book(y/n)  ");
     	if(getch()=='n')
        {
            char menuLib[] = "Main-Menu-Library";
            gotoxy(70,25);
            returnfunc(menuLib);
            mainMenuLibrary();
    	//returnfunc();
		}
	    else
		{
	    addNewBook();
		}
    }
	else
	    {
            char menuLib[] = "Main-Menu-Library";
            gotoxy(70,25);
            returnfunc(menuLib);
            mainMenuLibrary();
            //returnfunc();
		}
	}

void viewAllBook()
{
    char view[25] = "View-All-Book";
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    system("cls");
    topLine(view);
	int sum = 0, gt = 0, j=7,k=1;
	Beep(630,500);
	gotoxy(5,5);
    printf("S.no. Book ID   Book Name     Book Author    Price     Quantity   GrandTotal    DateTime<Last-Update>");
    fp = fopen("Lib_Book_Data.txt","rb+");
//    fp1 = fopen("test","ab+");
    while(fread(&book,sizeof(book),1,fp)==1 && fread(&stime,sizeof(stime),1,fp)==1)
    {
    gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",book.book_id);
	gotoxy(21,j);
	puts(book.book_title);
	gotoxy(35,j);
	puts(book.book_author);
	gotoxy(50,j);
	printf("%.2f",book.book_price);
	gotoxy(60,j);
	printf("%d",book.book_Quantity);
	gotoxy(71,j);
	printf("%.2f",(book.book_price)*(book.book_Quantity));

	gotoxy(85,j);
    cout<<stime.wDay<<"."<<stime.wMonth<<"."<<stime.wYear<<"/"<<(stime.wHour+5)%12<<"."<<(stime.wMinute+30)%60<<"."<<stime.wSecond<<"\n";

	j++,k++;
	delay(100);
	gt = gt + (book.book_price)*(book.book_Quantity);
	sum = sum + book.book_Quantity;
    }
    gotoxy(5,j+5);
    printf("Total Books in Library : %d",sum);
    gotoxy(50,j+5);
    printf("Total Price of Books in Library : %d",gt);
    //Beep(600,600);
    fclose(fp);
    {
    gotoxy(80,j+10);
	{printf("Press AnyKey to Return Main Menu"); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
    char menuLib[] = "Main-Menu-Library";
    gotoxy(70,25);
    returnfunc(menuLib);
    mainMenuLibrary();    }
}
}

void searchBook()
{
    char menuLib[] = "Main-Menu-Library";

    system("cls");
	SYSTEMTIME stime;
    GetSystemTime(&stime);
    char searchBox[20] = "Search-Book";
    topLine(searchBox);
    Beep(400,500);
    int d,a;
    char book_title[20];
	fp=fopen("Lib_Book_Data.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
	while(getch()!=0)
	{

    {
        gotoxy(20,4);
        printf(">>> 1. Search With Book Id");
        gotoxy(20,5);
        cout<<">>> 2. Search With Title : ";
        cin>>a;
        gotoxy(20,6);
        switch(a)
        {
            case 1:
            printf("Enter the book id : ");
            scanf("%d",&d);
            break;
            case 2:
            printf("Enter Book-Title : ");
            fflush(stdin);
            gets(book_title);
            break;
            default:
                cout<<"Wrong choice";
        }
        gotoxy(20,7);
		char text1[] = "Searching............";
		    gotoxy(20,7);
			for(int k=0; k<(strlen(text1)); k++)
		    {
		    	printf("%c",text1[k]);
		    	delay(30);
	        }
	    while(fread(&book,sizeof(book),1,fp)==1 && fread(&stime,sizeof(stime),1,fp)==1)
        {
        if(book.book_id == d || strcmp(book.book_title,book_title) == 0 )
        {
            delay(2);
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            gotoxy(20,9);
            printf("BOOK ID         : %d",book.book_id);
            gotoxy(20,10);
            printf("BOOK Name       : %s",book.book_title);
            gotoxy(20,11);
            printf("BOOK Author     : %s ",book.book_author);
            gotoxy(20,12);
            printf("BOOK Qantity    : %d ",book.book_Quantity);
            gotoxy(20,13);
            printf("BOOK Price      : Rs.%.2f",book.book_price);
            gotoxy(20,14);
            printf("Grand Total     : %f ",book.book_price*book.book_Quantity);
            gotoxy(20,15);

            cout<<"Last Update      :"<<stime.wDay<<"."<<stime.wMonth<<"."<<stime.wYear<<"/"<<(stime.wHour+5)%12<<"."<<(stime.wMinute+30)%60<<"."<<stime.wSecond<<"\n";
            Beep(500,500);
			findbook='t';
        }

        }
        if(findbook!='t')  //checks whether condition enters inside loop or not
        {
        gotoxy(22,9);
        printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchBook();
        else
        gotoxy(70,25);
        returnfunc(menuLib);
        mainMenuLibrary();
        //returnfunc();
        break;
    }
    }
    getch();
    searchBook();
    fclose(fp);
}

void removeBook()
{
	Beep(2000,800);
	system("cls");
	SYSTEMTIME stime;
    GetSystemTime(&stime);
	int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
    system("cls");
	char removeData[20] = "Remove-Data";
	topLine(removeData);
    gotoxy(10,5);
    printf("Enter the Book ID to  delete:");
    scanf("%d",&d);
    fp=fopen("Lib_Book_Data.txt","rb+");
    rewind(fp);
    while(fread(&book,sizeof(book),1,fp)==1 && fread(&stime,sizeof(stime),1,fp)==1)
    {
        if(book.book_id==d)
        {

        gotoxy(10,7);
        printf("The book record is available");
        gotoxy(10,8);
        cout<<"Zero Book will left in Library";
        gotoxy(10,10);
        printf("Book name is     : %s",book.book_title);
        gotoxy(10,11);
        printf("Quantity of Book : %d",book.book_Quantity);
        findbook='t';
        getch();
        }
    }
    fclose(fp);
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found");
        gotoxy(10,12);
        cout<<"Returning..........";
        delay(500);
        if(getch())
        mainMenuLibrary();
    }
    if(findbook=='t' )
    {
        gotoxy(10,15);

        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        fp = fopen("Lib_Book_Data.txt","rb+");
        fd=fopen("Temp.txt","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&book,sizeof(book),1,fp)==1)
        {
            if(book.book_id!=d)
            {
            fseek(fd,0,SEEK_CUR);
            fwrite(&book,sizeof(book),1,fd); //write all in temporary file except that
            }                              //we want to delete
        }
        fclose(fd);
        fclose(fp);
        remove("Lib_Book_Data.txt");
        rename("Temp.txt","Lib_Book_Data.txt"); //copy all item from temporary file to fp except that
        fp=fopen("Lib_Book_Data.txt","r");    //we want to delete
        if(findbook=='t')
        {
            gotoxy(10,17);
            printf("The record is successfully deleted");
            Beep(1000,300);
			gotoxy(10,18);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainMenuLibrary();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainMenuLibrary();
}

void editBookData()
{
    	Beep(1500,600);
    int c=0;
    int d,e;
    system("cls");
    char editBookData[20] = "Edit-Book-Data";
    topLine(editBookData);

	char another='y';
    while(another=='y')
    {

        gotoxy(15,6);
        printf("Enter Book Id to be edited:");
        scanf("%d",&d);


        fp = fopen("Lib_Book_Data.txt","rb+");
        rewind(fp);
	    while(fread(&book,sizeof(book),1,fp)==1)
	    {
            if(book.book_id==d)
            {
                gotoxy(15,7);
                printf("The book is availble   %d",book.book_id);
                gotoxy(15,8);
                printf("The Book ID : %d",d);
                gotoxy(15,9);
                printf("Enter new name:");scanf("%s",book.book_title);
                gotoxy(15,10);
                printf("Enter new Author : ");scanf("%s",book.book_author);
                gotoxy(15,11);
                printf("Enter new quantity : ");scanf("%d",&book.book_Quantity);
                gotoxy(15,12);
                printf("Enter new price : ");scanf("%f",&book.book_price);
                gotoxy(15,14);

                printf("The record is modified");
                Beep(523,500);


			    fseek(fp,ftell(fp)-sizeof(book),0);
                fwrite(&book,sizeof(book),1,fp);
                fclose(fp);
                c=1;
                }
            if(c==0)
                {
                gotoxy(15,9);
                printf("No record found");
                }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    char menuLib[] = "Main-Menu-Library";
    gotoxy(70,25);
    returnfunc(menuLib);
    mainMenuLibrary();
//	returnfunc();

}

void returnfunc(char *text2)
{
    char returntext[] =" Returning...........";
    cout<<"To ";
    for(int j=0; j<(strlen(text2)); j++)
    {
    	cout<<text2[j];
    	delay(100);
    }
    for(int j=0; j<(strlen(returntext)); j++)
    {
    	printf("%c",returntext[j]);
    	delay(100);
    }

}
COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void topLine(char *headline)
{
    system("cls");
	char wlf[25] = "|********************** ";
	char wll[25] = " **********************|";
	gotoxy(15,2);
	for(int i=0; i<strlen(wlf); i++)
	{
	cout<<wlf[i];
	delay(10);
    }
    cout<<headline;

	for(int i=0; i<strlen(wll); i++)
	{
	cout<<wll[i];
	delay(10);
    }
    gotoxy(71,3);
    cout<<"Date & Time\n";
    gotoxy(71,4);
    dateTime();
    Beep(700,500);

}

void exit(char *place)
{
	system("cls");
	gotoxy(0,14);
	for(int i =0; i<120; i++)
	{
		printf("%c",177);
	}
	gotoxy(0,16);
	for(int i =0; i<120; i++)
	{
		printf("%c",177);
	}
	gotoxy(55,15);
	printf("Thanks to use Our");
	cout<<place;
    gotoxy(50,17);
    cout<<"Press any key for exit(Except Enter) ";
    for(int i=0; i<5; i++)
	{
	Beep(523,200);
	delay(200);
    }
    if(getch()!=13)
	exit(0);
}

void dateTime()
{

	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("%d-%d-%d / %d.%d.%d",stime.wDay,stime.wMonth,stime.wYear,stime.wHour+5,stime.wMinute+30,stime.wSecond);
}
