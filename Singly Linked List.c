/******************************************************************************
SINGLY LINKED LIST
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *link;
} node;
node *head = NULL;
node *temp = NULL;
void display ();
void insert_at_beg ();
void insert_at_end ();
void insert_at_pos (int);
void delete_at_beg ();
void delete_at_end ();
void delete_at_pos (int);
void display();
int length ();

void main ()
{
  int ch, i, n, pos;
  while (1)
    {
        printf("\n 1.Insert at begining\n 2.Insert at end\n 3.Insert at any position\n 4.Delete at begining\n 5.Delete at end\n 6.Delete at any postion\n 7.Display\n 8.length\n 9.Exit");
        printf ("\n Enter your option:");
        scanf ("%d", &ch);
        switch (ch)
	{
	case 1: printf ("Insert at begining:");
	insert_at_beg ();
	break;
	case 2:printf ("Insert at end:");
	insert_at_end ();
	break;
	case 3:printf ("Insert at any postion:");
	printf ("enter your option:");
	scanf ("%d", &pos);
	insert_at_pos (pos);
	break;
	case 4:printf ("Delete at begining:");
	delete_at_beg ();
	break;
	case 5:printf ("Delete at end:");
	delete_at_end ();
	break;
	case 6:printf ("delete at any postion:");
	printf ("enter your option:");
	scanf ("%d", &pos);
	delete_at_pos (pos);
	break;
	case 7:
	if (head == NULL)
	    {
	        printf ("\n List is Empty");
	    }
	    else
	    {
	        printf ("The List is:");
	        display ();
	    }
	    break;
	case 8:
	if (head == NULL)
	    {
	        printf ("Empty List ..length is 0");
	    }
	    else
	    {
	        n = length ();
	        printf ("\n length of the list is:%d", n);
	    }
	    break;
    case 9:exit (0);
	    break;
	    }
    }
}

node *getnode ()
{
    node *new =(node*) malloc(sizeof(node));
    printf ("\n Enter data:");
    scanf ("%d", &new->data);
    new->link = NULL;
    return new;
}

void insert_at_beg ()
{
    node *new = getnode ();
    new->link = head;
    if (head == NULL)
    {
        temp = new;
    }
    else
    {
        head = new;
    }
}

void insert_at_end ()
{
    node *new = getnode ();
    if (head == NULL)
    {
        head = temp = new;
    }
    else
    {
        temp->link = NULL;
        temp = new;
    }
}

void insert_at_pos (int k)
{
    int i,n;
    n=length();
    if(k==1)
    {
        insert_at_beg();
    }
        else if(k>=n)
        {
        insert_at_end();
        }
        else if(1<k && k<n)
        {
            node* new=getnode();
            temp=head;
            for(i=1;i<k-1;i++)
            {
            temp=temp->link;
            }
            new->link=temp->link;
            temp->link=new;
        }
    }

void display()
{
    node *curr = head;
    while (curr != NULL)
    {
        printf ("%d", curr->data);
        curr = curr->link;
    }
}

int length ()
{
    int count = 1;
    temp = head;
    while (temp->link != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void delete_at_beg ()
{
    node *temp = head;
    if (head == NULL)
    {
        printf ("List is empty");
    }
    else if (head->link == NULL)
    {
        printf ("data is deleted:%d", head->data);
        head = NULL;
        temp = NULL;
        free (temp);
    }
    else
    {
        head = head->link;
        free (temp);
    }
}

void delete_at_end ()
{
    node *temp;
    if (head == NULL)
    {
        printf ("\nThe list is empty");
    }
    else if (head->link == NULL)
    {
        printf ("data is deleted:%d", head->data);
        head = NULL;
        temp = NULL;
        free (temp);
    }
    else
    {
        node *p;
        while (p->link = temp)
	    {
	    temp = p->link;
	    p = temp->link;
	    p->link = NULL;
	    p = temp;
	    free (temp);
	    }
    }
}

void delete_at_pos (int k)
{
    int i, n;
    printf ("Enter position:");
    scanf ("%d", &k);
    node *curr = head;
    node *temp1;
    if (k == 1)
    {
        delete_at_beg ();
    }
    else if (k == n)
    {
        delete_at_end ();
    }
    else if (1 < k && k < n)
    {
        for (i = 1; i < k - 2; i++)
	    {
	    curr = curr->link;
	    temp = curr->link;
	    curr->link = curr->link->link;
	    free (temp1);
	    }
    }
    else
    {
      printf ("Invalid Position\n");
    }
}



