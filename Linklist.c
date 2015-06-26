#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
void display(void);
int main(int argc,char *argv[])
{
    int choice;
    int value;
    int index;
    while(1)
    {
        printf("what do you want to do?\n\n");
        printf("1.insert\n 2.fetch\n 3.display\n 4.exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\n enter the value you want to insert!\n ");
            scanf("%d",&value);
            insert(value);
            printf("\n inserted value %d into linked list\n",value);
            break;
        case 2:
            printf("\n value at what index you want to fetch\n");
            scanf("%d",&index);
            value=fetch(index);
            printf("\n value at %d is %d\n",index,value);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting.....\n");
            exit(0);
        default:
            break;

        }
    }
}


void insert(int value)
{
    if(head==NULL)
    {
        head=(Node*)malloc(sizeof(Node));
        head->value=value;
        head->next=NULL;
        tail=head;
    }
    else
    {
        tail->next=(Node*)malloc(sizeof(Node));
        tail->next->value=value;
        tail->next->next=NULL;
        tail=tail->next;
    }
}



int fetch(int index)
{
    int i;
    if(head==NULL)
    {
        printf("linklist is empty");
    }
    Node *pointer = head;
    for(i=0; i<index; i++)
    {
        if(pointer->next==NULL)
        {
            return -1;
        }
        pointer=pointer->next;
    }
    return pointer->value;
}
void display()
{
    int i;
    Node *im;
    im = head;
    if(head==NULL)
    {
        printf("linklist is empty\n");
    }
    else
    {
        printf("\n the status of link list is \n");
        while(im->next!=NULL)
        {
            printf("%d\n",(im->value));
            im=im->next;

            printf("%d\n",(im->value));
            return;
        }
    }
}




