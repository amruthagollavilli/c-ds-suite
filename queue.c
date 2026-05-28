// primary operations using queue 

#include <stdio.h>

// since for userdefined data we have to use malloc and free

#include<stdlib.h>

int *queue;
int max_size;
int front= -1;
int rear= -1;
 
// inserting the value

void enqueue(int val){
    
// checking whether the queue is null or not 

    if(rear == max_size-1){

        // showing the overflow

        printf("the queue is empty\n");

    }

    else{

      if (front == -1) {
            front = 0;
        }

        // inserting the value

        rear++;
        queue[rear] = val;
        printf("%d successfully inserted\n",queue[rear]);

    }
    
}
 
//deleting the value

void dequeue(){

//checking whether the queue is empty

if(front == -1){

//   showing underflow error
    
    printf("cannot be inserted\n");
}
else{
    
    printf("%d successfully deleted\n");


    // if the queue has a single element

     if(front==rear){
        front = rear=-1;
     }
     else{
     front++;
     }
}

}
 
// displaying the front element

void getFront(){
    if(front ==-1){
        printf(" the queue is empty\n");
    }
    else{
        printf("%d ",queue[front]);
    }
}

// checking whether it isempty or not

void isFull(){

     if(rear == max_size-1){
        printf("queue is full\n");
     }
     else{
        printf("queue is not full\n");
     }
}

// checking whether the queue is empty or not

void isEmpty(){

    if(front ==-1){

        printf("queue is empty\n");

    }
    else{
        printf("queue is not empty\n");
    }
}

// displaying all the elements

void display(){

    // checking whether the queue is emmpty or not empty
     
    if(front ==-1){

        printf("queue is empty\n");

    }
    else{
        for(int i = front;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
    }
}
 
int main(){
    int choice;
    int val;
    printf("enter the queue size");
    scanf("%d",&max_size);

    //to allocate specific block of memory dynamically 

      queue = (int *)malloc(max_size * sizeof(int));

    //  checking whether stack is NULL

    if (queue== NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while(1){

      printf(" 1.enqueue\n 2.dequeue\n 3.getfront\n 4.isempty\n 5. isfull \n 6.display\n 7.exit\n ");
      printf("enter your choice");
      scanf("%d",&choice);
      
      switch(choice){
        case 1:
        printf("enter the value");
        scanf("%d",&val);
        enqueue(val);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        getFront();
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
        free(queue);
        exit(0);
        default:
        printf("Invalid choice");
      }
    }
  return 0;
}
 