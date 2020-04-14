#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node_S;

void move_node(node_S **dest_ref, node_S ** source_ref)
{
	node_S *new_node = *source_ref;
	
	*source_ref = new_node->next;
	new_node->next = *dest_ref;
	*dest_ref = new_node;
}

node_S *merge_sort(node_S *a, node_S *b)
{
	node_S temp;
	node_S *tail = &temp;
	temp.next = NULL;
	
	while(1)
	{
		if(a == NULL)
		{
			tail->next = b;
			break;
		}
		else if(b == NULL)
		{
			tail->next = a;
			break;
		}
		if(a->data <= b->data)
		{
			move_node(&(tail->next),&a);
		}
		else
		{
			move_node(&(tail->next),&b);
		}
		tail=tail->next;
	}
	return(temp.next);
}

void push(node_S **head_ref, int value)
{
	node_S *new_node = (node_S*)malloc(sizeof(node_S));
	new_node->data = value;
	
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print(node_S *node)
{
	while(node!=NULL)
	{
		printf("%d ",node->data);
		 node=node->next;
	}
	printf("\n");
}
	

int main(void)
{
	node_S* list1 = NULL;
	node_S* list2 = NULL;
	node_S* merge_list = NULL;
	push(&list1,3);
	push(&list1,2);
	push(&list1,1);
	print(list1);
	push(&list2,6);
	push(&list2,5);
	push(&list2,4);
	print(list2);
	merge_list = merge_sort(list1,list2);
	printf("Merged List is:\n");
	print(merge_list);
	return 0;
}
