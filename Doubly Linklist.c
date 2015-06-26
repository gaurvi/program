#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    int value;
    struct dnode *next;
    struct dnode *previous;
};
typedef struct dnode dNode;

dNode *head;
dNode *tail;
dNode *pointer;

void insert(int,int);
int fetch(int);
void display(void);
void main()
{
    int choice;
    int value;
    int index;
    while(1)
    {
        printf("What do you want to do in doubly linklist?\n\n");
        printf("1. insert\n 2. fetch \n 3.display \n 4. exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\n Enter the value you want to insert! and at which index you want to insert\n");
            scanf("%d%d",&value,&index);
            insert(value,index);
            printf("\nInserted the value %d into linklist and it is inserted at %d index\n",index,value);
            break;
        case 2:
            printf("\n Valut at what index you want to fetch\n");
            scanf("%d",&index);
            value=fetch(index);
            printf("\n Value at index is %d\n",index,value);
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
void insert(int value, int index)
{
    if(head==NULL)
    {
        head=(dNode*)malloc(sizeof(dNode));
        head->value=value;
        head->next=NULL;
        tail=head;
    }
    if(head!=NULL && index <0)
    {
        tail->previous=(dNode*)malloc(sizeof(dNode));
        tail->previous->value=value;

    }
    if(head!=NULL && index >0)
    {
        tail->next =(dNode*)malloc(sizeof(dNode));
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
    if(index<0)
    {
        pointer=tail;
        for(i = 0; i > index; i--)
        {
            if(pointer->previous == NULL)
            {
                printf("Double Linklist is empty");


            }
            pointer = pointer->previous;
        }
        return pointer->value;
    }
    if(index>0)
    {
        pointer=head;
        for(i=0; i < index; i++)
        {
            if(pointer->next == NULL)
            {
                return -1;
            }
            pointer = pointer->next;


        }
        return pointer->value;
    }
}
    void display()
    {
        int i;
        dNode *im;
        im = head;
        if(head==NULL)
        {
            printf("Linklist is empty\n");
        }
        else
        {
            printf("\n The status of linklist is \n");
            while(im->next!=NULL)
            {
                printf("%d\n",(im->value));
                im=im->next;
            }
            printf("%d\n",(im->value));
            return;

        }
    }















