//-------------------Bubble Sorting in C--------------------
//--------By - Kaushal Prajapat -- On 16.01.2021----------

#include<stdio.h>
#include<conio.h>

void bubble_sort(int arr[] , int size)
{
    int temp;
    for (int j = 0 ; j < size ; j++)
        for (int k = 0 ; k < size - 1 - j ; k++)
            if(arr[k] > arr[k+1])
                {
                    temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                }


    for(int i = 0 ; i < size ; i++)
        printf("%d ",arr[i]);
}

int main()
{
    printf("//-------------------Bubble Sorting in C--------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 16.01.2021----------//\n\n\n");

    int ar[] = {11,9,5,87,99,56,84,51,19,58};
    bubble_sort(ar,10);
}
