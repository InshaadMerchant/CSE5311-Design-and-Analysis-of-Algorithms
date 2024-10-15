#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} 
Node;

void insertAtHead(Node** head, int new_data) 
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void deleteNode(Node** head, int key) 
{
    Node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) 
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {

        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(Node *node) 
{
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void) 
{
    Node* head = NULL;
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}
