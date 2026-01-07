#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int partition(int arr[], int low ,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    int arr[] = {40,90,70,30,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr,n);
    quicksort(arr,0,n-1);
    print_array(arr,n);
    return 0;
}

