#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMETER ","
#include "program.h"
#include "methods.h"

void loadAddresses(FILE *file, struct Person **list){
    char line[128];
    while (fgets(line, sizeof(line), file)) {
		strtok(line, "\r");
        struct Person *person = NULL;
        if(strcmp(line, "\n") == 0) {
			break;
        }
        person = createAddressNode(line);
        if (person != NULL) {
            addToList(list, person);
        }
    }
}
struct Person* createAddressNode(char *address_line){
    struct Person *person = NULL;
    char *name;
    char *surname;
    char *number;
	char *email;

    name = strtok(address_line, DELIMETER);
    surname = strtok(NULL, DELIMETER);
    number = strtok(NULL, DELIMETER);
	email = strtok(NULL, DELIMETER);

    person = createNode(name, surname, number, email);
    
    return person;
}

struct Person* createNode(char *name, char *surname, char *number, char *email){
    struct Person *person = NULL;
    person = (struct Person*) malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->number, number);
	strcpy(person->email, email);
    person->next = NULL;
    return person;
}