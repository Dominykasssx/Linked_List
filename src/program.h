struct Person {
    char name[30];
    char surname[30];
    char number[30];
	char email[30];
    struct Person *next;
};

void addToList(struct Person **list, struct Person *node);
void printList(struct Person *list, int countNumber);
void deleteList(struct Person **list);
void addToListPosition(struct Person **list, struct Person *person, int position);
struct Person* findByPosition(struct Person *list, int position);
struct Person* findByText(struct Person *list, char text[30], int count);
void deleteByPosition(struct Person **list, int position);
int listCount(struct Person *list);