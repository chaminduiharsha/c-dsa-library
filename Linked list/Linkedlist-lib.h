#ifndef Linkedlist_lib_h
#define Linkedlist_lib_h

struct Node {

    int data;
    struct Node *next;
};

struct List {
    struct Node *head;
};

void display(struct List *list);
void search(struct List *list, int key);
void insertFront(struct List *list, int value);
void insertRear(struct List *list, int value);
void insertMiddle(struct List *list, int value, int pos);
void deleteFront(struct List *list);
void deleteRear(struct List *list);
void deleteMiddle(struct List *list, int pos);
void updateFront(struct List *list, int value);
void updateRear(struct List *list, int value);
void updateMiddle(struct List *list, int pos, int value);
void countNodes(struct List *list);




#endif Linkedlist_lib_h

