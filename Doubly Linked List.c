/******************************************************************************
dll
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct dll
{
        int data;
        struct dll *prev;
        struct dll *next;
}dll;
dll *head = NULL;
dll *tail = NULL;
dll *getnode();
void insert_beg();
void insert_end();
void insert_at_pos();
void delete_beg();
void delete_end();
void delete_at_pos();
void display();
int length();
void main()
{
        int ch,n;
        while(1)
        {
                printf("\n1. insert begin\n2. insert end \n3. insert at position \n4. delete begin\n5.delete end \n6.delete at position \n7.display\n8.length\n9.exit");
                printf("\n enter your option:");
                scanf("%d",&ch);

                switch(ch)
                {
                        case 1: printf("\n insert begin");
                                insert_beg();
                                break;
                        case 2: printf("\n insert end");
                                insert_end();
                                break;
                        case 3: printf("\n insert at position");
                                insert_at_pos();
                                break;
                        case 4: printf("\n delete begin");
                                delete_beg();
                                break;
                        case 5: printf("\n delete end ");
                                delete_end();
                                break;
                        case 6: printf("\n delete at position ");
                                delete_at_pos();
                                break;
                        case 7: printf("\n displaying elements:");
                                display();
                                break;
                        case 8: printf("length of list:");
                                length();
                                break;
                        case 9: exit(0);
                                break;

                }
        }
}
dll *getnode()
{
        dll *new = (dll*)malloc(sizeof(dll));
        printf("\n enter your data:");
        scanf("%d",&new->data);
        new -> next = NULL;
        new-> prev = NULL;
        return new;
}
void insert_beg()
{
        dll *new = getnode();
        if(head == NULL)
        {
                head = new;
                tail = new;
        }
        else
        {
                new->next = head;
                head->prev = new;
                head =  new;
        }
}
void insert_end()
{

        dll *new = getnode();
        if(head == NULL)
        {
                head = new;
                tail = new;
        }
        else
        {
            tail->next = new;
                new->prev = tail;
                tail =  new;
        }
}
void insert_at_pos()
{
        dll *new = getnode();
        dll *temp = head;
        int k,i;
        printf("\n enter position:");
        scanf("%d",&k);
        for(i=1;i<k-1;i++)
        {
                temp =  temp->next;
        }
        new->next = temp->next;
        temp->next->prev = new;
        new->prev = temp;
        temp->next =  new;
}
void delete_beg()
{
        dll *temp1 = head;
        if(head == NULL)
        {
                printf("\n no node");
        }
        else if(head-> next == NULL)
        {
                head = NULL;
                tail = NULL;
                free(temp1);
        }
        else
        {
            tail->prev->next = NULL;
            tail = tail->next;
            free(temp1);
        }
}
void delete_end()
{
        dll *t = tail;
        if(head == NULL)
        {
                printf("\n no node");
        }
        else if( head->next = NULL)
        {
                head = NULL;
                tail = NULL;
                free(t);
        }
        else
        {
                tail->prev->next = NULL;
                tail = tail->prev;
                free(t);
        }
}
void delete_at_pos()
{
        dll *temp2 = head;
        dll *t1;
        int k,i;
        printf("\n enter the position");
        scanf("%d",&k);
        for(i=0;i<k-1;i++)
        {
            temp2 = temp2->next;
        }
        t1 = temp2->next;
        temp2->next->next->prev = temp2;
        temp2->next = temp2->next->next;
        free(t1);
}
void display()
{
        dll *curr = head;
        while(curr->next!=NULL)
        {
                printf("\n %d", curr->data);
                curr = curr->next;
        }
        printf("\n %d",curr->data);
}
int length()
{
        dll *curr = head;
        int count = 0;
        while(curr->next!=NULL)
        {
                count ++;
                curr = curr->next;
        }
        printf("\n length is %d ",count+1);
}

