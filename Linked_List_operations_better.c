#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node_t;

int push(node_t **head_ref, int value)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node==NULL)
    {
        return 1;
    }
    
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return 0;
}

int insert(node_t *prev, int value)
{
    if(prev == NULL)
    {
        return 1;
    }
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        return 1;
    }
    new_node->data = value;
    new_node->next = prev->next;
    prev->next = new_node;
    return 0;
}

int append(node_t **head_ref, int value)
{
    node_t *temp = *head_ref;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        return 1;
    }
    new_node->data = value;
    if(temp==NULL)
    {
        *head_ref = new_node;
        new_node->next = NULL;
        return 0;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
    return 0;
}

int count(node_t *head_ref)
{
    int count = 0;
    node_t *temp = head_ref;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int delete(node_t **head_ref, int key)
{
    node_t *temp = *head_ref;
    if(temp!=NULL && temp->data==key)
    {
        *head_ref = temp->next;
        free(temp);
        return 0;
    }
    node_t *prev;
    while(temp!=NULL && temp->data!=key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return 1;
    }
    prev->next = temp->next;
    free(temp);
    return 0;
}

void print(node_t *print_node)
{
    while(print_node!=NULL)
    {
        printf("%d ",print_node->data);
        print_node=print_node->next;
    }
}

int delete_list(node_t **head_ref)
{
    node_t *current = *head_ref, *temp;
    if(current==NULL)
    {
        return 1;
    }
    while(current!=NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    (*head_ref) = NULL;
    return 0;
}

/*int search(node_t **head_ref, int key)
{
    node_t *temp = *head_ref;
    if(temp!=NULL && temp->data==key)
    {
        return 0;
    }
    while(temp!=NULL && temp->data!=key)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/

/* Recursive */

int search(node_t *head_ref, int key)
{
    if(head_ref == NULL)
    {
        return 1;
    }
    if(head_ref!=NULL && head_ref->data == key )
    {
        return 0;
    }
    else
    {
        search(head_ref->next,key);
    }
}

/*int print_median(node_t **head_ref)
{
    node_t *temp = *head_ref;
    int length = count(temp),mid;
    if(length%2==0)
    {
        mid=(length/2); //Gives 2nd median node.
    }
    else
    {
        mid=(length+1)/2; //Gives the exact median node.
    }
    while(mid)
    {
        temp=temp->next;
        mid--;
    }
    return (temp->data);
}*/

/* Using two pointers */

int print_median(node_t **head_ref)
{
    node_t *slow, *fast;
    slow = fast = *head_ref;
    if(*head_ref == NULL)
    {
        return 1;
    }
    while(fast!=NULL && fast->next!=NULL) //important
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return (slow->data);
}

int reverse(node_t **head_ref)
{
    node_t *current = *head_ref, *prev=NULL, *temp;
    if(current == NULL)
    {
        return 1;
    }
    while(current!=NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
    return 0;
}

void print_list_in_reverse(node_t *head_ref)
{
    if(head_ref == NULL)
    {
        return;
    }
    print_list_in_reverse(head_ref->next);
    printf("%d ",head_ref->data);
}

/*int detect_loop(node_t **head_ref)
{
    node_t *fast, *slow;
    fast = slow = *head_ref;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            printf("Loop Found!");
            return 0;
        }
    }
    return 1;
*/

int detect_and_count_loop(node_t **head_ref)
{
    node_t *slow, *fast;
    slow = fast = *head_ref;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            printf("Loop found!\n");
            break;
        }
    }
    if(fast==NULL | fast->next==NULL)
    {
        return 0;
    }
    int count = 0;
    while(slow->next!=fast) // note
    {
        count++;
        slow = slow->next;
    }
    return (count+1);
}


int main(void)
{
    node_t *head = NULL;
    push(&head,4);
    push(&head,2);
    push(&head,1);
    print(head);
    printf("\n");
    insert(head->next,3);
    print(head);
    append(&head,5);
    printf("\n");
    print(head);
    printf("\n");
    printf("Length: %d\n",count(head));
    delete(&head,3);
    print(head);
    printf("\n");
    printf("Now, length is: %d\n",count(head));
    if(!(search(head,3)))
    {
        printf("Node Found!\n");
    }
    else
    {
        printf("Node not found!\n");
    }
    printf("The median element is %d\n",print_median(&head));
    print_list_in_reverse(head);
    printf("\n");
    reverse(&head);
    print(head);
    return 0;
}