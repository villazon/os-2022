// the structure
struct os_node {
  int age;
  // add other elements
  struct os_node *next;
};

// create a new node, return the new allocated one
struct os_node* create_node(long ID, char * first_name, char * family_name, int age);

// add node at the end of the list
int add_node(struct os_node** head, struct os_node *toadd);
// remove the first element of the list, and return the removed node
struct os_node* remove_first(struct os_node** head);
// remove the last element of the list, and return the removed node
struct os_node* remove_last(struct os_node**head);
// print nodes of all the list
void print_nodes(struct os_node* head);
// remove all the 
int free_nodes(struct os_node** head);


