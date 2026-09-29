#include<stdio.h>
#include<stdlib.h>
#include"Doublylinkedlist.h"


void createlinkedlist(struct List *list,int value)
{
   struct node *newnode;

    list->head=NULL;
    list->tail=NULL;

 newnode=(struct node*)malloc(sizeof(struct node));

  newnode->data=value;
  newnode->next=NULL;
  newnode->prev=NULL;

  if(list->head==NULL)
  {
      list->tail =list->head=newnode;
  }
  else
  {
      list->tail->next=newnode;
      newnode->prev=list->tail;
      list->tail=newnode;

  }

return;
}



void display(struct List *list)
{
    struct node *temp;
    temp=list->head;

    if(temp==NULL)
    {
        printf("empty list\n");
    }
    else{

     while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }




    }





}


void search(struct List *list,int key)
{

    int pos=1;
    struct node *temp;
    temp=list->head;

    if(temp==NULL)
    {
        printf("empty list\n");
    }
    else{

    while(temp != NULL)
    {
        if(key==temp->data)
        {
            printf("value found at %d position\n",pos);
        }

        temp=temp->next;
        pos++;

    }


    }

}


void insertFront(struct List *list,int value)
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;

      if (list->head == NULL) {
        list->head = list->tail = newnode;
        return;
    }



    list->head->prev=newnode;
    newnode->next=list->head;
    list->head=newnode;



}

void insertRear(struct List *list,int value)
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;



       if (list->tail == NULL) {
        list->head = list->tail = newnode;
        return;}


   list->tail->next=newnode;
    newnode->prev=list->tail;
   list->tail=newnode;


}

void insertMiddle(struct List *list,int value,int pos)
{ int i=1;
 struct node *newnode,*temp;
 temp=list->head;


  if (pos == 1) {
        insertFront(list, value);
        return;
    }
 newnode=(struct node*)malloc(sizeof(struct node));


  newnode->data=value;
  newnode->next=NULL;
  newnode->prev=NULL;




 while(i<pos-1)
 {
     temp=temp->next;
     i++;
 }


   if(temp==NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;

    }

 newnode->next=temp->next;
 newnode->prev=temp;




 temp->next=newnode;
 newnode->next->prev=newnode;


    if (temp->next != NULL)
        temp->next->prev = newnode;
    else
        list->tail = newnode;

    temp->next = newnode;

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

     list-> head=temp->next;
    if(list->head!=NULL)
    {
        list->head->prev=NULL;
    }
    else
        list->tail=NULL;

    free(temp);


}

void deleteRear(struct List *list)
{

    struct node *temp = list->tail;

    if (temp == NULL) {
        printf("empty list\n");
        return;
    }

    if (temp->prev == NULL) {
    } else {
        list->tail = temp->prev;
        list->tail->next = NULL;
    }
    free(temp);
}




void deleteMiddle(struct List *list,int pos)
{
    int i=1;

    if(pos<1)
    {
        printf("invalid position\n");
    }

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

    struct node *temp=list->head;


    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }

    if(temp==NULL)
    {
        printf("position out of range\n");
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);


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
    temp=list->head;

    if(temp==NULL)
    {
        printf("empty list\n");
        return;
    }


    if(pos==1)
    {
        updateFront(list,value);
        return;
    }

    if(pos<0)
    {
        printf("invalid position\n");
        return;
    }


    while(i<pos)
    {
         temp=temp->next;
         i++;
    }

    temp->data=value;




}

void countNodes(struct List *list)
{

    int count=0;
    struct node *temp;
    temp=list->head;


    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    printf("Total nodes:%d\n",count);


}

int main()
{

    struct List list;

    list.head = NULL;
    list.tail = NULL;

    int choice, value, pos, key;


    do {

        printf("\n=====DOUBLY LINKED LIST MENU =====\n");


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

            countNodes(&list);

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


