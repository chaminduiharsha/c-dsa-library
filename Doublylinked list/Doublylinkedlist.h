#ifndef Doublylinkedlist_lib_h
#define Doublylinkedlist_lib_h

struct node{
    int data;
    struct node*prev;
    struct node *next;

};

struct List{
    struct node *head;
    struct node *tail;
};


void createlinkedlist(struct List *list,int value);
void search(struct List *list,int key);
void display(struct List *list);
void insertFront(struct List *list,int value);
void insertRear(struct List *list,int value);
void deleteRear(struct List *list);
void deleteFront(struct List *list);
void insertMiddle(struct List *list,int value,int pos);
void updateFront(struct List *list,int value);
void deleteMiddle(struct List *list,int pos);
void updateMiddle(struct List *list,int pos,int value);
void countNodes(struct List *list);
void updateRear(struct List *list,int value);


#endif Doublylinkedlist_lib_h

