
#ifndef SP_LINKEDLISTCELLS_H
#define SP_LINKEDLISTCELLS_H

#include <stdlib.h>
#include "cell.h"
#include "errors.h"

/**
 * linkedListCell are nodes of linkedList, part of the linked list DS
 */


/**
* struct for node in list of cells. Contains a pointer to a cell and two pointers: previous and next nodes on the list.
*/
typedef struct NodeLinkedListCells{
    Cell* cell;
    struct NodeLinkedListCells* prev;
    struct NodeLinkedListCells* next;
}NodeCell;

/**
* struct of linked list of cells. Contains a field for list length and two pointers: head node of the list
* and current node of the list.
*/
typedef struct LinkedListCells{
    NodeCell* head;
    NodeCell* current;
    int len;
}LinkedListCells;

/**
* adds (cfter current) a node to the list contains the cell.
* if list is empty, adds that node to be head & current
* @param list of nodes type NodeCell
* @param c a cell to add
*/
void add_cell_after_curr(LinkedListCells *list, Cell *c);
/**
* @param list
* @return cell of current node of list. NULL if list is empty
*/
Cell *get_curr_cell(LinkedListCells *list);

int get_len_linked_list_cells(LinkedListCells* list);

/**
* moves the current cell pointer of the input list to the head cell.
* @param list != NULL
*/
void move_curr_to_head(LinkedListCells *list);

/**
* move current pointer to the next cell of the list
* @param list != NULL
* @return 1 if succeeded, 0 if there is'nt next cell after current
*/
int advance_curr_cell(LinkedListCells *list);

/**
* create new node contains cell c. next and prev are NULL
* @param c - cell the output node contains
* @return the new node
*/
NodeCell * alloc_node_cell(Cell* c);

/**
* allocate memory for linked list of cells.
* @return the empty list
*/
LinkedListCells* alloc_linked_list_cells();

/**
* free the ONLY cell field of input node
* @param node != NULL
*/
void free_node_cell(NodeCell *node);

/**
* free all the nodes in input list and its other fields
* @param list != NULL
*/
void free_linked_list_cells(LinkedListCells *list);

#endif
