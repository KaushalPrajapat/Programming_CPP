/*	\\---------------------------------------------------------------------------------------------------------------------------------------------//
*	 \\---------------SCHOOL MANAGMENT PROGRAM -------------- Using C language ------------------- in May 2019------------------------------------//
*	  \\------------------------------------------------------------------------------------------Updade on 22.Jan-2021--------------------------//
*	   \\---------------------------------------------------------------------------------------------------------------------------------------//
*	    \\-------------------------------------------------------BY - Er. Kaushal Prajapat-----------------------------------------------------//
*		 \\																																	  //
*		  \\ Functunalities -- 																												 //
*							1.Library Management 
*							2.School Managment
*							3.Principle Page
*							4.Managment Shell
*							5.App Rating System and Record
*
*
*  ``````````````````````````For More Information Contact at prajapatkaushal555@gmail.com or Phone . 9772774141`````````````````````//
*/


#include <windows.h>
#include<stdio.h>                  
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#include<utilapiset.h>              //contains BEEP function
int grandtotal;
FILE *fp,*fd;
struct book
{
	int id,qnty;
	float price;
	char bname[20],author[20];
}b,b1;
struct student
{
	int sid,sage,sclass,lib_id;
	char sname[20];
}s1,s2;
struct update_issue1
{
	int sl_id,s_id,b_id;
	char s_name[20],b_name[20];
}up,up1;
struct rating
{
	int rate;
	char name[22];
}rt;
 
void rate_app();
void viewRating();
void get_time();
void home();
	void addstudent();
	void removestudent();
	void showstudents();
	void searchstudent();
    void editstudent();
void password_managment();
void password_library();
void password_principle();


char findbook;
	void addbook();
	void removebook();
	void searchbook();
	void editbook();
	void viewbooks();
	void exit();


    void issue_book();
    void return_book();
    void return_update_book(int d);
    void update_return();
    void give_book();
    void update();
    void get_issued_data();
void mainmenulibrary();
void mainmenu_managment_cell();
void mainmenu_student();
void mainmenu_principle();


void borrow_return_menu();
void return_update(int x);
void back_book();
    void borrow_return_menu_issue_book();
	void borrow_return_menu_return_book();
	void borrow_return_menu_get_issued_data();
	
    
    void student_searchbook();
    void student_viewbooks();
    void student_searchstudent();
    void student_showstudents();
void aboutschool();
void home();
void home_return_func();
void delay(unsigned int mseconds);
void gotoxy(int, int);

main()
{
   home();
}




void home()
{
	system("cls");
	char wl[100] = "************************> HOME <****************************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(900,500);
    gotoxy(15,4);
    printf(">>> 1.For Librarion only\n");
    gotoxy(15,6);
	printf(">>> 2.For Managment Cell Only\n");
    gotoxy(15,8);
	printf(">>> 3.For Student about Library\n");
    gotoxy(15,10);
	printf(">>> 4.Principle\n");
    gotoxy(15,17);
	printf("Press Enter to Show About School");
	gotoxy(15,12);
	printf(">>> 5.View Application Rating\n");
	gotoxy(15,14);
	printf(">>> 6. EXIT");
	gotoxy(15,21);
	printf("Enter Your Choice : ");
	
	gotoxy(90,30);
    char rg[50] = ">>> Made By KAUSHAL <<<";
	for(int i=0; i<strlen(rg); i++)
	{
	printf("%c",rg[i]);
	delay(20);
    }
	switch(getch())
	{
	case '1' :
		password_library();
	    mainmenulibrary();
	    break;
	case '2' :
		password_managment();
		mainmenu_managment_cell();
		break;
	case '3' :
		mainmenu_student();
		break;
	case '4' :
		password_principle();
		mainmenu_principle();
		break;
	case '5' :
		viewRating();
		break;
	case '6' :
	    exit();
	    break;
    case 13:
    	aboutschool();
    	break;
	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		home();
    }
}
void mainmenulibrary()
{
	system("cls");
	char wl[70] = "******************> MAINMENU OF LIBRARY <******************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(700,500);
    gotoxy(15,4);
    printf(">>> 1.Add New Book\n");
    gotoxy(15,6);
	printf(">>> 2.Remove A Book\n");
    gotoxy(15,8);
	printf(">>> 3.Edit A Book\n");
    gotoxy(15,10);
	printf(">>> 4.View All Book List\n");
    gotoxy(15,12);
    printf(">>> 5.Search A Book\n");
    gotoxy(15,25);
    printf(">>> 7.Show Issued Book List");
	gotoxy(15,14);
	printf(">>> 6.Exit From Library\n");
	gotoxy(15,16);
	printf(">>> 9.Back to Home Page");
	gotoxy(15,18);
	printf(">>> 8.View rating for Library");
	
	gotoxy(15,21);
	printf("Enter Your Choice : ");

	switch(getch())
    {
    case '8':
   		viewRating();
   		break;
	case '7' :
		get_issued_data();
		break;
	case '1' :
	    addbook();
	    break;
	case '2' :
		removebook();
		break;
	case '3' :
		editbook();
	    break;
	case '4' :
		viewbooks();
		break;
	case '5' :
		searchbook();
		break;
	case '6' :
	    exit();
	    break;
   case  '9' :
   	    home_return_func();
   	    break;
	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		mainmenulibrary();
    }
}
void mainmenu_managment_cell()
{
	system("cls");
	char wl[70] = "******************> MAINMENU OF MANAGMENT-CELL <******************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(700,500);
    gotoxy(15,4);
    printf(">>> 1.Add New Admission\n");
    gotoxy(15,6);
	printf(">>> 2.Remove a Student\n");
    gotoxy(15,8);
	printf(">>> 3.Edit A Student Data\n");
    gotoxy(15,10);
	printf(">>> 4.View All Students List\n");
    gotoxy(15,12);
    printf(">>> 5.Search A Student\n");
	gotoxy(15,14);
	printf(">>> 6.Return to Home Page\n");
	gotoxy(15,16);
	printf(">>> 9.Back to Home");
	gotoxy(15,19);
	printf("Enter Your Choice : ");

	switch(getch())
	{
	case '9' :
		home();
	case '1' :
	    addstudent();
	    break;
	case '2' :
		removestudent();
		break;
	case '3' :
		editstudent();
	    break;
	case '4' :
		showstudents();
		break;
	case '5' :
		searchstudent();
		break;
	case '6' :
	    exit();
	    break;

	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		home();
    }
}

