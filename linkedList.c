#include <stdio.h>
#include "linkedList.h"

Node *get_head(LinkedList *list) {
    return list->head;
}

Node *get_curr(LinkedList *list) {
    return list->current;
}

int remove_next_after_curr(LinkedList *list) {
    Node *next = list->current->next;
    if (list->current == NULL) {
        error("linkedList","remove_next_after_curr",2);
        exit(0);
    }
    if (list->current->next == NULL) {
        return 1;
    }
    if (list->current->next->next == NULL) {
        list->current->next = NULL;
        free_node(next);
        list->len--;
        return 1;
    }
    list->current->next = list->current->next->next;
    list->current->next->next->prev = list->current;
    free_node(next);
    list->len--;
    return 1;
}

void remove_node(LinkedList *list, Node *node) {
    if (list->head == node) {
        list->head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if(node->next != NULL){
        node->next->prev = node->prev;
    }
    if(list->current == node){
        if(list->current == list->head){
            list->current = node->next;
        }
        else{
            list->current = node->prev;
        }
    }
    free_node(node);
    list->len--;

}

void remove_all_after_curr(LinkedList *list) {
    Node* temp = list->current->next;
    list->current->next = NULL;
    if(temp != NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
            temp->prev->next=NULL;
            list->len--;
        }
        free_node(temp);
        list->len--;
    }

}


void add_linked_list(LinkedList *list, Command *c, LinkedListCells *changed, int prevmode) {
    Node* newNode = alloc_node(c, changed, prevmode);
    if(list->current != NULL) {
        remove_all_after_curr(list);
        list->current->next = newNode;
        newNode->prev = list->current;
    }
    else{
        list->current = newNode;
        list->head = newNode;
    }
    list->len++;
}
Node * alloc_node(Command *c, LinkedListCells *changed, int prevmode){
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    if(newNode==NULL){
        error("linkedList","alloc_node",1);
        exit(0);
    }
    newNode->c = c;
    newNode->changed=changed;
    newNode->prevmode = prevmode;
    return newNode;
}
LinkedList *alloc_linkedList() {
    LinkedList* newList = (LinkedList*) calloc(1, sizeof(LinkedList));
    if(newList == NULL){
        error("linkedList","alloc_linkedList",1);
        exit(0);
    }
    return newList;
}
void advance_curr(LinkedList *list) {
    if(list->current == NULL){
        error("linkedList","advance_curr",2);
        exit(0);
    }
    if(list->current->next==NULL){
        error("linkedList","advance_curr",3);
        exit(0);
    }
    list->current = list->current->next;
}
void backward_curr(LinkedList *list) {
    if(list->current == NULL){
        error("linkedList","backward_curr",2);
        exit(0);
    }
    if(list->current->prev==NULL){
        error("linkedList","backward_curr",4);
        exit(0);
    }
    list->current=list->current->prev;
}

int get_prev_mode(Node *node) {
    return node->prevmode;
}

void free_node(Node *node) {
    if(node!= NULL) {
        free_linked_list_cells(node->changed);
        free_command(node->c);
        free(node);
    }
}

void free_linked_list(LinkedList *list) {
    Node* temp;
    if(list != NULL) {
        temp=list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        while(temp != list->head){
            temp=temp->prev;
            free_node(temp->next);
        }
        free(list);
    }
}

void print_linked_list_prevmode(LinkedList* list){
    Node* temp=list->head;
    printf("Linked list:\n");
    while(temp!=NULL){
        printf("%d, ",temp->prevmode);
        temp=temp->next;
    }
    printf("\n");
}

Command *get_command(Node *node) {
    return node->c;
}

int is_curr_last(LinkedList *list) {
    if (list->current->next==NULL)
        return 1;
    return 0;
}

LinkedListCells * get_changed_cells_list(Node *node) { return node->changed; }

int get_len_linked_list(LinkedList *list) { return list->len; }


