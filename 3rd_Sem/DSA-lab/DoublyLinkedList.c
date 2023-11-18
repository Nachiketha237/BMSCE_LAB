#include<stdio.h>
#include<stdlib.h>

struct node{
int value;
struct node *next;
struct node  *prev;
};


typedef struct node *NODE;

//For allocating memory space-

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Memory could not be allocated.");
    }

    return(temp);

}


//Inserting values at the beginning-

NODE insert_left(NODE first,int item)
{
    NODE new;
    new=getnode();

    new->value=item;
    new->next=NULL;
    new->prev=NULL;

    if(first==NULL)
        return new;
    else
    {
        new->next=first;
        new->prev=first->prev;
        first->prev=new;
        return first;
    }

}

//Inserting at the end-





//For deleting at the end-
NODE delete_any_given_value(int val,NODE first)
{
    if (first == NULL){
        printf("The linked list is empty!");
        return NULL;
    }
    else if (first->next == NULL)
    {
        if (first->value==val)
            return NULL;
        else{
            printf("Element not found!");
            return NULL;
        }
    }
    else{
        NODE curr = first;
        NODE prv=NULL;
        while ((curr->value != val) && (curr != NULL))
        {
            prv = curr;
            curr = (curr->next);
        }
        if (curr->value==val)
        {
            prv->next = curr->next;
            (curr->next)->prev=prv;
            free(curr);
            return first;
        }
        else
        {
            printf("\nPosition not found!");
            return first;
        }
    }
}


//For displaying-

void display(NODE first)
{
    NODE temp;
    // temp=getnode();
    temp=first;

    while(temp!=NULL)
    {
        printf(" %d",temp->value);
        temp=temp->prev;
    }
}

int main()
{
    int choice,item;
    NODE first = NULL;
    while (1)
    {
        printf("\n\n--------------------------------------------Menu-----------------------------------------\n1) Insert at left\n2) Display\n3) Delete given value\n4) Exit\n-----------------------------------------\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            first = insert_left(first,item);
            break;
        case 2:printf("/nThe items are:");
            display(first);
            break;
        case 3:
            printf("Enter the value of the element is to be deleted : ");
            scanf("%d", &item);
            first = delete_any_given_value(item, first);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}