void mainmenu_student()
{
	system("cls");
	char wl[70] = "******************> MAINMENU OF FOR STUDENT <******************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(700,500);
    gotoxy(15,4);
    printf(">>> 1.View all Books In Library\n");
    gotoxy(15,6);
	printf(">>> 2.Search Book in Library\n");
    gotoxy(15,8);
	printf(">>> 3.Wanna Borrow or Return Book\n");
    gotoxy(15,10);
	printf(">>> 4.Search About a Student \n");
	gotoxy(15,12);
	printf(">>> 6.EXIT\n");
	gotoxy(15,14);
	printf(">>> 9.Back to Home");
	gotoxy(15,19);
	printf("Enter Your Choice : ");

	switch(getch())
	{
	case '9' :
		home();
	case '1' :
	    student_viewbooks();
	    break;
	case '2' :
		student_searchbook();
		break;
	case '3' :
		borrow_return_menu();
		break;
	case '4' :
		student_searchstudent();
		break;
	case '6' :
	    exit();
	    break;

	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		home();
    }

}

void mainmenu_principle()
{
	system("cls");
	char wl[70] = "******************> MAINMENU OF FOR PRINCIPLE <******************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(700,500);
    gotoxy(15,4);
    printf(">>> 1.ACCESS TO LIBRARY\n");
    gotoxy(15,6);
	printf(">>> 2.ACCESS TO MANAGMENT GROUP OF TEACHER\n");
    gotoxy(15,8);
	printf(">>> 3.ACCESS TO STUDENT MENU\n");
	gotoxy(15,10);
	printf(">>> 6.EXIT\n");
	gotoxy(15,12);
	printf(">>> 9.Back to Home");
	gotoxy(15,19);
	printf("Enter Your Choice : ");

	switch(getch())
	{
	case '9' :
		home();
	case '1' :
	    mainmenulibrary();
	    break;
	case '2' :
		mainmenu_managment_cell();
		break;
	case '3' :
		mainmenu_student();
		break;
	case '6' :
	    exit();
	    break;

	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		home();
    }

}




void addbook()
{
	 
	system("cls");
	char text[] = "***************************** ADD BOOK *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
  
	Beep(523,500);
    gotoxy(15,3);
	printf("Give The Details : ");
	gotoxy(10,4);
	printf("Book ID : ");
	scanf("%d",&b.id);
	fp = fopen("LIB_MEGE.txt","r");
    rewind(fp);
    while(fread(&b1,sizeof(b1),1,fp)==1)
    if(b1.id==b.id)
    {
    	gotoxy(15,25);
    	printf("Book already exist");
    	delay(500);
    	mainmenulibrary();
	}
	fclose(fp);
   
   	fflush(stdin);
	gotoxy(10,5);
	printf("Book Name : ");
	gets(b.bname);
	gotoxy(10,6);
	printf("Book Author : ");
	gets(b.author);
	gotoxy(10,7);
	printf("Book Price : ");
	scanf("%f",&b.price);
	gotoxy(10,8);
	printf("Book Quantity : ");
	scanf("%d",&b.qnty);
    system("cls");
    gotoxy(10,3);
    printf("Entered Book Details Are Under : ");
    gotoxy(10,4);
    printf("Book ID   Book Name     Book Author    Price     Quantity   GrandTotal");
    gotoxy(10,5);
	printf("%d",b.id);
	gotoxy(20,5);
	puts(b.bname);    
	gotoxy(35,5);
	puts(b.author);
	gotoxy(50,5);
	printf("%.2f",b.price);
	gotoxy(60,5);
	printf("%d",b.qnty);
	gotoxy(70,5);
	printf("%.2f",(b.price)*(b.qnty));
	gotoxy(10,7);
	printf("Do You Wanna Save Book Data(y/n) : ");

    if(getch()=='y')
    {
    	fp = fopen("LIB_MEGE.txt","ab+");
    	fseek(fp,0,SEEK_SET);
    	fwrite(&b,sizeof(b),1,fp);
    	fclose(fp);
    	gotoxy(15,9);
    	printf("Successfully Saved !......");
    	gotoxy(10,10);
    	printf("Wanna Save More Book(y/n)  ");
     	if(getch()=='n')
        {
    	mainmenulibrary();
		}
	    else
		{
	    addbook();
		}
    }
	else
	    {
	    mainmenulibrary();
		}
	}

