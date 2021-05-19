//-------------------Searching in C--------------------
//--------By - Kaushal Prajapat -- On 16.01.2021----------

#include<stdio.h>
#include<conio.h>
searching(int arr[] , int size , int item)
{
    int flag = 1;
    for (int i = 0 ; i < size ; i++)
    {
        if(arr[i] == item)
            {
                printf("Found at index no. %d\n",i);
                flag = 0;
            }

    }
    if(flag == 1)
    printf("Search Unsuccessful\n");
}



int main()
{
    printf("//-------------------Searching in C--------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 16.01.2021----------//\n\n\n");

    int ar[] = {11,9,5,87,99,56,84,51,19,58};
    searching(ar,10,94);
}
