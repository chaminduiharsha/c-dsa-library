#include<stdio.h>
#define capacity 100



int insertatany(int arr[],int *size,int position,int newmark)
{
    int i;

    if(*size==capacity)
    {
        printf("array is overflow\n");

    }

    else if(position==*size)
    {
        arr[*size]=newmark;
        printf("value added to the %d index\n",*size);
    }
    else
    {
        for(i=*size-1;i>=position-1;i--)
        {
        arr[i+1]=arr[i];
        }
        arr[position-1]=newmark;
    }
     printf("value added to the %d index\n",position-1);
    (*size)++;
return 1;
}




int deleteatany(int arr[],int index1[],int *size,int position)
{ int i;
    if(position>capacity||*size==0||position<=0)
    { printf("cant perform deletion\n");
        return 0;
    }
    else if(position==*size)
    {
        printf("value at the %d was deleted\n",*size);



    }
    else
    {
        for(i=position-1;i<*size-1;i++)
        {
            index1[i]=index1[i+1];
            arr[i]=arr[i+1];
        } printf("value at the %d was deleted\n",position-1);

    }
    (*size)--;
    return 1;

}




int searchmark(int arr[],int index1[],int mark,int *size)
{ int i;
    for(i=0;i<=*size-1;i++)
    {
        if(mark==arr[index1[i]])
        {
            printf("searched mark founded\n");
            printf("searched mark's index is %d\n",index1[i]);
            return i;
        }

    }

    printf("mark not found\n");
    return-1;

}




int updatemark(int arr[],int index1[],int *size,int index,int newmark)
{ int i;
    if(index<0||index>=*size)
       {
        printf("invalid index\n");
        return 0;}

    arr[index1[i]]=newmark;
    return 1;

}





int displayallmarks(int arr[],int index1[],int *size)
{
    int i;

    if(*size == 0)
    {
        printf("No marks available\n");
        return 0;
    }

    printf("students marks:\n");


    for(i=0;i < *size;i++)
    {
        printf("%d index mark is %d\n",index1[i],arr[index1[i]]);
    }
return 1;
}






int main()
{ int arr[capacity];
  int size=0;
  int choice=0;
  int mark;
  int position=0;
  int index;
  int newmark;

  int index1[20];
  int i = 0;

do
{
printf("---Student Marks Manager---\n");
printf("1.Add a mark at a chosen position\n");
printf("2.Delete a mark at a chosen position\n");
printf("3.Search for a mark\n");
printf("4.Upadate a mark by index\n");
printf("5.Display all marks\n");
printf("6.Exit\n");

printf("whats ur choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
    printf("a.Give any position do u want to enter mark:");
    scanf("%d",&position);
    index1[i] = position-1;
    i++;
    printf("b.Enter newmark:");
    scanf("%d",&mark);
    insertatany(arr,&size,position,mark);
    break;

case 2:
    printf("a.Enter position do u want to delete:");
    scanf("%d",&position);
    deleteatany(arr,index1,&size,position);
    break;
case 3:
    printf("a.Enter mark do u want to search:");
    scanf("%d",&mark);
    searchmark(arr,index1,mark,&size);
    break;
case 4:
    printf("a.Enter index do u want to change:\n");
    scanf("%d",&index);
    printf("b.Enter new mark:");
    scanf("%d",&newmark);
    updatemark(arr,index1,&size,index,newmark);
    break;
case 5:
  displayallmarks(arr,index1,&size);
  break;
case 6:
    printf("program terminated\n");

}


} while(choice!=6);

return 0;
}
