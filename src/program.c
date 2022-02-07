#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "program.h"


void addToList(struct Person **list, struct Person *person){
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
}
void addToListPosition(struct Person **list, struct Person *person, int position){
	
	int i = 0;
    struct Person *previous;
	struct Person *current;
	struct Person *new;
	
    new= person;
	
	previous = NULL;
	
	for (current = *list;  current != NULL;  current = current->next, i += 1) {
        if (i >= position)
            break;
        previous = current;
    }
	
	new->next = current;
	
	if (previous != NULL)
        previous->next = new;
    else
        *list = new;
}


void printList(struct Person *list, int countNumber){
	int i = 0;
    struct Person *temp = list;
    while (temp != NULL && i < countNumber) {
        printf("%s %s %s %s \n", temp->name, temp->surname, temp->number, temp->email);
        temp = temp->next;
		i++;
    }
}

void deleteList(struct Person **list) {
	struct Person *to_delete = *list;
    while (*list != NULL) 
	{
        *list = (*list)->next;
        free(to_delete);
        to_delete = *list;
    }
}

struct Person* findByPosition(struct Person *list, int position){
	int i = 0;
    struct Person *temp = list;
    struct Person *person = NULL;
    while (temp != NULL) {
		if(i == position)
        {
			person = temp;
			break;
		}
        temp = temp->next;
		i++;
    }	
    return person;
}

    struct Person* findByText(struct Person *list, char text[30], int count){
	int i = 0;
    int countFound = 0;
    struct Person *temp = list;
    struct Person *person = NULL;
    while (temp != NULL) {
		if(strcmp(temp->name,text) == 0 || strcmp(temp->surname,text) == 0|| strcmp(temp->number,text)== 0|| strcmp(temp->email,text)== 0){
            countFound++;
            if(countFound == count){
                person = temp;
            }
		}
        temp = temp->next;
		i++;
    }
		return person;
}
int listCount(struct Person *list){
    int i = 0;
    struct Person *temp = list;
    while (temp != NULL) {
        temp = temp->next;
		i++;
    }	
    return i;
}

void deleteByPosition(struct Person **list, int position) {
	int i = 0;
	struct Person *to_delete = *list;
	
	
	if (position == 0) {
    *list = to_delete->next; 
    free(to_delete);
    return;
    }
	for (int i = 0; to_delete != NULL && i < position - 1; i++)
        to_delete = to_delete->next;
        
	struct Person *next = to_delete->next->next;
    free(to_delete->next); 
    to_delete->next = next; 
}
