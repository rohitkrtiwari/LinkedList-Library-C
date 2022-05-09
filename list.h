#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *num;

num init();
void list_functions();
void display(num);
num append(num, int);
num clear(num);
num copy(num);
int size(num);
num extend(num, num);
int index(num, int);
num insert(num, int, int);
num delete (num, int);
num reverse(num);
num sort(num);

num init(num head)
{
    head = NULL;
    return head;
}

void list_functions()
{

    printf("\n\n\t************ LINKED LIST ************\n");
    printf("\ninclude the header file : \t#include 'list.h'");
    printf("\nList Declaration : \t\tnum list;");
    printf("\nList init : \t\t\tlist = init(list);");

    printf("\n\nTo Print the elements of list: \tdisplay(list);");
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

void display(num head)
{
    num p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
num append(num head, int data)
{
    num ptr = head;
    num temp = (num)malloc(sizeof(num));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        return head;
    }
}

num clear(num head)
{
    num current = head;
    num next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    return head;
}

num copy(num head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        num newnum = (num)malloc(sizeof(num));
        newnum->data = head->data;
        newnum->next = copy(head->next);
        return newnum;
    }
}

int size(num head)
{
    num p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

num extend(num list1, num list2)
{
    num p = list1;
    num q = list2;
    if (p != NULL)
    {
        if (p != NULL)
        {
            while (p->next != NULL)
                p = p->next;
            while (q != NULL)
            {
                p = append(p, q->data);
                q = q->next;
            }
        }
    }
    return list1;
}

int index(num head, int data)
{
    num p = head;
    int count = 0;
    if (head != NULL)
    {
        while (p != NULL)
        {
            if (p->data == data)
                return count;
            p = p->next;
            count++;
        }
    }
    return -1;
}

num insert(num head, int data, int pos)
{
    if (head == NULL)
    {
        printf("\nInvalid Position");
        return head;
    }
    else
    {
        int c = size(head);
        num temp = (num)malloc(sizeof(num));
        temp->data = data;
        temp->next = NULL;
        if (pos > c || pos < 0)
        {
            printf("\nInvalid Position");
            return head;
        }
        else if (pos == 0)
        {
            temp->next = head;
            head = temp;
            return head;
        }
        else
        {
            num ptr = head;
            while (--pos)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
            return head;
        }
    }
}

num delete (num head, int key)
{
    num temp, prev;
    temp = head;
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

num reverse(num head)
{
    num prev = NULL;
    num current = head;
    num next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void swap(num a, num b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
num sort(num start)
{
    int swapped, i;
    num ptr1;
    num lptr = NULL;
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
    } while (swapped);
    return start;
}