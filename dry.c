#include "dry.h"
#include <stdio.h>
#include <stdbool.h>

static ErrorCode destroyList(Node head, Node* merged_out) {
	while(head) {
		Node toDelete = head;
		head = head->next;
		free(toDelete);
	}
    merged_out = NULL;
    return MEMORY_ERROR;
}

static Node createNode(int x) {
	Node newNode = malloc(sizeof(*newNode));
	if(!newNode) {
		return NULL;
	}
	newNode->x = x;
	newNode->next = NULL;
	return newNode;
}

ErrorCode mergeSortedLists(Node list1, Node list2, Node* merged_out)
{
    if(merged_out == NULL) {
        return NULL_ARGUMENT;
    }
    if ((!(getListLength(list1)) && !(getListLength(list2)))) {
        return EMPTY_LIST;
    }
    if ((!(isListSorted(list1)) || !(isListSorted(list2)))) {
        return UNSORTED_LIST;
    }
        
    bool is_first_time = true; 
    Node ptr;
    Node head;
    do {
        if(list1) {
            if (list2) {
                //insert from list1 OR list2
                ((list1->x) < (list2->x)) ? (ptr = createNode(list1->x)) : (ptr = createNode(list2->x));
                ((list1->x) < (list2->x)) ? (list1=list1->next) : (list2 = list2->next);
            }
            else {
                ptr = createNode(list1->x); //insert from list1
                list1 = list1->next;
            }
    
        }
        else {
                ptr = createNode(list2->x); //insert from list2
                list2 = list2->next;
        }
        if(is_first_time) {
            head = ptr;
            is_first_time=false;
        }
        if(!ptr) {
            return destroyList(head, merged_out);
        }
        ptr=ptr->next;
    } while (list1 || list2);
    merged_out = &head;
    return SUCCESS;
}