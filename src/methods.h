struct Person* createNode(char *name, char *surname, char *number, char *email);
struct Person* createAddressNode(char *address_line);
void loadAddresses(FILE *file, struct Person **list);