#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
   struct node *prev;

};

struct List{

    struct node *head;
    struct node *tail;


};

void createlinkedlist(struct List *list,int value)
{
    struct node *newnode;


    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;

    if(list->head==NULL)
    {
        list->head=list->tail=newnode;
    }
    else
    {
        list->tail->next=newnode;
        newnode->prev=list->tail;
        list->tail=newnode;

    }

    list->tail->next=list->head;
    list->head->prev=list->tail;




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
    else{

     while(temp->next!= list->head)
     {
         printf("display all:%d\n",temp->data);
         temp=temp->next;

     }

     printf("%d",temp->data);

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
        if(list->data==key)
        {
            printf("value %d found at position %d \n",key,pos)
            return;
        }
        temp=temp->next;
        pos++;

    }while(temp != list->head);

    printf("value not found\n");
    return;


}

void insertFront(struct List *list,int value)
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node);

    newnode->prev=NULL;
    newnode->next=NULL;
    newnode->data=value;

    if(list->head==NULL)
    {
        list->head=list->tail=newnode;
        return;
    }

    newnode->next=list->head;
    list->head->prev=newnode;
    newnode->prev=list->tail;
    list->tail->next=newnode;
    list->head=newnode;


}

void insertRear(struct List *list,int value)
{
    struct node *newnode;


    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;


    if(list->head==NULL)
    {
        list->head=list-tail=newnode;
        return;
    }



}

void insertMiddle(struct List *list,int pos,int value)
{
    struct node *newnode,*temp;
    int i=1;
    struct

    if(list->head==NULL)
    {
        printf("empty list\n");
        return;
    }

    if(pos==1)
    {
        insertFront(list,value);
        return;
    }

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;

    while(i<pos-1)
    {

        temp=temp->next;
        i++;

    }
    if(temp==NULL)
    {
        printf("invalid position \n");
        return;
    }

    if(temp != list->head)
    {
        newnode->next=temp->next;
        newnode->prev=temp;

        temp->next->prev=newnode;
        temp->next=newnode;
    }
    else{

        insertRear(list,value);
        return;
    }


}



void deleteFront(struct List *list)
{
    struct node temp;
    temp=list->head;

    if(temp == NULL)
    {
        printf("empty list\n");
        return;
    }


    if(list->head != list ->tail)
    {
        temp->next->prev=list->tail;

    }
    else
    {
        temp->next=NULL;
        temp->prev=NULL;

    }

    free(temp);

}




void deleteRear(struct List *list)
{
    struct node *temp;
    temp=list->head;

    if(list->head==NULL)
    {
        printf("empty list \n");
        return;
    }

    if(list->head==list->tail)  //only one node
    {
        free(list->tail);
        list->head=list->tail=NULL;
        return;
    }


    while(temp->next != list->tail )
   {
       temp=temp->next;

   }


   temp->next=list->tail->next;
   free(list->tail);
   list->tail=temp;

}

void deleteMiddle(struct List *list,int pos)
{
    struct node *temp;
    temp=list->head;


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

    if(pos<0)
    {
        printf("invalid position\n");
        return;
    }

    while(i<pos-1)
    {
        temp=temp->next;

    }
    if(temp==NULL)
    {
        printf("invalid position\n");
        return;
    }

    struct node *freenode;
    freenode=temp->next;


    if( temp->next == list->tail )
    {
        deleteRear(list);
        return;
    }
    else

     temp->next->next->prev=temp;
     temp->next=temp->next->next;
     free(freenode);




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
    if(pos==1)
    {
        updateFront(list,value);
        return;
    }
    if(list->head==NULL)
    {
        printf("empty list");
        return;
    }
    if(pos<1)
    {
        printf("invalid position\n");
        return;
    }

    while(i<pos)
    {
        temp=temp->next;
    }

    temp->data=value;



}



int countNodes(struct List *list)
{
    struct node *temp;
    temp=list->head;
    int count=1;

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

        printf("\n=====DOUBLY CIRCULLAR LINKED LIST MENU =====\n");


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



























