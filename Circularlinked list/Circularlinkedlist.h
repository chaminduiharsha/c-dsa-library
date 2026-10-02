#ifndef Circularlinkedlist_lib_h
#define Circularlinkedlist_lib_h


struct node{

    int data;
    struct node *next;
};

struct List{

    struct node *head;
    struct node*tail;
};


void createlinkedlist(struct List *list,int value);
void search(struct List *list,int key);
void display(struct List *list);
void insertRear(struct List *list,int value);
void insertFront(struct List *list,int value);
void insertMiddle(struct List *list,int value,int pos);
void deleteFront(struct List *list);
void deleteRear(struct List *list);
void deleteMiddle(struct List *list,int pos);
void updateFront(struct List *list,int value);
void updateRear(struct List *list,int value);
void updateMiddle(struct List *list,int pos,int value);
int countNodes(struct List *list);

#endif Circularlinkedlist_lib_h

