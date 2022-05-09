#include <stdio.h>
#include "list.h"

int main() {
    // Prints all the avalaibale methods of this modules
    list_functions();

    // Some List operations 
    num l1;
    l1 = init(l1);
    l1 = append(l1, 12);
    l1 = append(l1, 23);
    l1 = append(l1, 34);
    display(l1);
}