void searchbook()
{
	Beep(400,500);
	int d;
    system("cls");	
    char text[] = "******************************** SEARCH BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}gotoxy(20,10);
//    printf("1. Search By ID");
    fp=fopen("LIB_MEGE.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
	while(getch()!=0)
	{
      
    {
//        system("cls");
        gotoxy(25,4);
        printf("****Search Books By Id****");
        gotoxy(20,5);
        printf("Enter the book id:");
        scanf("%d",&d);
        gotoxy(20,7);
		char text1[] = "Searching............";
		    gotoxy(20,7);
			for(int k=0; k<(strlen(text1)); k++)
		    {
		    	printf("%c",text1[k]);
		    	delay(30);
	        }
	    while(fread(&b,sizeof(b),1,fp)==1)
        {
        if(b.id==d)
        {
            delay(2);
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            gotoxy(20,9);
            printf("BOOK ID        : %d",b.id);
            gotoxy(20,10);
            printf("BOOK Name      : %s",b.bname);
            gotoxy(20,11);
            printf("BOOK Author    : %s ",b.author);
            gotoxy(20,12);
            printf("BOOK Qantity   : %d ",b.qnty);
            gotoxy(20,13);
            printf("BOOK Price     : Rs.%.2f",b.price);
            gotoxy(20,14);
            printf("Grand Total    : %f ",b.price*b.qnty);
            gotoxy(20,15);
            Beep(500,500);
			findbook='t';
        }
 
        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchbook();
        else
        mainmenulibrary();
        break;
    }
    }
    getch();
    searchbook();  
    fclose(fp);
}

void viewbooks()
{
	Beep(700,700);
    system("cls");	
    char text[] = "******************************** VIEW BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int sum = 0, gt = 0, j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no. Book ID   Book Name     Book Author    Price     Quantity   GrandTotal");
    fp = fopen("LIB_MEGE.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1)
    {
	gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",b.id);
	gotoxy(20,j);
	puts(b.bname);    
	gotoxy(35,j);
	puts(b.author);
	gotoxy(50,j);
	printf("%.2f",b.price);
	gotoxy(60,j);
	printf("%d",b.qnty);
	gotoxy(71,j);
	printf("%.2f",(b.price)*(b.qnty));
	j++,k++;
	delay(100);
	gt = gt + (b.price)*(b.qnty);
	sum = sum + b.qnty;
    }
    gotoxy(5,j+5);
    printf("Total Books in Library : %d",sum);
    gotoxy(50,j+5);
    printf("Total Price of Books in Library : %d",gt);
    //Beep(600,600);
    fclose(fp);
    {
    gotoxy(80,j+10);   
	{printf("Press AnyKey to Return MAIN MENU LIBRARY"); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
	printf("Returning in 2 Seconds");
	delay(2000);
	mainmenulibrary();
    }
}
}

void editbook()
{
	Beep(1500,600);
    int c=0;
    int d,e;
    system("cls");	
    char text[] = "******************************** EDIT BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
	char another='y';
    while(another=='y')
    {
       // system("cls");
        gotoxy(15,6);
        printf("Enter Book Id to be edited:");
        scanf("%d",&d);

        fp = fopen("LIB_MEGE.txt","rb+");
        rewind(fp);
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
            if(b.id==d)
            {
                gotoxy(15,7);
                printf("The book is availble   %d",b.id);
                gotoxy(15,8);
                printf("The Book ID : %d",d);
                gotoxy(15,9);
                printf("Enter new name:");scanf("%s",b.bname);
                gotoxy(15,10);
                printf("Enter new Author : ");scanf("%s",b.author);
                gotoxy(15,11);
                printf("Enter new quantity : ");scanf("%d",&b.qnty);
                gotoxy(15,12);
                printf("Enter new price : ");scanf("%f",&b.price);
                gotoxy(15,14);
                
                printf("The record is modified");
                Beep(523,500);
               
             
			    fseek(fp,ftell(fp)-sizeof(b),0);
                fwrite(&b,sizeof(b),1,fp);
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
        if(getch()=='y')
        {
        	editbook();
		}
		else
		{
			mainmenulibrary();
		}
    }
	mainmenulibrary();
}

void removebook()
{
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** REMOVE BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
//    system("cls");
    gotoxy(10,5);
    printf("Enter the Book ID to  delete:");
    scanf("%d",&d);
    fp=fopen("LIB_MEGE.txt","rb+");
    rewind(fp);
    while(fread(&b,sizeof(b),1,fp)==1)
    {
        if(b.id==d)
        {
 
        gotoxy(10,7);
        printf("The book record is available");
        gotoxy(10,8);
        printf("Book name is     : %s",b.bname);
        gotoxy(10,9);
        printf("Quantity of Book : %d",b.qnty);
        findbook='t';
        }
    }
    fclose(fp);
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        mainmenulibrary();
    }
    if(findbook=='t' )
    {
        gotoxy(10,12);
        
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        fp = fopen("LIB_MEGE.txt","rb+");
        fd=fopen("Temp.txt","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&b,sizeof(b),1,fp)==1)
        {
            if(b.id!=d)
            {
            fseek(fd,0,SEEK_CUR);
            fwrite(&b,sizeof(b),1,fd); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(fd);
        fclose(fp);
        remove("LIB_MEGE.txt");
        rename("Temp.txt","LIB_MEGE.txt"); //copy all item from temporary file to fp except that
        fp=fopen("LIB_MEGE.txt","r");    //we want to delete
        if(findbook=='t')
        {   
            gotoxy(10,15);
            printf("The record is sucessfully deleted");
            Beep(1000,300);
			gotoxy(10,16);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    home();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenulibrary();
}

void password_library()
{
	char password1[] = "kaushal",pass[8],ch;
	int i=0;
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** Password Protected Library *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    gotoxy(10,5);
    printf("Enter password_library : ");
    while(ch!=13)
   {
    ch=getch();
 
    if(ch!=13 && ch!=8){
    putch('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
	if(strcmp(pass,password1)==0)
	{
		gotoxy(10,8);
		printf("Password Match");
		gotoxy(10,9);
		printf("Press AnyKey to Continue");
		if(getch()!=0)
		
		mainmenulibrary();
	}
	
	int z;
	if(strcmp(pass,password1)!=0)
		{
		for(z=3; z>0; z--)
		{
		gotoxy(10,8);
		printf("Password Error");
		gotoxy(10,9);
		printf("Retry");
		delay(1000);
		password_library();
	    }
        }
}

void password_managment()
{
	char password1[] = "kaushal",pass[15],ch;
	int i=0;
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** Password Protected Cell *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    gotoxy(10,5);
    printf("Enter password Managment-Cell : ");
    while(ch!=13)
   {
    ch=getch();
 
    if(ch!=13 && ch!=8){
    putch('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
	if(strcmp(pass,password1)==0)
	{
		gotoxy(10,8);
		printf("Password match");
		gotoxy(10,9);
		printf("Press AnyKey to Continue");
		if(getch()!=0)
		
		mainmenu_managment_cell();
	}
	
	int z;
	if(strcmp(pass,password1)!=0)
		{
		for(z=3; z>0; z--)
		{
		gotoxy(10,8);
		printf("Password Error");
		gotoxy(10,9);
		printf("Retry");
		delay(1000);
		password_managment();
	    }
        }
}

void password_principle()
{
	char password1[] = "kaushal",pass[8],ch;
	int i=0;
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** Password Protected  *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    gotoxy(10,5);
    printf("Enter Principle password : ");
    while(ch!=13)
   {
    ch=getch();
 
    if(ch!=13 && ch!=8){
    putch('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
	if(strcmp(pass,password1)==0)
	{
		gotoxy(10,8);
		printf("Password Match");
		gotoxy(10,9);
		printf("Press AnyKey to Continue");
		if(getch()!=0)
		
		mainmenu_principle();
	}
	
	int z;
	if(strcmp(pass,password1)!=0)
		{
		for(z=3; z>0; z--)
		{
		gotoxy(10,8);
		printf("Password Error");
		gotoxy(10,9);
		printf("Retry");
		delay(1000);
		password_principle();
	    }
        }
}





void addstudent()
{
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** Student Details *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    	Beep(523,500);
    gotoxy(15,3);
	printf("Give The Details : ");
	gotoxy(10,4);
	printf("Student  ID : ");
	scanf("%d",&s1.sid);
	fp = fopen("s_data.txt","r");
    rewind(fp);
    while(fread(&s2,sizeof(s2),1,fp)==1)
    if(s2.sid==s1.sid)
    {
    	gotoxy(15,25);
    	printf("Student already exist");
    	home_return_func();
	}
	fclose(fp);
	fflush(stdin);
	gotoxy(10,5);
    printf("Library ID : ");
    scanf("%d",&s1.lib_id);
   	fflush(stdin);
	gotoxy(10,6);
	printf("Student Name : ");
	gets(s1.sname);
	gotoxy(10,7);
	printf("Student Age : ");
	scanf("%d",&s1.sage);
	gotoxy(10,8);
	printf("Student Class : ");
	scanf("%d",&s1.sclass);
    system("cls");
    gotoxy(10,3);
    printf("Entered Student Details Are Under : ");
    gotoxy(10,4);
    printf("Student ID  Student Lib_ID  Student Name   Student Age    Student Class  ");
    gotoxy(10,5);
	printf("%d",s1.sid);  
	gotoxy(22,5);
    printf("%d",s1.lib_id);
    gotoxy(38,5);
	puts(s1.sname);
	gotoxy(55,5);
	printf("%d",s1.sage);
	gotoxy(68,5);
	printf("%d",s1.sclass);
	gotoxy(10,7);
	printf("Do You Wanna Save Student Data(y/n) : ");

    if(getch()=='y')
    {
    	fp = fopen("s_data.txt","ab+");
    	fseek(fp,0,SEEK_SET);
    	fwrite(&s1,sizeof(s1),1,fp);
    	fclose(fp);
    	gotoxy(15,9);
    	printf("Successfully Saved !......");
    	gotoxy(10,10);
    	printf("Wanna Save More Student Data(y/n)  ");
     	if(getch()=='n')
        {
    	mainmenu_managment_cell();
		}
	    else
		{
	    addstudent();
		}
    }
	else
	    {
	    mainmenu_managment_cell();
		}
	}

void showstudents()
{
	Beep(700,700);
    system("cls");	
    char text[] = "******************************** STUDENTS LIST *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no. Student ID     Library ID  Student Name   S'age  S'Class");
    fp = fopen("s_data.txt","rb+");
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
	gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",s1.sid);
	gotoxy(26,j);
	printf("%d",s1.lib_id);    
	gotoxy(38,j);
	puts(s1.sname);
	gotoxy(53,j);
	printf("%d",s1.sage);
	gotoxy(60,j);
	printf("%d",s1.sclass);
	j++,k++;
	delay(100);
	}
    fclose(fp);
    {
	gotoxy(10,j+10);
    printf("Total Students : %d",k-1);
    gotoxy(80,j+10);   
	{printf("Press AnyKey to Return Home Page"); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
	printf("Returning in 2 Seconds");
	delay(2000);
	mainmenu_managment_cell();
    }
}
}

void removestudent()
{
	{
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** REMOVE A STUDENT *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
//    system("cls");
    gotoxy(10,5);
    printf("Enter Student Id : ");
    scanf("%d",&d);
    fp=fopen("s_data.txt","rb+");
    rewind(fp);
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
        if(s1.sid==d)
        {
 
        gotoxy(10,7);
        printf("The book record is available");
        
        gotoxy(10,9);
        printf("Student Name : %s",s1.sname);
        gotoxy(10,8);
        printf("Student ID is     : %d",s1.sid);
        findbook='t';
        }
    }
    fclose(fp);
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No Student Found modify the search (Press Enter) ");
        if(getch()==13)
        {
            removestudent();
        }
        else
        {
        	home();
		}
    }
    if(findbook=='t' )
    {
        gotoxy(10,12);
        
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        fp = fopen("s_data.txt","rb+");
        fd=fopen("Temp.txt","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&s1,sizeof(s1),1,fp)==1)
        {
            if(s1.sid!=d)
            {
            fseek(fd,0,SEEK_CUR);
            fwrite(&s1,sizeof(s1),1,fd); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(fd);
        fclose(fp);
        remove("s_data.txt");
        rename("Temp.txt","s_data.txt"); //copy all item from temporary file to fp except that
        fp=fopen("s_data.txt","r");    //we want to delete
        if(findbook=='t')
        {   
            gotoxy(10,15);
            printf("The record is sucessfully deleted");
            Beep(1000,300);
			gotoxy(10,16);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenu_managment_cell();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenu_managment_cell();
}
}

void searchstudent()
{
	Beep(400,500);
	int d;
    system("cls");	
    char text[] = "******************************** SEARCH STUDENT *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}gotoxy(20,10);
//    printf("1. Search By ID");
    fp=fopen("s_data.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
	while(getch()!=0)
	{
      
    {
//        system("cls");
        gotoxy(25,4);
        printf("****Search Student By Id****");
        gotoxy(20,5);
        printf("Enter the Student ID :");
        scanf("%d",&d);
        gotoxy(20,7);
		char text1[] = "Searching............";
		    gotoxy(20,7);
			for(int k=0; k<(strlen(text1)); k++)
		    {
		    	printf("%c",text1[k]);
		    	delay(30);
	        }
	    while(fread(&s1,sizeof(s1),1,fp)==1)
        {
        if(s1.sid==d)
        {
            delay(2);
            gotoxy(20,7);
            printf("The Student is in School");
            gotoxy(20,8);
            gotoxy(20,9);
            printf("Student ID             : %d",s1.sid);
            gotoxy(20,10);
            printf("Student Name           : %s",s1.sname);
            gotoxy(20,11);
            printf("Student Class          : %d ",s1.sclass);
            gotoxy(20,12);
            printf("Student Age            : %d ",s1.sage);
            gotoxy(20,13);
            printf("Student Library ID     : %d",s1.lib_id);
            
            gotoxy(20,15);
            Beep(500,500);
			findbook='t';
        }
 
        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(press Enter) ");
        if(getch()==13)
        searchbook();
        else
        mainmenu_managment_cell();
        break;
    }
    }
    getch();
    searchbook();  
    fclose(fp);
}

void editstudent()
{
	Beep(1500,600);
    int c=0;
    int d,e;
    system("cls");	
    char text[] = "******************************** EDIT STUDENT DATA *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
	char another='y';
    while(another=='y')
    {
       // system("cls");
        gotoxy(15,6);
        printf("Enter Student ID to be edited:");
        scanf("%d",&d);
        fp = fopen("s_data.txt","rb+");
        rewind(fp);
	    while(fread(&s1,sizeof(s1),1,fp)==1)
	    {
            if(s1.sid==d)
            {
                gotoxy(15,7);
                printf("The Student is in Class :  %d",s1.sclass);
                gotoxy(15,8);
                printf("The Student ID : %d",s1.sid);
                gotoxy(15,9);
                printf("Enter new name : ");scanf("%s",s1.sname);
                gotoxy(15,10);
                printf("Enter new Library card : ");scanf("%d",&s1.lib_id);
                gotoxy(15,11);
                printf("Enter new Class : ");scanf("%d",&s1.sclass);
                gotoxy(15,12);
                printf("Enter Age <Now> : ");scanf("%d",&s1.sage);
                gotoxy(15,14);
                printf("The record is modified");
                Beep(523,500);
               
             
			    fseek(fp,ftell(fp)-sizeof(s1),0);
                fwrite(&s1,sizeof(s1),1,fp);
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
	mainmenu_managment_cell();
}

void aboutschool()
{
	int k = 20;
	system("cls");
	char wl[] = "***************************> MY DREAM SCHOOL HARIDWAR <***********************************";
	gotoxy(k,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    gotoxy(k,4);
    printf("From Director,");
    gotoxy(k,5);
	printf("This school is open for the students which can");
	gotoxy(k,6);
	printf("not afford fee in thousands.");
	gotoxy(k,7);
	printf("Intence to Open this school is to provied good");
	gotoxy(k,8);
	printf("education to those students.");
	char tch[] = "***************> TEACHERS IN SCHOOL <***************";
	gotoxy(k,10);
	for(int j=0; j<strlen(tch); j++)
	{
	printf("%c",tch[j]);
	delay(10);
    }
	gotoxy(k,12);
	printf("Subject  - Teacher's Name");
	gotoxy(k,13);
	printf("English  - Mr. Gopal Soni");
	gotoxy(k,14);
	printf("Hindi    - Mr. Rakesh Kumar");
	gotoxy(k,15);
	printf("Social_S - Mr. Rajesh Meena");
	gotoxy(k,16);
	printf("Science  - Mr. Kaushal Prajapat");
	gotoxy(k,17);
	printf("Maths    - Mr. Vijay Sharma");
	gotoxy(k,18);
	printf("Chemist. - Mr. Anuj Soni");
	gotoxy(k,19);
	printf("Physics  - prof. Ashank Verma");
	gotoxy(k,20);
	printf("Math 12+ - Prof. Kaushal Prajapat");
	getch();
	home();
}



void issue_book()
{
	int c=0;
    int lid,e;
    system("cls");	
    char text[] = "******************************** ISSUE BOOK *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    {
       // system("cls");
        gotoxy(15,6);
        printf("Enter Student Library ID : ");
        scanf("%d",&lid);
        fp = fopen("s_data.txt","rb+");
        rewind(fp);
	    while(fread(&s1,sizeof(s1),1,fp)==1)
	    {
            if(s1.sid==lid)
            {
                
                give_book();
                fclose(fp);
                c=1;
                getch();
            }
            if(c==0)
                {
                gotoxy(15,9);
//                printf("No LIB_ID Issued");
                }
        }
        gotoxy(15,16);
        printf("Modify Lib_ID(Y/N)");
        issue_book();
        delay(1000);
	 }
	mainmenu_managment_cell();
}


void give_book()
{

	system("cls");	
    char text[] = "******************************** ISSUE BOOK *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(1);
    }
             gotoxy(15,7);
                printf("The Student Name :  %s",s1.sname);
                gotoxy(15,8);
                printf("The Student ID : %d",s1.sid);
                gotoxy(15,9);
                printf("The Student LIB_ID : %d",s1.lib_id);
       
    int c=0,d;
    char another='y';
    while(another=='y')
    {
       // system("cls");
        gotoxy(15,13);
        printf("Enter Book ID to Borrow : ");
        scanf("%d",&d);

        fp = fopen("LIB_MEGE.txt","rb+");
        rewind(fp);
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
            if(b.id==d)
            {
				//c=1;
				   if(b.qnty>0)
	                {
	                gotoxy(15,15);
	                printf("The book is availble   %d",b.id);
	                gotoxy(15,16);
	                printf("The Book Quantity : %d",b.qnty);
	                gotoxy(15,17);
	                printf("Book Name : %s",b.bname);
	                gotoxy(15,18);
	                printf("Confirm? (Y/N)");
	                if(getch()=='y')
	                {
					gotoxy(15,19);
	                printf("The Book * %s *  id *%d* is given to * %s *",b.bname,b.id,s1.sname);  
	                b.qnty = b.qnty - 1;
				    fseek(fp,ftell(fp)-sizeof(b),0);
	                fwrite(&b,sizeof(b),1,fp);
	                fclose(fp);

                update();

                    }
					else
					{
					give_book();
					}
					gotoxy(90,30);
                    get_time();
                    gotoxy(15,21);
	                printf("Wanna Borrow more book (Y/N)");
	                if(getch()=='y')
	                system("cls");
				    borrow_return_menu();
                    }
				}
            if(c==0)
                {
                gotoxy(15,15);
                printf("No Book Available");
//                delay(1000);
				}
			if(b.qnty==0)
			{
			gotoxy(15,25);
			printf("Book is Out of Stoke");
            }
	
	}
	gotoxy(90,30);
   	get_time();
   	gotoxy(15,26);
   	printf("Wanna return mainmenu of library (Y/N)");
   	{
   		if(getch()=='y')
   		{
	mainmenulibrary();
     	}
        else
        {
        	give_book();
		}   
	}
	}
}

void update()
{
	up.b_id = b.id;
//	up.b_name[22] = b.bname[22];
	strcpy(up.b_name,b.bname);
	up.sl_id = s1.lib_id;
	up.s_id = s1.sid;
//	up.s_name[22] = s1.sname[22];
    strcpy(up.s_name,s1.sname);
		{
    	fp = fopen("lib_data.txt","ab+");
    	fseek(fp,0,SEEK_SET);
    	fwrite(&up,sizeof(up),1,fp);
    	fclose(fp);
        }
}

void get_issued_data()
{
    	Beep(700,700);
    system("cls");	
    char text[] = "******************************** ISSUED BOOK *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no. Book ID   Book Name           Student ID Student Name");
    fp = fopen("lib_data.txt","rb");
    while(fread(&up,sizeof(up),1,fp)==1)
    {
	gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",up.b_id);
	gotoxy(20,j);
	puts(up.b_name); 
	gotoxy(42,j);
	printf("%d",up.s_id);
	gotoxy(52,j);
	puts(up.s_name); 
	j++,k++;
	delay(100);
	}

    fclose(fp);
    {
    gotoxy(80,j+10);   
	{printf("Press AnyKey to Return PREVIOUS MENU "); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
	printf("Returning in 2 Seconds");
	delay(2000);
	borrow_return_menu();
	//mainmenulibrary(); ////Error Here
    }
}

}

void student_searchbook()
{
	Beep(400,500);
	int d;
    system("cls");	
    char text[] = "******************************** SEARCH BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}gotoxy(20,10);
//    printf("1. Search By ID");
    fp=fopen("LIB_MEGE.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
	while(getch()!=0)
	{
      
    {
//        system("cls");
        gotoxy(25,4);
        printf("****Search Books By Id****");
        gotoxy(20,5);
        printf("Enter the book id:");
        scanf("%d",&d);
        gotoxy(20,7);
		char text1[] = "Searching............";
		    gotoxy(20,7);
			for(int k=0; k<(strlen(text1)); k++)
		    {
		    	printf("%c",text1[k]);
		    	delay(30);
	        }
	    while(fread(&b,sizeof(b),1,fp)==1)
        {
        if(b.id==d)
        {
            delay(2);
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            gotoxy(20,9);
            printf("BOOK ID        : %d",b.id);
            gotoxy(20,10);
            printf("BOOK Name      : %s",b.bname);
            gotoxy(20,11);
            printf("BOOK Author    : %s ",b.author);
            gotoxy(20,12);
            printf("BOOK Qantity   : %d ",b.qnty);
            gotoxy(20,13);
            printf("BOOK Price     : Rs.%.2f",b.price);
            gotoxy(20,14);
            printf("Grand Total    : %f ",b.price*b.qnty);
            gotoxy(20,15);
            Beep(500,500);
			findbook='t';
        }
 
        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        student_searchbook();
        else
        mainmenu_student();
        break;
    }
    }
    getch();
    student_searchbook();  
    fclose(fp);
}

void student_viewbooks()
{
	Beep(700,700);
    system("cls");	
    char text[] = "******************************** VIEW BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int sum = 0, gt = 0, j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no. Book ID   Book Name     Book Author    Price     Quantity   GrandTotal");
    fp = fopen("LIB_MEGE.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1)
    {
	gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",b.id);
	gotoxy(20,j);
	puts(b.bname);    
	gotoxy(35,j);
	puts(b.author);
	gotoxy(50,j);
	printf("%.2f",b.price);
	gotoxy(60,j);
	printf("%d",b.qnty);
	gotoxy(71,j);
	printf("%.2f",(b.price)*(b.qnty));
	j++,k++;
	delay(100);
	gt = gt + (b.price)*(b.qnty);
	sum = sum + b.qnty;
    }
    gotoxy(5,j+5);
    printf("Total Books in Library : %d",sum);
    gotoxy(50,j+5);
    printf("Total Price of Books in Library : %d",gt);
    
    fclose(fp);
    {
    gotoxy(80,j+10);   
	{printf("Press AnyKey to Return MAIN MENU STUDENT"); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
	printf("Returning in 2 Seconds");
	delay(2000);
	mainmenu_student();
    }
}
}


void student_showstudents()
{
	Beep(700,700);
    system("cls");	
    char text[] = "******************************** STUDENTS LIST *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no. Student ID     Library ID  Student Name   S'age  S'Class");
    fp = fopen("s_data.txt","rb+");
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
	gotoxy(5,j);
	printf("%d.",k);
	gotoxy(11,j);
	printf("%d",s1.sid);
	gotoxy(26,j);
	printf("%d",s1.lib_id);    
	gotoxy(38,j);
	puts(s1.sname);
	gotoxy(53,j);
	printf("%d",s1.sage);
	gotoxy(60,j);
	printf("%d",s1.sclass);
	j++,k++;
	delay(100);
	}
    fclose(fp);
    {
	gotoxy(10,j+10);
    printf("Total Students : %d",k-1);
    gotoxy(80,j+10);   
	{printf("Press AnyKey to Return Home Page"); }
	if(getch()!=0)
	{
	Beep(600,400);
	gotoxy(80,j+12);
	printf("Returning in 2 Seconds");
	delay(2000);
	mainmenu_student();
    }
}
}



void student_searchstudent()
{
	Beep(400,500);
	int d;
    system("cls");	
    char text[] = "******************************** SEARCH STUDENT *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}gotoxy(20,10);
//    printf("1. Search By ID");
    fp=fopen("s_data.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
	while(getch()!=0)
	{
      
    {
//        system("cls");
        gotoxy(25,4);
        printf("****Search Student By Id****");
        gotoxy(20,5);
        printf("Enter the Student ID :");
        scanf("%d",&d);
        gotoxy(20,7);
		char text1[] = "Searching............";
		    gotoxy(20,7);
			for(int k=0; k<(strlen(text1)); k++)
		    {
		    	printf("%c",text1[k]);
		    	delay(30);
	        }
	    while(fread(&s1,sizeof(s1),1,fp)==1)
        {
        if(s1.sid==d)
        {
            delay(2);
            gotoxy(20,7);
            printf("The Student is in School");
            gotoxy(20,8);
            gotoxy(20,9);
            printf("Student ID             : %d",s1.sid);
            gotoxy(20,10);
            printf("Student Name           : %s",s1.sname);
            gotoxy(20,11);
            printf("Student Class          : %d ",s1.sclass);
            gotoxy(20,12);
            printf("Student Age            : %d ",s1.sage);
            gotoxy(20,13);
            printf("Student Library ID     : %d",s1.lib_id);
            
            gotoxy(20,15);
            Beep(500,500);
			findbook='t';
        }
 
        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(press Enter) ");
        if(getch()==13)
        student_searchstudent();
        else
        mainmenu_student();
        break;
    }
    }
    getch();
    student_searchbook();  
    fclose(fp);
}


void borrow_return_menu()
{
	system("cls");
	char wl[] = "******************> MAINMENU FOR BORROW AND RETURN BOOK <******************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    Beep(700,500);
    gotoxy(15,4);
    printf(">>> 1.Borrow Book\n");
    gotoxy(15,6);
	printf(">>> 2.Return Book\n");
	gotoxy(15,8);
    printf(">>> 3.Show Issued Book");
    gotoxy(15,10);
	printf(">>> 4.Main Menu Library");
	gotoxy(15,12);
	printf(">>> 6.EXIT");
	gotoxy(15,16);
    printf(">>> 9.Back to Home");
	gotoxy(15,20);
	printf("Enter Your Choice : ");

	switch(getch())
	{
	case '9' :
		home();
	case '1' :
	    borrow_return_menu_issue_book();
	    break;
	case '2' :
		return_book();
		break;

	case '4' :
		mainmenulibrary();
		break;
	case '6' :
	    exit();
	    break;
    
    case '3' :
    	get_issued_data();
    	break;
	default :
		Beep(523,500);
		gotoxy(15,18);
		printf("SORRY !! ");
		gotoxy(15,19);
		printf("Wrong Choice !! Try Again !!");
		delay(2000);
		system("cls");
		home();
    }

}

void borrow_return_menu_issue_book()
{
	int c=0;
    int lid,e;
    system("cls");	
    char text[] = "******************************** ISSUE BOOK *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    {
       // system("cls");
        gotoxy(15,6);
        printf("Enter Student Library ID : ");
        scanf("%d",&lid);
        fp = fopen("s_data.txt","rb+");
        rewind(fp);
	    while(fread(&s1,sizeof(s1),1,fp)==1)
	    {
            if(s1.sid==lid)
            {
                
                give_book();
                fclose(fp);
                c=1;
                getch();
                }
            if(c==0)
                {
                gotoxy(15,9);
//                printf("No LIB_ID Issued");
                }
        }
        gotoxy(15,16);
        printf("Modify Lib_ID(Y/N)");
        issue_book();
        delay(1000);
	 }
	borrow_return_menu();
}

void borrow_return_menu_return_book()
{
	printf("This is Return Book Function");
}




void return_book()
{
	Beep(2000,800);
	system("cls");
	char text[] = "******************************** RETURN BOOKS *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
    }
    int sid,bid;
    char another='y';
    while(another=='y')  //infinite loop
    {
//    system("cls");
    gotoxy(10,4);
    printf("Enter the Student ID :");
    scanf("%d",&sid);
    gotoxy(10,5);
    printf("Enter the Book ID to  Return :");
    scanf("%d",&bid);
    fp=fopen("lib_data.txt","rb+");
    rewind(fp);
    while(fread(&up,sizeof(up),1,fp)==1)
    {
        if(up.b_id==bid&&up.s_id==sid)
        {
 
        gotoxy(10,7);
        printf("The record is available");
        gotoxy(10,9);
        printf("Book name is     : %s",up.b_name);
        gotoxy(10,8);
        printf("Book ID : %d",up.b_id);
        findbook='t';
        }
    }
    fclose(fp);
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search (Press Enter) ");
        if(getch()==13)
        system("cls");
		return_book();
    }
    if(findbook=='t' )
    {
        gotoxy(10,12);
        
        printf("Do you want to Return it?(Y/N):");
        if(getch()=='y')
        {
        	return_update_book(bid);
        fp = fopen("lib_data.txt","rb+");
        fd=fopen("Temp1.txt","w");  //temporary file for delete
        rewind(fp);
        while(fread(&up,sizeof(up),1,fp)==1)
        {
            if(up.b_id!=bid)
            {
            fseek(fd,0,SEEK_CUR);
            fwrite(&up,sizeof(up),1,fd); //write all in tempory file except that
		    }                              //we want to delete
        }
        fclose(fd);
        fclose(fp);
        remove("lib_data.txt");
        rename("Temp1.txt","lib_data.txt"); //copy all item from temporary file to fp except that
        fp=fopen("lib_data.txt","r");    //we want to delete
        if(findbook=='t')
            {   
            gotoxy(10,15);
            printf("The Book is sucessfully Returned");
            Beep(1000,300);
			gotoxy(10,16);
            printf("Return another record?(Y/N)");
            }
        }
    else
    home();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    borrow_return_menu();
}

void return_update_book(int d)
{
	int bid;
        fp = fopen("LIB_MEGE.txt","rb+");
        rewind(fp);
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
            if(b.id==d)
            {
                    b.qnty = b.qnty + 1;            
			    fseek(fp,ftell(fp)-sizeof(b),0);
                fwrite(&b,sizeof(b),1,fp);
                fclose(fp);
            } 
        }
}

void get_time()
{
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("%d.%d.%d // %d - %d - %d",stime.wHour+5,stime.wMinute+30,stime.wSecond,stime.wDay,stime.wMonth,stime.wYear);
 	getch();
}

void home_return_func()
{
    gotoxy(80,28);   
	if(getch()!=0)
	{
	Beep(600,400);
	
	for(int i = 2 ; i >= 0 ; i--)	
	{
	gotoxy(80,30);
	printf("Returning in %d Seconds\n",i);
	delay(1000);
	}
	home();
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

void exit()
{
	system("cls");
	gotoxy(15,5);
	printf("Wanna Rate My Application press \"1\" else press any Key : ");
	//fflush(stdin);
	if(getch() == 49)
		rate_app();
	system("cls");
	gotoxy(51,13);
    char rg[50] = ">>> Prepared TEAM AKA <<<";
	for(int i=0; i<strlen(rg); i++)
	{
	printf("%c",rg[i]);
	delay(20);
    }
	gotoxy(48,14);
	for(int i =49; i<78; i++)
	{
		printf("%c",177);
	}
	gotoxy(48,16);
	for(int i =49; i<78; i++)
	{
		printf("%c",177);
	}
	gotoxy(48,15);printf("%c",177);
	gotoxy(76,15);printf("%c",177);
	gotoxy(50,15);
	printf("* Thanks To Use Our App *");
	for(int i=0; i<5; i++)
	{
	Beep(523,200);
	delay(200);
    }
    
	exit(0);
}

void viewRating()
{
	Beep(700,700);
    system("cls");	
    char text[] = "******************************** VIEW Rating *********************************";
    gotoxy(5,2);
	for(int j=0; j<(strlen(text)); j++)
    {
    	printf("%c",text[j]);
    	delay(10);
	}
   
	int sum = 0, gt = 0, j=6,k=1;
	Beep(630,500);
	
	gotoxy(5,4);
    printf("S.no.          User Name       User Rating");
    fp = fopen("rating.txt","rb");
    while(fread(&rt,sizeof(rt),1,fp)==1)
    {
    gotoxy(5,j);
    printf("%d",k);
	gotoxy(20,j);
	puts(rt.name);    
	gotoxy(40,j);
	printf("%d",rt.rate);
	j++,k++;
	delay(100);
	sum = sum + rt.rate;
    }
    gotoxy(5,j+5);
    printf("Total Persons rated : %d",k-1);
    gotoxy(50,j+5);
    printf("Average rating : %.2f",(float)sum/(k-1));
    Beep(600,600);
    fclose(fp);
    getch();
    home();   
}


void rate_app()
{
	FILE *fp;
	Beep(900,500);
	system("cls");
	char wl[100] = "****************************> RATE MY APPLICATION <******************************";
	gotoxy(15,2);
	for(int i=0; i<strlen(wl); i++)
	{
	printf("%c",wl[i]);
	delay(10);
    }
    gotoxy(15,5);
    printf("Rate Our Application");
    gotoxy(15,7);
    printf("Enter Your Name :");
    gets(rt.name);
    gotoxy(15,9);
    printf("0 for Bad and 10 for best : ");
    scanf("%d",&rt.rate);
	if(rt.rate <= 10 && rt.rate >= 0)	
		{
		fp = fopen("rating.txt","ab+");
	    	fseek(fp,0,SEEK_SET);
	    	fwrite(&rt,sizeof(rt),1,fp);
	    	fclose(fp);
	    	gotoxy(15,12);
	    	printf("Successfully Recorded !......");
	    	gotoxy(15,15);
	    	printf("Thanks For Working with US");
			delay(1000);
		}
	else
		{
		gotoxy(15,15);
		printf("Invalid Rating Values ");
		fflush(stdin);
		rate_app();
		delay(1500);
		}
}



