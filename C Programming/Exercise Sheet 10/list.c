#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/* Create a new list with the given value */
list_t *list_init(void *value)
{
    list_t *list = malloc(sizeof(list_t));
    node_t *startNode = malloc(sizeof(node_t));
    list->startNode = malloc(sizeof(node_t));
    list->endNode = list->startNode;
    startNode = startNode->data = value;
    startNode->prev = NULL;
    startNode->next = NULL;
}

/*
 * Free the list element and all connected list elements
 */
void list_free(list_t *lst, void (*freefunc)(void *data))
{
    node_t *currentNode = lst->startNode;
    while (currentNode->next != NULL)
    {
        freefunc(currentNode->data);
        freefunc(currentNode->prev);
        node_t *nextNode = currentNode->next;
        freefunc(currentNode);
        currentNode = nextNode->next;
    }
    freefunc(lst->startNode);
    freefunc(lst->endNode);
    freefunc(lst);
}

/* Link a new list element with the specified value right of the lst
 * @Return the new list element that stores the value
 */
list_t *list_append(list_t *lst, void *value)
{
    //TODO: newNode just replaced endNode. Prev is current end node//

    node_t *newNode = malloc(sizeof(node_t));
    node_t *endNode = lst->endNode;

    lst->endNode = newNode;
    newNode->prev = endNode;
}

/*
 * Remove the list element from the linked list
 */
void list_unlink(list_t *lst)
{
}

/*
 * Return the list element right of this element
 * Return NULL if none
 */
node_t *list_right(list_t *lst)
{
}

/*
 * Return the list element left of this element
 * Return NULL if none
 */
node_t *list_left(list_t *lst)
{
}

/*
 * Return the number of elements in this list
 */
int list_size(list_t *lst)
{
}

/*
 * Return the value stored in the list element
 */
void *list_value(list_t *lst)
{
}

/*
 * Iterate through the list forward (from the current list element) calling listfunc() on each element
 */
void list_iterate_fwd(list_t *lst, void (*traversefunc)(void *data))
{
}