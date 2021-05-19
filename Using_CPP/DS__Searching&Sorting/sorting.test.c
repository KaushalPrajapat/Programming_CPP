
    printf("Insertation SOrt\n");
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
