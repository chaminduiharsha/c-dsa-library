#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Part
{
    int id;
    char name[50];
    float weight;
    float price;
    int quantity;

};


void addPart(struct Part **parts, int *size);
void displayParts(struct Part *parts, int size);
void sortByPrice(struct Part *parts, int size);
void sortByWeight(struct Part *parts, int size);
void searchPart(struct Part *parts, int size);
void deletePart(struct Part **parts, int *size);
void totalInventoryValue(struct Part *parts, int size);

void addPart(struct Part ** parts)                 //WE USE DOUBLE POINTER TO CHANGE *parts IN THE MAIN FUNCTION

{
    struct Part *temp;

    temp=realloc(*parts,(*size+1)*sizeof(struct Part));  //FROM TEMP WE GET STRUCTURE'S MEMMORY BLOCK BASE ADDRESS

    if(temp==NULL)
    {
        printf("Memmory allocation failed\n");
        return;
    }

    *parts=temp;                      //FROM DOUBLE POINTER WE GET ACCCESS TO CREATE MORE STRUCTURE VARIABLES LIKE part[0],parts[1],...


    printf("\nEnter name of the part:");
    scanf("%d",&(*parts)[*size].name);

    printf("\nEnter id of the part: ");
    scanf("%d",&(*parts)[*size].id);

    printf("\nEnter weight of the part:");
    scanf("%f",&(*parts)[*size].weight);

    printf("\nEnter price of the part:");
    scanf("%f",&(*parts)[*size].price);

    printf("\nEnter quantity of part:");
    scanf("%d",&(*parts)[*size].quantity);

    (*size)++;

    printf("\nPart  added successfully.");



}

void displayParts(struct Part *parts,int size)
{
    if(size==0)
    {
        printf("No parts available\n");
        return;

    }


    printf("\n-----------------------------------------------------------------------\n");
    printf("ID\tNAME\t\tWEIGHT\t\tPRICE\t\tQUANTITY\n");
    printf("-----------------------------------------------------------------------\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d\t%-15s%.2f\t\t%.2f\t\t%d\n",
               parts[i].id,
               parts[i].name,
               parts[i].weight,
               parts[i].price,
               parts[i].quantity);
    }

}

void sortByPrice(struct Part * parts,int size)
{
    int i,j,swap=0;
    struct Part temp;

    for(i=0;i<size-1;i++)
    {
        swap=0;
        for(j=0;j<size-1-i;j++)
        { if(parts[j].price < parts[j+1].price)
            temp=parts[j];
            parts[j]=parts[j+1];
            parts[j+1]=temp;

            swap=1;
        }
        if(swap==0)
            break;
    }
}

void sortByWeight(struct Part  * parts,int size)
{
    int i,j,swap=0;
    struct Part temp;

    for(i=0;i<size-1;i++)
    {
        swap=0;
        for(j=0;j<size-1-i;j++)
        {
            if(parts[j].weight > parts[j+1].weight)
            {
                temp=parts[j];
                parts[j]=parts[j+1];
                parts[j+1]=parts[j];

                swap=1;
            }

        }
        if(swap==0)
            break;
    }
}

void searchPart(struct Part *parts,int size)
{
    char partname[50];
    int found=0;

    if(size==0)
    {
        printf("no parts aavailable\n");
        return;
    }

    printf("enter name of the search part:");
    scanf("%s",partname);

    for(i=0;i<size;i++)
    {
        if(strcmp(parts[i].name,partname)==0)
        {
            printf("\nPart Found!\n");
            printf("ID       : %d\n", parts[i].id);
            printf("Name     : %s\n", parts[i].name);
            printf("Weight   : %.2f g\n", parts[i].weight);
            printf("Price    : %.2f LKR\n", parts[i].price);
            printf("Quantity : %d\n", parts[i].quantity);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nPart not found.\n");
    }
}

void deletePart(struct Part **parts,int size)
{
    int index=-1;
    int id;

    if(*size==0)
    {
        printf("inverntory is empty\n");
        return;
    }

    printf("enter id for delete part:");
    scanf("%d",&id);


    for(i=0;i<*size;i++)
    {
        if((*parts[i].id==id)    // *parts mean base address of the structure part[0] , then increment we get part[1],part[2],...
        {
            index=i;
            break;
        }
    }

    if(index==-1)
    {
        printf("part is not found\n");
        return;
    }
    for(i=index;i<*size-1;i++)
    {
        (*parts)[i]=(*parts)[i+1];

    }
    (*size)--;

      if(*size == 0)
    {
        free(*parts);
        *parts = NULL;
    }
    else
    {
        struct Part *temp;

        temp = realloc(*parts, (*size) * sizeof(struct Part));  //resize the memmory block to size

        if(temp != NULL)
        {
            *parts = temp;  //assign new base address to *parts
        }
    }

    printf("\nPart deleted successfully.\n");
}


void totalInventoryValue(struct Part *parts, int size)
{
    float total = 0;

    for(int i = 0; i < size; i++)
    {
        total += parts[i].price * parts[i].quantity;
    }

    printf("\nTotal Inventory Value = %.2f LKR\n", total);
}


int main()
{
    struct Part *parts = NULL;
    int size = 0;
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" RC PLANE PARTS INVENTORY MANAGER\n");
        printf("=====================================\n");
        printf("1. Add Part\n");
        printf("2. Display Parts\n");
        printf("3. Sort By Price\n");
        printf("4. Sort By Weight\n");
        printf("5. Search Part\n");
        printf("6. Delete Part\n");
        printf("7. Total Inventory Value\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPart(&parts, &size);
                break;

            case 2:
                displayParts(parts, size);
                break;

            case 3:
                sortByPrice(parts, size);
                printf("\nParts sorted by price.\n");
                break;

            case 4:
                sortByWeight(parts, size);
                printf("\nParts sorted by weight.\n");
                break;

            case 5:
                searchPart(parts, size);
                break;

            case 6:
                deletePart(&parts, &size);
                break;

            case 7:
                totalInventoryValue(parts, size);
                break;

            case 0:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 0);

    free(parts);

    return 0;
}




