#include<stdio.h>
void print_array(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selection_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_inx = i;
        for(int j= i+1;j<n;j++)
        {
            if(arr[j]<arr[min_inx])
            {
                min_inx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_inx];
        arr[min_inx] = temp;
    }
}
int main()
{
    int arr[] = {40,90,70,30,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr,n);
    selection_sort(arr,n);
    print_array(arr,n);
    return 0;
}
