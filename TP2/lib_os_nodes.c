#include "os_nodes.h"
#include <stdio.h>

struct os_node* create_node(long ID,
			    char * first_name,
			    char * family_name,
			    int age){

  printf("create node...\n");
  return NULL;

}

int add_node(struct os_node** head, struct os_node *toadd) {
  printf("add_node..\n");
  return 0;
}


struct os_node* remove_first(struct os_node** head) {
  printf("remove first node from the list, return the removed element\n");
  return NULL;
}

struct os_node* remove_last(struct os_node**head){
  printf("remove last node from the list, return the removed element\n");
  return NULL;
}

void print_nodes(struct os_node* head) {
  printf("print_nodes\n");
}

int free_nodes(struct os_node** head) {
  printf("free_nodes\n");
  return 0;
}

