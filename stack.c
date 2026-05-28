
// stack using array

#include<stdio.h>

// since for userdefined data we have to use malloc and free

#include<stdlib.h>

int *stack;
int max_size;
int top= -1;

// inserting a value

void push(int val){

//  checking whether the stack is full or not

     if(top == max_size-1){

    // showing the overflow error

       printf("stack overflowed cannot use push \n");

     }
     else{

    // inserting the element

        stack[++top]= val;
        printf("%d successfully inserted \n",val);

     }
}

// poping the element

void pop(){

    // checking whether the stack is empty or not

    if(top==-1){

    // showing the underflow error

    printf("stack underflowed cannot use pop\n");

    }

   else{
     
    // deleting the element

     printf("%d successfully poped \n ", stack[top]);
     stack[top--];

    }
}

//  checking whetherstack is empty or full

void isEmpty(){
    
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty \n");
    }
}

// checking whether stack is full or not

void isFull(){
     if(top == max_size -1){
        printf("the stack is full\n");
     }
     else{
        printf("stack is not full\n");
     }
}

//  displaying the top most element

void peek(){

    //  checking whether stack is empty or not

      if(top == -1){

        printf("stack is empty\n");

      }
      else{

         printf("%d",stack[top]);

      }
}

// displaying  all the elements in the stack

void display(){
  
//   checking whether the stack is empty
    
   if(top == -1){

    printf("the stack is empty\n");

   }

// displaying the stack 

    for(int i=0;i<=top;i++){
        printf("%d  ",stack[i]);
    }
} 
 
int main(){
    int val;
    int choice;
    
     printf("enter the stack size");
     scanf("%d",&max_size);

    //to allocate specific block of memory dynamically 

      stack = (int *)malloc(max_size * sizeof(int));

    //  checking whether stack is NULL

    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // menu driven

      while(1){
      printf(" 1. push\n 2.pop\n 3.peek\n 4.isempty\n 5. isfull \n 6.display\n 7.exit\n ");
      printf("enter your choice");
      scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter the value");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            isEmpty();
            break;
            case 5:
            isFull();
            break;
            case 6:
            display();
            break;
            case 7:
            free(stack);
            exit(0);
            default:
            printf("invalid choice");
        }
        printf("\n");
      }
      return 0;
}
