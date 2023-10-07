#include<stdio.h>
int main(){
    int n,i,key,mid;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int start=0,end=n-1;
    int arr[n];
    printf("Enter the array elements in a sorted manner: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the array element to be found: ");
    scanf("%d",&key);
    mid=(start+end)/2;
    while(start<=end)
    {
        if(key==arr[mid])
        {
            printf("Element %d found at index %d ,position %d",key,mid,mid+1);  
            break;   
        }
        else if(key<arr[mid])
        {
            end=mid-1;
            mid=(start+end)/2; 
        }
        else
        {
            start=mid+1;
            mid=(start+end)/2; 
        }
    }
    if(start>end){
        printf("Element %d not found",key);
    }
    return 0;
}