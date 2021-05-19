//-------------------Bubble Sorting in C--------------------
//--------By - Kaushal Prajapat -- On 16.01.2021----------

#include<stdio.h>
#include<conio.h>

void insertaion_Sort(int arr[] , int size)
{
    printf("\nSorted Array\n");
    int i,j;
    for (i = 0 ; i < size ; i++)
    {
        int temp = arr[i];
        for( j = i - 1; j >= 0 && temp < arr[j] ; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    for(int i = 0 ; i < size ; i++)
        printf("%d ",arr[i]);

}

int main()
{
    printf("//-------------------Insertion Sorting in C--------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 16.01.2021----------//\n\n\n");

    int ar[] = {11,9,5,87,99,56,84,51,19,58};
    printf("Unsorted Array : \n");
    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",ar[i]);

    insertaion_Sort(ar,10);



}
