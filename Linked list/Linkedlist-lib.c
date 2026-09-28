#include <stdio.h>
#include <stdlib.h>
#include"Linkedlist.h"

// Traversal
void display(struct List *list) {
    struct Node *temp = list->head;

    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


// Search
void search(struct List *list, int key) {
    struct Node *temp = list->head;
    int pos = 1;

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Not found.\n");
}


// Insert Front
void insertFront(struct List *list, int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = list->head;

    list->head = newNode;
}


// Insert Rear
void insertRear(struct List *list, int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {

        list->head = newNode;
        return;
    }

    struct Node *temp = list->head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


// Insert Middle
void insertMiddle(struct List *list, int value, int pos) {

    if (pos == 1) {
        insertFront(list, value);
        return;
    }

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    struct Node *temp = list->head;

    for (int i = 1;
         i < pos - 1 && temp != NULL;
         i++) {

        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Invalid position.\n");

        free(newNode);

        return;
    }

    newNode->next = temp->next;

    temp->next = newNode;
}


// Delete Front
void deleteFront(struct List *list) {

    if (list->head == NULL) {

        printf("List empty.\n");
        return;
    }

    struct Node *temp = list->head;

    list->head = list->head->next;

    free(temp);
}


// Delete Rear
void deleteRear(struct List *list) {

    if (list->head == NULL) {

        printf("List empty.\n");
        return;
    }

    if (list->head->next == NULL) {

        free(list->head);

        list->head = NULL;

        return;
    }

    struct Node *temp = list->head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);

    temp->next = NULL;
}


// Delete Middle
void deleteMiddle(struct List *list, int pos) {

    if (list->head == NULL) {

        printf("List empty.\n");
        return;
    }

    if (pos == 1) {

        deleteFront(list);
        return;
    }

    struct Node *temp = list->head;

    for (int i = 1;
         i < pos - 1 && temp != NULL;
         i++) {

        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {

        printf("Invalid position.\n");
        return;
    }

    struct Node *del = temp->next;

    temp->next = del->next;

    free(del);
}


// Update Front
void updateFront(struct List *list, int value) {

    if (list->head == NULL) {

        printf("List empty.\n");
        return;
    }

    list->head->data = value;
}


// Update Rear
void updateRear(struct List *list, int value) {

    if (list->head == NULL) {

        printf("List empty.\n");
        return;
    }

    struct Node *temp = list->head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->data = value;
}


// Update Middle
void updateMiddle(struct List *list, int pos, int value) {

    struct Node *temp = list->head;

    for (int i = 1;
         i < pos && temp != NULL;
         i++) {

        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Invalid position.\n");
        return;
    }

    temp->data = value;
}


// Count Nodes
void countNodes(struct List *list) {

    int count = 0;

    struct Node *temp = list->head;

    while (temp != NULL) {

        count++;

        temp = temp->next;
    }

    printf("Total Nodes = %d\n", count);
}


int main() {

    struct List list;

    list.head = NULL;

    int choice, value, pos, key;


    do {

        printf("\n===== LINKED LIST MENU =====\n");

        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Insert Middle\n");

        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Delete Middle\n");

        printf("7. Update Front\n");
        printf("8. Update Rear\n");
        printf("9. Update Middle\n");

        printf("10. Search\n");
        printf("11. Display\n");
        printf("12. Count Nodes\n");

        printf("13. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);


        switch (choice) {


        case 1:

            printf("Enter value: ");
            scanf("%d", &value);

            insertFront(&list, value);

            break;


        case 2:

            printf("Enter value: ");
            scanf("%d", &value);

            insertRear(&list, value);

            break;


        case 3:

            printf("Enter value and position: ");
            scanf("%d%d", &value, &pos);

            insertMiddle(&list, value, pos);

            break;


        case 4:

            deleteFront(&list);

            break;


        case 5:

            deleteRear(&list);

            break;


        case 6:

            printf("Enter position: ");
            scanf("%d", &pos);

            deleteMiddle(&list, pos);

            break;


        case 7:

            printf("Enter new value: ");
            scanf("%d", &value);

            updateFront(&list, value);

            break;


        case 8:

            printf("Enter new value: ");
            scanf("%d", &value);

            updateRear(&list, value);

            break;


        case 9:

            printf("Enter position and new value: ");
            scanf("%d%d", &pos, &value);

            updateMiddle(&list, pos, value);

            break;


        case 10:

            printf("Enter value to search: ");
            scanf("%d", &key);

            search(&list, key);

            break;


        case 11:

            display(&list);

            break;


        case 12:

            countNodes(&list);

            break;


        case 13:

            printf("Program Ended.\n");

            break;


        default:

            printf("Invalid Choice.\n");
        }


    } while (choice != 13);


    return 0;
}

