#include <stdio.h>
#include "os_nodes.h"


int main() {

  struct os_node* myhead = NULL;
  struct os_node *newnode = create_node(10000, "Mark", "Twain", 89);
  // add first node to an empty structure
  add_node(&myhead, newnode);
  // create and add new
  newnode = create_node(10001, "Richard", "Nixon", 91);
  add_node(&myhead, newnode);
  // creae and add new
  newnode = create_node(10001, "Abraham", "Lincoln", 70);
  add_node(&myhead, newnode);

  // print all the list
  print_nodes(myhead);

  // free nodes backwards
  free_nodes(&myhead);
  // here head should be NULL
  
}
