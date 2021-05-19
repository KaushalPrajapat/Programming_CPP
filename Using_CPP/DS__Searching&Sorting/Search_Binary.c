//-------------------Binary Search with Bubble Sort in C--------------------
//--------By - Kaushal Prajapat -- On 16.01.2021----------

#include<stdio.h>
#include<conio.h>

void bin_search(int ar[] , int max , int data)
{
    int min = 0 , mid , size = max - 1 ;
    while(min <= size)
    {
        mid = ( size + min ) / 2;
        if(data == ar[mid])
        {
            printf("Data Found at index : %d",mid);
            return;
        }
        else if(data > ar[mid])
            min = mid + 1 ;

        else if(data < ar[mid])
            size = mid - 1 ;
    }

    printf("Data Not Found");

}

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

    bin_search(arr,10,19);
}

int main()
{
    printf("//-------------------Binary Searching in C--------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 16.01.2021----------//\n\n\n");

    int ar[] = {11,9,5,87,99,56,84,51,19,58};
    bubble_sort(ar,10);
}

