
#include "linkedListCells.h"

void add_cell_curr(LinkedListCells *list, Cell *c) {
    NodeCell* newNode;
    NodeCell* temp = list->current->next;
    newNode = alloc_node_cell(c);
    if(temp!=NULL) {
        list->current->next->prev = newNode;
        list->current->next = newNode;
    }

    if(list->head == NULL){

    }
    newNode->prev = list->current;
    newNode->next = temp;
    list->len ++;
}

Cell *get_curr_cell(LinkedListCells *list) {
    return list->current->c;
}

NodeCell * alloc_node_cell(Cell* c) {
    NodeCell* nodeC = calloc(3, sizeof(int*));
    nodeC->c = c;
    return nodeC;
}

Cell *get_head_cell(LinkedListCells *list) {
    return list->head->c;
}

int next_cell(LinkedListCells *list) {
    if (list->current->next == NULL) {
        error("linkedListCells","next_cell",3);
        return 0;
    }
    list->current = list->current->next;
    return 1;
}

int prev_cell(LinkedListCells *list) {
    if(list->head = list->current) {
        error("linkedListCells","prev_cell",4);
        return 0;
    }
    list->current = list->current->prev;
    return 1;
}

void move_curr_to_head(LinkedListCells *list) {
    list->current=list->head;
}

LinkedListCells *alloc_linked_list_cells() {
    LinkedListCells* newlist = calloc(3, sizeof(int*));
    if(newlist == NULL){
        error("linkedListCells","alloc_linked_list_cells",1);
        exit(0);
    }
}

void free_node_cell(NodeCell *node) {
    free(node->c);
    free(node->prev);
    free(node->next);
}

void free_linked_list_cells(LinkedListCells *list) {
    NodeCell* temp= list->current;
    if(temp!=NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != list->head) {
            temp = temp->prev;
            free_node_cell(temp->next);
        }
        free(list->current);
        free_node_cell(list->head);
        free(list->head);
    }
}