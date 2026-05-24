#include<stdio.h>
#include<stdlib.h>

// --Creating a Node--

struct node{
    int data;
    struct node*next;}

// Initializing head equal to zero

struct node*head =0;
 
// --1.Inserting a node at beginig--

void insertatbeg(int val){

    // Creating a new node
   
    struct node*newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    
    // Check if memory allocation is failed
    
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // for both empty and non empty lists

     
    newnode->data = val;
    newnode->next = head;

    head = newnode;

}

void insertatmid(int val,int pos){

    // Creating a newnode
    
    struct node*newnode;
    newnode =(struct node*)malloc(sizeof(struct node));

    // Check if memory allocation is failed
    
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newnode->data=val;

    // if the linkedlist is empty

    if(head==NULL){
        head = newnode;
        newnode->next = NULL;
    }

    // if it is not empty 
    
    // initialising a tempnode

    struct node*temp;
    temp=head;
    
    // If inserting at position 1 (the very beginning)
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return; //  stop executing the rest of the function!
    }

    // if the linkedlist is empty

    if (head == NULL) {
        printf("List is empty. Cannot insert at position %d!\n", pos);
        free(newnode);
        return;
    }


    for(int i= 1;i< pos-1;i++){
        temp =temp->next;

        // Check for NULL *inside* the loop before moving further

        if (temp == NULL) {
            printf("Position %d is out of bounds!\n", pos);
            free(newnode); 
            return;
        }
    }
    
    // Check if the position is out of bounds

    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", pos);
        free(newnode); // Clean up memory since we aren't using it
        return;
    }

    newnode->next =temp->next;
    temp->next =newnode;
}

void insertatend(int val){

  // Creating a newnode
    
    struct node*newnode;
    newnode =(struct node*)malloc(sizeof(struct node));

    // Check if memory allocation is failed
    
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newnode->data=val;

    // if the linkedlist is empty

    if(head==NULL){
        head = newnode;
        newnode->next = NULL;
        return;
    }  

    // creating a temp node

    struct node*temp;
    temp=head;

    while(temp->next!= NULL){
        temp=temp->next;
    }

    temp->next =newnode;
    newnode->next = NULL;
}

void deleteatbeg(){

    // check if the linkedlist is empty

    if(head==NULL){
        printf("Cannot delete an element cause the linked list is Empty");
        return;
    }
     
    struct node*temp;
    temp=head;

    head =head->next;
    free(temp);
}

void deleteatmid(int pos){

 // check if the linkedlist is empty

    if(head==NULL){
        printf("Cannot delete an element cause the linked list is Empty");
        return;
    }
     
    //  if delete at beginnig happens

    if(pos==1)
    {
      deleteatbeg();
      return;  
    }
    
    // Creating two temporary nodes temp,pre

    struct node*temp;
    temp=head->next;
    struct node*pre;
    pre=head;
    
    // traversing

    for(int i=2; i<pos;i++){
       
        pre = temp;
        temp= temp->next;

        if (temp == NULL) {
            printf("Position %d is out of bounds!\n", pos);
            return;
        }

    }

    //  if position is out of bounds

    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", pos);
        return;
    }


    pre->next=temp->next;
    free(temp);
    
}

void deleteatend(){
    
}
