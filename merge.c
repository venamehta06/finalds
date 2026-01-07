#include<stdio.h>
int nums[50],temp[50];
void Merge(int low,int mid,int high)
{
    int i = low;
    int j = mid +1;
    int k = low;

    while(i<=mid && j<=high)
    {
        if(nums[i]<nums[j])
        {
            temp[k++]=nums[i++];
        }
        else
        {
            temp[k++]=nums[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = nums[i++];
    }
     while(j<=high)
    {
        temp[k++] = nums[j++];
    }
    for(i=low;i<=high;i++)
        nums[i] = temp[i];
}

void MergeSort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }

}
int main()
{
    int num;
    int a;
    printf("Enter the number of elements ");
    scanf("%d",&num);

    for(int i = 0;i<num;i++)
    {
        printf("Enter the number ");
        scanf("%d",&nums[i]);
    }
    MergeSort(0,num-1);
    printf("Sorted array:\n");
    for (int i = 0; i < num; i++)
        printf("%d ", nums[i]);

    return 0;
}
