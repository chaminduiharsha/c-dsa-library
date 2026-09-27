#ifndef Array_lib_h
#define Array_lib_h



void traversel(int arr[],int *size);
int linearsearch(int arr[],int *size,int target);
int updateByvalue(int arr[],int *size,int oldValue,int newValue);
int insertAtanypos(int arr[],int *size,int capacity,int position,int value);
int deleteAtPosition(int arr[],int *size,int position);



#endif // Array_lib_h


