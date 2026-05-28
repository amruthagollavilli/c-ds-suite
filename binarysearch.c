#include<stdio.h>
int binarysearch(int arr[],int n,int key){
    int low =0;
    int high=n-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low= mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int  main(){
    int n,key;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elments in the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the key\n");
    scanf("%d",&key);
    int res = binarysearch(arr,n,key);
    if(res!=-1){
     printf("the value is found at %d \n",res+1);
    }
    else{
     printf("the key is not found\n");
    }
 return 0;
}