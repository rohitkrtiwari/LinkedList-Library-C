# **Linked List Library Implemented in C**

A simple library implemented in C language for mananging Linked Lists

## **What is a Linked List**
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers as shown in the below image.
<br><br>
<img src="images/Linkedlist.png">


## **get repo**
<pre>
git clone https://github.com/rohitkrtiwari/C-Linked-List-Header.git 
</pre>


## **Starter Code**
<pre>
#include "list.h"
int main()
{
    struct node * list = NULL;     // list Declaration
    list_functions();              // Displays all the      functions of this module
    return 0;
}
</pre>


## **append()**
Adds the new element at end of the list
<pre>
list = append(list, 1);
</pre>

## **clear()**
Clears the entire list
<pre>
list = clear(list);
</pre>

## **copy()**
Copy the list to another list
<pre>
list2 = clear(list1);
</pre>

## **size()**
Returns the size of the list
<pre>
int s = size(list);
</pre>

## **extend()**
extends the data of a list to a list
<pre>
list1 = extend(list1, list2);
</pre>

## **index()**
Returns the index of data
<pre>
int i = index(list, data);
</pre>

## **delete()**
Deletes the data from the list
<pre>
list = delete(list, data);
</pre>


## **reverse()**
Returns the list in reverse order
<pre>
list = reverse(list);
</pre>

## **sort()**
Sorts the list in ascending order
<pre>
list = sort(list);
</pre>
