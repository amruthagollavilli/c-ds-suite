#include<stdio.h>
int linearsearch(int arr[],int n,int key){
    for(int i =0;i<n;i++){
        if(arr[i]== key){
            return i;
        }
    }
    return -1;
}
int main(){
 int n,key;
 printf("enter the size if the array\n");
 scanf("%d",&n);
 int arr[n];
 printf("enter the elements in the array\n");
 for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 printf("enter the key\n");
 scanf("%d",&key);
 int res =linearsearch(arr,n,key);
 if(res!=-1){
    printf("the value is found at %d \n",res+1);
 }
 else{
    printf("the key is not found\n");
 }
 return 0;
}