#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
} node_t;
void remove_last(node_t ** head)
{
    if (*head == NULL)
    {
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    node_t * current = *head;
    while(current->next->next !=NULL){
        current = current->next;
    }

    free(current-> next);
    current->next=NULL;
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
    remove_last(&head);
    print_list(head);
    return 0;
}
