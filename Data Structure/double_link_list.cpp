#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next;
};

class DoubleLinkList {
private:
  Node* head;
  int count;

public:
  DoubleLinkList() {
    head = NULL;
    count = 0;
  }

  Node* create_new_node(int x) {
    Node* newnode = new(Node);
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next= NULL;
    return newnode;
  }

  void insert_at_head(int x) {
    printf("Insert %d at head \n", x);
    Node* node = create_new_node(x);
    if ( head == NULL ) {
      head = node;
    }
    else {
      node->next = head;
      head = node;
    }
    print_list();
  }

  void print_list() {
    Node* tmp = head;
    while ( tmp != NULL ) {
      cout << tmp->data << ' ';
      tmp = tmp->next;
    }
    cout << endl;
  }
}; // end class DoubleLinkList

int main(int argc, char const *argv[]) {
  DoubleLinkList dllist;
  dllist.insert_at_head(1);
  dllist.insert_at_head(2);
  dllist.insert_at_head(3);
  return 0;
}
