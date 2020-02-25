#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node_S;

void push(node_S **head_ref, int value)
{
    node_S *new = (node_S*)malloc(sizeof(node_S));
    new->data = value;
    
    new->next = *head_ref;
    *head_ref = new;
}

void insertpost(node_S *prev, int value)
{
    if(prev == NULL)
    {
        return;
    }
    node_S *new = (node_S*)malloc(sizeof(node_S));
    new->data = value;
    new->next = prev->next;
    prev->next = new;
}

void append(node_S **head_ref, int value)
{
    node_S *new = (node_S*)malloc(sizeof(node_S));
    new->data = value;
    
    if(*head_ref == NULL)
    {
        *head_ref = new;
        new->next = NULL;
        return;
    }
    node_S *temp = *head_ref;
    while(temp->next!= NULL)
    {
        temp=temp->next;
    }
    temp->next = new;
    new->next = NULL;
}

void delete(node_S ** head_ref, int key)
{
    node_S *temp = *head_ref, *prev;
    if(temp!=NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    while(temp!=NULL && temp->data!=key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
    return;
    
    prev->next = temp->next;
    free(temp);
    return;
}

int count (node_S *head_ref)
{
    int count = 0;
    node_S *current = head_ref;
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void reverse(node_S ** head_ref)
{
    node_S *current = *head_ref, *prev = NULL, *temp;
    while(current!=NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *head_ref = prev;
}

void print(node_S *s)
{
    while(s!=NULL)
    {
        printf("%i ",s->data);
        s=s->next;
    }
}

int main(void)
{
    node_S *head;
    push(&head,1);
    push(&head,4);
    append(&head,5);
    insertpost(head,2);
    print(head);
    printf("\n");
    delete(&head,1);
    print(head);
    printf("Length of linkedlist is %i\n",count(head));
    reverse(&head);
    print(head);
    
    return 0;
}