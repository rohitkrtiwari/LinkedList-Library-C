#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};

void list_functions();
void display(struct node *);
struct node * append(struct node *, int);
struct node * clear(struct node *);
struct node * copy(struct node *);
int size(struct node *);
struct node * extend(struct node *, struct node *);
int index(struct node *, int);
struct node * insert(struct node *, int, int);
struct node * delete(struct node *, int);
struct node * reverse(struct node *);
struct node * sort(struct node *);


void list_functions(){
    
    printf("\n\n\t************ LINKED LIST ************\n");
    printf("\ninclude the header file : \t#include 'list.h'");
    printf("\nList Declaration : \t\tstruct node * list-name = NULL;");
    
    printf("\n\nTo add a new element at end: \tlist = append(list, x);");
    printf("\nTo clear all element : \t\tlist = clear(list);");
    printf("\nTo Duplicate a list : \t\tlist2 = copy(list1);");
    printf("\nSize of List : \t\t\tint size = size(list);");
    printf("\nExtend List2 in List 1 : \tlist1 = extend(list1, list2);");
    printf("\nIndex of some data : \t\tint index = index(list, data);");
    printf("\nInsert at nth Index : \t\tlist = insert(list, data, position);");
    printf("\nDelete some data from list : \tlist = delete(list, data);");
    printf("\nReverse the list : \t\tlist = reverse(list);");
    printf("\nSort the list : \t\tlist = sort(list);");

    printf("\nList the Functions : \t\tlist_functions();");


}

void display(struct node * head){
    struct node * p = head;
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
struct node * append(struct node * head, int data){
    struct node * ptr = head;
    struct node * temp = (struct node *) malloc (sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        return head;
    }
    else{
        while (ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next = temp;
        return head;
    }
}

struct node * clear(struct node * head){
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    return head;
}

struct node * copy(struct node * head){
    if (head == NULL) {
        return NULL;
    }
    else {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = head->data;
        newNode->next = copy(head->next);
        return newNode;
    }   
}

int size(struct node * head){
    struct node * p = head;
    int size=0;
    while (p!=NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

struct node * extend(struct node * list1, struct node * list2){
    struct node * p = list1;
    struct node * q = list2;
    
    if(p !=NULL ){

        if(p != NULL){
            while (p->next!=NULL) 
                p = p->next;

            while (q!=NULL) {
                p = append(p, q->data);                
                q = q->next;
            }
        }
    }   
    return list1;
}

int index(struct node * head, int data){
    struct node * p = head;
    int count = 0;
    if(head != NULL){
        while (p!=NULL)
        {   
            if(p->data == data)
                return count;
            p = p->next;
            count ++;
        }
    }
    return -1;
}

struct node * insert(struct node * head, int data, int pos){
    if(head==NULL){
        printf("\nInvalid Position");
        return head;
    }
    else{
        int c = size(head);
        struct node * temp = (struct node *) malloc (sizeof(struct node));
        temp->data = data;
        temp->next = NULL;

        if(pos>c || pos < 0){
            printf("\nInvalid Position");
            return head;
        }
        // inserting first node
        else if(pos == 0){
            temp->next = head; 
            head = temp;
            return head;
        }
        else{
            struct node * ptr = head;
            while (--pos)
                ptr=ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
            return head;
        }
    }
}

struct node * delete(struct node *head, int key){
    struct node *temp, *prev;
    temp = head;
    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        free(temp); 
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    prev->next = temp->next;
    free(temp); 
    return head;
}


struct node * reverse(struct node * head){
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
struct node * sort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
    if (start == NULL)
        return start;
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    return start;
}