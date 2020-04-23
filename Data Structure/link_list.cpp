#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
  int data;
  Node* next;
};

class LinkList{
public:
  Node* head;
  int count;

  LinkList(){
    head = NULL;
    count = 0;
  }

  void insert(int n, int idx=1) {
    /*
    Insert n at idx in the link list
    */
    printf("Insert %d at position %d \n", n, idx);
    Node* tmp = new(Node);
    tmp->data = n;
    if ( head==NULL ){
      head = tmp;
      tmp->next = NULL;
    }
    else {
      Node* tmp2 = head;
      for (int i=0; i<idx-2; ++i) {
        tmp2 = tmp2->next;
      }
      tmp->next = tmp2->next;
      tmp2->next = tmp;
    }
    // if ( idx==1 ) {
    //   tmp->next = head;
    //   head = tmp;
    // }
    // else{
    //   Node* tmp2 = head;
    //   for (int i=0; i<idx-2; ++i) {
    //     tmp2 = tmp2->next;
    //   }
    //   tmp->next = tmp2->next;
    //   tmp2->next = tmp;
    // }
    count++;
    iteration_print();
    cout << endl;
  }

  void delet(int idx) {
    printf("Delete data at position %d \n", idx);
    Node* tmp = head;
    Node* to_del;
    if ( idx == 1 ) {
       to_del = head;
      head = to_del->next;
    }
    else {
      // traverse to the idx-1 node
      for (int i=0; i<idx-2; ++i) {
        tmp = tmp->next;
      }
      to_del = tmp->next;
      tmp->next = to_del->next;
    }
    delete to_del;

    count--;
    iteration_print();
    cout << endl;
  }

  void iteration_reverse() {
    if (head == NULL) {return;}
    Node* pre = NULL;
    Node* cur = head;
    Node* tmp;
    while (cur->next != NULL) {
      tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    cur->next = pre;
    head = cur;
  }

  void recursion_reverse(Node* p) {
    if ( p->next == NULL ) {
      head = p;
      return;
    }
    recursion_reverse(p->next);
    p->next->next = p;
    p->next = NULL;
  }

  void iteration_print() {
    Node* tmp = head;
    while (tmp != NULL ) {
      cout << tmp->data << ' ';
      tmp = tmp->next;
    }
    cout << endl;
  }

  void recursion_print(Node* p) {
    if ( p == NULL ){
      cout << endl;
      return;
    }
    cout << p->data << ' ';
    recursion_print(p->next);
  }

  void revserse_print(Node* p) {
    if ( p == NULL ){
      return;
    }
    revserse_print(p->next);
    cout << p->data << ' ';
  }
}; // end class LinkList


int main(int argc, char const *argv[]) {
  LinkList llist;
  llist.insert(1);
  llist.insert(2, 2);
  llist.insert(3, 3);
  llist.insert(5, 4);
  llist.insert(4, 4);
  llist.delet(2);

  cout << "Iterative Reverse List" << endl;
  llist.iteration_reverse();
  llist.iteration_print();
  cout << endl;

  cout << "Recursive Reverse List" << endl;
  llist.recursion_reverse(llist.head);
  llist.iteration_print();
  cout << endl;

  cout << "Recursive Print" << endl;
  llist.recursion_print(llist.head);
  cout << endl;

  cout << "Reverse Recursive Print" << endl;
  llist.revserse_print(llist.head);
  cout << endl;
  return 0;
}
