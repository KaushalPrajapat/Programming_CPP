//-----------Removing and Adding Updating and Searching in a Array in C-----------//
//------By - Kaushal Prajapat -- On 19.12.2020----------//

#include<stdio.h>
#include<conio.h>
#define ARRAY_SIZE 5;
void print_array();
void insert_element();
int remove_element();
int update_element();
int search_element();
int main()
{

    printf("//---------------Removing, Adding, Updating and Searching in a Array using C-----------//\n");
    printf("//------By - Kaushal Prajapat -- On 21.12.2020----------//\n\n\n");
    int n = 5 , array_size = ARRAY_SIZE;
    int arr[] = {1,2,3,4,5};
    print_array(arr,array_size);
    printf("Element at index : %d",search_element(arr , array_size , 4));
    //printf("Old Value : %d ",update_element(arr , array_size , 3 , 45));
    //printf("Removed Element : %d",remove_element(arr,array_size,3));
    //insert_element(arr,6,2,10);
    getch();
}
int search_element(int arr[] , int number_of_element_in_array , int value_to_search)
{
    printf("Searching.... for element : %d\n",value_to_search);
    int j = 0;
    for( j = 0 ;j <= number_of_element_in_array ; j++)
    {
        if(arr[j] == value_to_search )
            break;
    }
    return j;
}
int update_element(int arr[] , int number_of_element_in_array ,int pos , int new_value)
{
    int z = arr[pos-1];
    printf("%d",z);
    arr[pos-1] = new_value;
    printf("Array after Updating %d with %d\n",z,new_value);
    print_array(arr,number_of_element_in_array);
    return (z) ;
}
int remove_element(int arr[] ,int number_of_element_in_array , int pos )
{
    int z = arr[pos-1];
    while(pos < number_of_element_in_array)
    {
        arr[pos-1] = arr[pos];
        pos++;
    }
    //arr[pos] = val;
    printf("Array after removing %d\n",z);
print_array(arr,number_of_element_in_array-1);
return z;
}
void insert_element(int arr[] ,int number_of_element_in_array , int pos , int val)
{
    int j = number_of_element_in_array;
    while(j >= pos)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[pos] = val;
    printf("Array after Inserting : \n");
print_array(arr,number_of_element_in_array+1);
}
void print_array(int arr[] ,int n)
{
    printf("printing Array :\n");
    for(int x = 0 ;  x < n ; x++)
    {
        printf("%d ",arr[x]);
    }
    printf("\n");
}
