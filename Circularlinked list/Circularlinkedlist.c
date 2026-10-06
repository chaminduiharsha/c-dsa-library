#include<stdio.h>
#include<stdlib.h>
#include"Circularlinkedlist.h"


void createlinkedlist(struct List *list,int value)
{
    struct node *newnode;

    list->head=NULL;
    list->tail=NULL;

    newnode=(struct node*) malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    if(list->head==NULL)
    {
        list->tail=list->head=newnode;
    }
    else
   {
      list->tail->next=newnode;
      list->tail=newnode;


    }

    list->tail->next=list->head;

}

void display(struct List *list)
{

    struct node *temp;
    temp=list->head;

    if(temp==NULL)
    {
        printf("empty list\n");
        return;
    }
    else
   {

    while(temp->next != list->head)
    {
        printf("display all :%d \n",temp->data);

        temp=temp->next;
    }

    printf("display all:%d\n",temp->data);


}

   }



void search(struct List *list,int key)
{
    struct node *temp;
    temp=list->head;
   int pos=1;

    if(temp==NULL)
    {
        printf("empty list\n");
        return;
    }
    do
    {
        if(temp->data==key)
        {
            printf("value %d found at %d position\n",key,pos);
            return;
        }

        temp=temp->next;
        pos++;

    } while(temp != list->head);

     printf("value not found\n");
        return;

}

void insertFront(struct List *list,int value)
{
    struct node *newnode;


    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->next=NULL;
    newnode->data=value;

    if(list->head==NULL)
    {
        list->tail=list->head=newnode;
        return;
    }



    newnode->next=list->head;
    list->head=newnode;
    list->tail->next=newnode;

}

void insertRear(struct List *list,int value)
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->next=NULL;
    newnode->data=value;

    if(list->tail==NULL)
    {
        list->tail=list->head=newnode;
        return;
    }

    newnode->next=list->head;
    list->tail->next=newnode;
    list->tail=newnode;


}

void insertMiddle(struct List *list,int value,int pos)
{
  struct node *newnode,*temp;
  int i=1;
  temp=list->head;

   if(pos==1)
   {
       insertFront(list,value);
       return;
   }
   newnode=(struct node*)malloc(sizeof(struct node));

   newnode->next=NULL;
   newnode->data=value;


   while(i<pos-1)
   {
       temp=temp->next;
       i++;
   }

   if(temp==NULL)
   {
       printf("invalid position\n");
       return;
   }



   if(temp != list->head)
   {
       newnode->next=temp->next;
       temp->next=newnode;
   }
   else
   {
       insertRear(list,value);

   }


}

void deleteFront(struct List *list)
{
    struct node *temp;
    temp=list->head;


    if(temp==NULL)
    {
        printf("empty list\n");
        return;
    }

    if(list->head->next!=list->head)
    {
    list->head=list->head->next;
    list->tail->next=list->head;

    }
    else{
        list->tail=NULL;
        list->head=NULL;
    }

    free(temp);
}

void deleteRear(struct List *list)
{
    struct node *temp;
    temp=list->head;


    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }
    if(list->head==list->tail)
    {
        list->head=list->tail=NULL;
        return;
    }

    while(temp->next != list->tail)
    {
        temp=temp->next;
    }

    free(list->tail);
    temp->next=list->head;
    list->tail=temp;




}






void deleteMiddle(struct List *list,int pos)
{
    struct node *temp,*freenode;
    int i=1;

    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }

    if(pos==1)
    {
        deleteFront(list);
        return;
    }
    if(pos<1)
    {
        printf("invalid position \n");
    }

    temp=list->head;

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }


    if(temp->next!=list->tail)
    {
        freenode=temp->next;
        temp->next=temp->next->next;
        free(freenode);
    }
    else
    {
        deleteRear(list);

    }




}

void updateFront(struct List *list,int value)
{
    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }
    list->head->data=value;

}

void updateRear(struct List *list,int value)
{
    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }

    list->tail->data=value;
}


void updateMiddle(struct List *list,int pos,int value)
{
    int i=1;
    struct node *temp;



    if(pos==1)
    {
        updateFront(list,value);
        return;
    }

    if(pos<1)
    {
        printf("invalid position\n");
        return;
    }
    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }

    while(i<pos)
    {
        temp=temp->next;
        i++;
    }

    temp->data=value;

}

int countNodes(struct List *list)
{ int count=1;


    struct node *temp;
    temp=list->head;


    while(temp!=list->tail)
    {
        temp=temp->next;
        count++;

    }



    return count;




}



int main()
{
    struct List list;

    list.head=NULL;
    list.tail=NULL;

    int choice, value, pos, key,count=0;


    do {

        printf("\n=====CIRCULLAR LINKED LIST MENU =====\n");


        printf("1.create list\n");

        printf("2. Insert Front\n");
        printf("3. Insert Rear\n");
        printf("4. Insert Middle\n");

        printf("5. Delete Front\n");
        printf("6. Delete Rear\n");
        printf("7. Delete Middle\n");

        printf("8. Update Front\n");
        printf("9. Update Rear\n");
        printf("10. Update Middle\n");

        printf("11. Search\n");
        printf("12. Display\n");
        printf("13. Count Nodes\n");

        printf("14. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);


        switch (choice) {


       case 1:
        printf("enter value:");
        scanf("%d",&value);


       createlinkedlist(&list,value);

       break;


        case 2:

            printf("Enter value: ");
            scanf("%d", &value);

            insertFront(&list, value);

            break;


        case 3:

            printf("Enter value: ");
            scanf("%d", &value);

            insertRear(&list, value);

            break;


        case 4:

            printf("Enter value and position: ");
            scanf("%d%d", &value, &pos);

            insertMiddle(&list, value, pos);

            break;


        case 5:

            deleteFront(&list);

            break;


        case 6:

            deleteRear(&list);

            break;


        case 7:

            printf("Enter position: ");
            scanf("%d", &pos);

            deleteMiddle(&list, pos);

            break;


        case 8:

            printf("Enter new value: ");
            scanf("%d", &value);

            updateFront(&list, value);

            break;


        case 9:

            printf("Enter new value: ");
            scanf("%d", &value);

            updateRear(&list, value);

            break;


        case 10:

            printf("Enter position and new value: ");
            scanf("%d%d", &pos, &value);

            updateMiddle(&list, pos, value);

            break;


        case 11:

            printf("Enter value to search: ");
            scanf("%d", &key);

            search(&list, key);

            break;


        case 12:

            display(&list);

            break;


        case 13:

            count=countNodes(&list);
            printf("nodes count %d",count);



            break;


        case 14:

            printf("Program Ended.\n");

            break;


        default:

            printf("Invalid Choice.\n");
        }


    } while (choice != 14);


    return 0;
}




