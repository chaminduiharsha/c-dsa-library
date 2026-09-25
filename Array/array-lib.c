#include<stdio.h>
#include "array-lib.h"



void traversal(int arr[],int *size)
{
    if(*size==0)
    {
        printf("empty array");
    }


    for(int i=0;i<*size;i++)
    {
        printf("%d\n",arr[i]);
    }
}



int linearsearch(int arr[],int *size,int target)
{
    int flag=0;

    for(int i=0;i<*size;i++)
    {
        if(arr[i]==target)
        {
             return i;
        }

    }

    return -1;
}




int updateByvalue(int arr[],int *size,int oldValue,int newValue)
{

    int index=linearsearch(arr,size,oldValue);

    if(index==-1)
    {
        printf("element not founded\n");
        return 0;
    }

        arr[index]=newValue;
        return 0;


}





int insertAtanypos(int arr[],int *size,int capacity,int position,int value)
{
    if(*size==capacity)
    {
        printf("array is overflow\n");
        return 0;
    }

    for(int i=*size-1;i >= position-1;i--)
    {
        arr[i+1]=arr[i];
        printf("value added to %d index\n",position-1);

    }
    arr[position-1]=value;
    (*size)++;
    return 1;

}





int deleteAtPosition(int arr[],int *size,int position)
{
    if(*size==0)
    {
        printf("array is empty\n");
        return 0;
    }
    else if(position>*size || position<0)
    {
        printf("invalid position\n");
        return 0;

    }
    else if(position==*size+1)
    {
        (*size)--;
        return 0;
    }

    {

    for(int i=position-1;i<*size-1;i++)
    {

        arr[i]=arr[i+1];
    }

    (*size)--;



    return 1;



    }




}





int main()
{
    int choice,size,capacity,position,target;
    int oldValue,newValue,value;

    printf("enter capacity:");
    scanf("%d",&capacity);

    printf("enter size of array:");
    scanf("%d",&size);
    int arr[size];


    for(int i=0;i<size;i++)
    {
        printf("enter value:");
        scanf("%d",&arr[i]);
    }


    printf("--array_operations--\n");

    printf("1.array_traversal\n");
    printf("2.array_linearsearch\n");
    printf("3.array_update by value\n");
    printf("4.array_insert at any position\n");
    printf("5.array_delete at any position\n");




    do{ printf("enter your choice:");
    scanf("%d",&choice);








    switch(choice){

    case 1:
        traversal(arr,&size);
        break;

    case 2:
        printf("enter value to search:");
        scanf("%d",&target);

       int flag = linearsearch( arr,&size,target);

       if(flag==-1)
       {
           printf("value not founded\n");
       }
       else{
        printf("value founded\n");
       }

        break;




    case 3:
        printf("enter value to update:");
        scanf("%d",&oldValue);

        printf("enter new value:");
        scanf("%d",&newValue);

        updateByvalue(arr,&size,oldValue,newValue);

      break;

    case 4:
        printf("enter position to insert:");
        scanf("%d",&position);

        printf("enter value to insert:");
        scanf("%d",&value);

        insertAtanypos(arr,&size,capacity,position,value);

        break;

    case 5:
        printf("enter position to delete:");
        scanf("%d",&position);


        deleteAtPosition( arr,&size,position);

        break;

    default:
        printf("Invalid choice\n");



}

    }while(choice<6 && choice >0);

    return 0;

}


