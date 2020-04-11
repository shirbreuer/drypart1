#include "dry.h"
#include <stdio.h>
#include <stdbool.h>

ErrorCode mergeSortedLists(Node list1, Node list2, Node* merged_out)
{
    if(list1 == NULL || list2 == NULL || merged_out == NULL) {
        return NULL_ARGUMENT;
    }
    if ((!(getListLength(list1)) || !(getListLength(list2)))) {
        return EMPTY_LIST;
    }
    if ((!(isListSorted(list1)) || !(isListSorted(list2)))) {
        return UNSORTED_LIST;
    }

    ((list1->x) < (list2->x)) ? ((*merged_out) = createNode(list1)) : ((*merged_out) = createNode(list2));
    if(!(*merged_out)) {
            merged_out = NULL;
            return MEMORY_ERROR;
        }

    Node head = *merged_out;
    (*merged_out)=(*merged_out)->next;

    while(list1 || list2) {

        if (list1 && list2) {
            ((list1->x) < (list2->x)) ? ((*merged_out) = createNode(list1)) : ((*merged_out) = createNode(list2));
            if (!(*merged_out)->next) {
                merged_out = destroyList(head);
                return MEMORY_ERROR;
            }
            (*merged_out)=(*merged_out)->next;
        }

        ((list1) ? ((*merged_out) = createNode(list1)) : ((*merged_out) = createNode(list2)));
        if (!(*merged_out)->next) {
            merged_out = destroyList(head);
            return MEMORY_ERROR;
        }
        (*merged_out)=(*merged_out)->next;
    }

    *merged_out = head;
    return SUCCESS;
}

Node* destroyList(Node ptr) {
	while(ptr) {
		Node toDelete = ptr;
		ptr = ptr->next;
		free(toDelete);
	}
    return NULL;
}

Node createNode(Node List) {
	Node ptr = malloc(sizeof(*ptr));
	if(!ptr) {
		return NULL;
	}
	ptr->x = List->x;
    List=List->next;
	ptr->next = NULL;
	return ptr;
}