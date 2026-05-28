#include<stdio.h>

void swap(int*a,int*b){
    int temp = *a;
        *a = *b;
        *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot= arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high&&arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
        swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

int quicksort(int arr[],int low,int high){
        if(low<high){
            int p=partition(arr,low,high);
            quicksort(arr,low,p-1);
            quicksort(arr,p+1,high);
        }    
}

int main(){
    int n;
    printf("enter the no of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
}
return 0;
}
