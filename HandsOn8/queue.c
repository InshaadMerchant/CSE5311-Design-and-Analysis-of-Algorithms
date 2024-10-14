#include <stdio.h>
#include <stdbool.h>

#define MAX 20
int queue[MAX], front = -1, rear = -1;

int isEmpty() 
{
    return (front == -1); 
}

int isFull() 
{
    return ((rear + 1) % MAX == front); 
}

int enqueue() 
{
    if (isFull()) 
    {
        printf("Queue Overflow\n");
        return 0;
    }
    if (isEmpty()) 
    {
        front = 0; 
    }
    rear = (rear + 1) % MAX; // Circular increment
    printf("Enter the element to be inserted: ");
    scanf("%d", &queue[rear]);
    printf("Element inserted successfully\n");
    return 0;
}

int dequeue() 
{
    if (isEmpty()) 
    {
        printf("Queue Underflow\n");
        return 0;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) 
    {
        front = rear = -1; 
    } 
    else 
    {
        front = (front + 1) % MAX; 
    }
    return 0;
}

int List() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return 0;
    }
    printf("Queue elements:\n");
    int i = front;
    while (true) 
    {
        printf("%d\n", queue[i]);
        if (i == rear) 
        {
            break;
        }
        i = (i + 1) % MAX; 
    }
    return 0;
}

int main(void) 
{
    int menu;
    while (true) 
    {
        printf("\n\nQueue Menu:");
        printf("\n1. Enqueue\n2. Dequeue\n3. List\n");
        printf("\nSelect Menu Option: ");
        scanf("%d", &menu);

        switch (menu) 
        {
            case 1:
                enqueue(); 
                break;
            case 2:
                dequeue();  
                break;
            case 3:
                List();
                break;
            default:
                printf("Wrong Menu Choice.\n");
        }
    }
    return 0;
}