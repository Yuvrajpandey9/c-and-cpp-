#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

void linkedlisttraversal(struct node *ptr)
{
   while(ptr != NULL)
   {
        printf("elements: %d\n",ptr->data);
        ptr=ptr->next;
   }
}


int main(){
    struct node*head;
    struct node*second;
    struct node*third;
     //alocate memory for nodes in the linked list in heap
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    
    //link first and second nodes
    head->data=71;
    head->next=second;
    second->data=62;
    //link second and third nodes
    second->next=third;
    third->data=93;
    
    //terminate the list at the third node
    third->next=NULL;

    linkedlisttraversal(head);
    return 0;
    

}