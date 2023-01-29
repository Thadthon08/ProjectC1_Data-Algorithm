#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int count = 0;
void append_list(char ch)
{
    node *n = malloc(sizeof(node));
    n->next = NULL;
    n->c = ch;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        tail->next = n;
    }
    tail = n;
    count++;
}

void print_list()
{
    node *current = head;
    while (current != NULL)
    {
        printf("%c ", current->c);
        current = current->next;
    }
}
void delete_node(char ch)
{
    node *current;
    node *prev;
    current = head;
    if (head->c == ch)
    {
        head = head->next;
    }
    else
    {
        while ((current != NULL) && (current->c != ch))
        {
            prev = current;
            current = current->next;
        }
        if (current->c == ch){
            if (tail->c==ch){
                tail = prev;
            }
            prev->next = current->next;
            current->next = NULL;
        }
        if(current->c == ch){
            count--;
        }
        else
        {
            printf("%c is not in the list\n", ch);
        }
        free(current);
    }
}
node *search_list(char ch)
{
    node *current;
    current = head;
    while ((current != NULL) && (current->c != ch))
    {
        current = current->next;
    }
    return current;
}
void destroy_list()
{
    node *ptr;
    while (count > 0)
    {
        ptr = head;
        head = head->next;
        count--;
        free(ptr);
    }
}

int main()
{
    append_list('A');
    append_list('B');
    append_list('O');
    append_list('D');
    printf("List: ");
    print_list();
    printf("\n");
    delete_node('B');
    printf("List after deletion: ");
    print_list();
    printf("\n");
    node *result = search_list('O');
    if (result != NULL)
    {
        printf("'O' found in the list\n");
    }
    else
    {
        printf("'O' not found in the list\n");
    }
    destroy_list();
    printf("List after destruction: ");
    print_list();
    printf("\n");
    return 0;
}
