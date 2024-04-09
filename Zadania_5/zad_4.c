#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
} node_t;
void remove_index(node_t ** head,int index)
{
    if(*head == NULL)
    {
        return;
    }

    if(index == 0)
    {
        node_t * temp = *head;
        *head = (*head) -> next;
        free(temp);
        return;
    }

    node_t * cr = *head;
    for(int i = 0; cr != NULL && i < index - 1; i++)
    {
        cr = cr -> next;
    }

    if(cr == NULL || cr->next == NULL)
    {
        return;
    }

    node_t *temp = cr->next;
    cr-> next = temp -> next;
    free(temp);
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
    remove_index(&head,2);
    remove_index(&head,5);
    print_list(head);
    return 0;
}
