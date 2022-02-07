#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "program.h"
#include "methods.h"


void printPerson (struct Person *person){
	printf("%s %s %s %s \n", person->name, person->surname, person->number, person->email);
}
void printUsage(){
	printf("\nAvailable commands:\n");
	printf("v is for view all persons\n");
	printf("a is for add person in the end of list\n");
	printf("p is for add person in specific position\n");
	printf("e is for delete one person from list in position\n");
	printf("d is for delete all persons from list\n");
	printf("f is for find person from position in list\n");
	printf("g is for find person from list by name, surname, email or phone number\n");
	printf("c for commands\n");
	printf("q for exit\n");
}
void parseUserInput(char name[30], char surname[30], char phoneNumber[30], char email[30]){
	printf("Enter name: ");
	scanf("%s", name);
	printf("Enter surname: ");
	scanf("%s", surname);
	printf("Enter phone number: ");
	scanf("%s", phoneNumber);
	printf("Enter email: ");
	scanf("%s", email);
}

void parseUserInputPosition(char position[10]){
	printf("Enter position: ");
	scanf("%s", position);
}


void actions(char operator, struct Person **list){
	char name[30], surname[30], phoneNumber[30], email[30], textOrPosition[30];
	int countFound = 1;
	int listSize;
	struct Person *person = NULL;
	struct Person *personForCheck = NULL;
	switch(operator) {
			case 'v':
				printList(*list, INT_MAX);
				break;
			case 'a':
				parseUserInput(name,surname,phoneNumber,email);
				printf("%s %s %s %s\n", name,surname,phoneNumber,email);
				person = createNode(name,surname,phoneNumber,email);
				if (person != NULL) {
				   addToList(list, person);
				   printf("Person was added to list\n");
				}
				else{
					printf("Failed to create person node\n");
				}
				break;
			case 'd':
				deleteList(list);
				if(*list == NULL)
				{
					printf("List was deleted\n");
				}
				break;
			case 'p':
				parseUserInput(name,surname,phoneNumber,email);
				parseUserInputPosition(textOrPosition);
				listSize = listCount(*list);
				if (atoi(textOrPosition) < 1){
					printf("Position is to low\n");
					break;
				}
				else if(atoi(textOrPosition) > listSize){
					printf("Position is to high\n");
					break;
				}
				printf("%s %s %s %s %s\n", name,surname,phoneNumber,email,textOrPosition);
				person = createNode(name,surname,phoneNumber,email);
				if (person != NULL) {
				addToListPosition(list, person, atoi(textOrPosition)-1);
				personForCheck = findByPosition(*list,atoi(textOrPosition)-1);
				if (person == personForCheck)
				{
					printf("Person was added\n");
				}
				else{
					printf("Person was NOT added\n");
				}
				}
				break;
			case 'e':
				parseUserInputPosition(textOrPosition);

				listSize = listCount(*list);
				if (atoi(textOrPosition) < 1){
					printf("Position is to low\n");
					break;
				}
				else if(atoi(textOrPosition) > listSize){
					printf("Position is to high\n");
					break;
				}

				person = findByPosition(*list,atoi(textOrPosition)-1);
				deleteByPosition(list,atoi(textOrPosition)-1);

				personForCheck = findByPosition(*list,atoi(textOrPosition)-1);
				if (personForCheck != person){
					printf("Person was deleted\n");
				}
				else{
					printf("Person was NOT deleted\n");
				}
				break;
			case 'f':
				parseUserInputPosition(textOrPosition);
				person = findByPosition(*list,atoi(textOrPosition)-1);
				if (person != NULL){
				printf("Person was found\n");
				printPerson(person);
				break;
				}
				else{
					printf("Person was NOT found\n");
				}
				break;
			case 'g':
				printf("Search by text: ");
				scanf("%s", textOrPosition);
				person = findByText(*list,textOrPosition,countFound);
				if (person == NULL)
				{
					printf("Person was not found");
					break;
				}
				while(person != NULL)
				{
					printPerson(person);
					countFound++;
					person = findByText(*list,textOrPosition,countFound);
				}
				break;
			case 'c':
				printUsage();
				break;
			case '\n':
				break;
			default:
				printf("Command not found\n");
		}
}

int main(void){
char address_file_path[30] = "addresses.csv";
    struct Person *list = NULL;
    FILE *address_file = NULL;
    address_file = fopen(address_file_path, "r");
    if( address_file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    loadAddresses(address_file, &list);
	fclose(address_file);
	printList(list, 10);
	printUsage();
	
	char operator;
	printf("Enter command: ");
	while((operator = getchar()) != '0') {
		if (operator == 'q'){
			deleteList(&list);
			break;
		}
		if (operator != '\n') {
			actions(operator, &list);
			printf("\nEnter command: ");
		}
	}
    return 0;
}