#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
} node_t;
void remove_by_value(node_t ** head,int value)
{
    if(*head == NULL)
    {
        return;
    }

    if((*head)->val == value)
    {
        node_t * temp = *head;
        *head = (*head) -> next;
        free(temp);
        return;
    }

    node_t * cr = *head;
    node_t * prev = NULL;

    while(cr != NULL && cr->val != value)
    {
        prev = cr;
        cr = cr->next;
    }

    if(cr == NULL)
    {
        return;
    }
    prev->next = cr->next;
    free(cr);
}

void add_first(node_t ** head, int val)
{
    node_t * new = (node_t * )malloc(sizeof(node_t));
    if(new == NULL)
    {
        return;
    }
    new->val = val;
    new->next = *head;
    *head = new;
}
void print_list(node_t * node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}
int main() {
    struct Node * head = NULL;
    add_first(&head,1);
    add_first(&head,3);
    add_first(&head,6);
    add_first(&head,9);
    print_list(head);
    printf("\n");
    remove_by_value(&head,6);
    print_list(head);
    return 0;
}
