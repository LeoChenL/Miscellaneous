/*
Problem Statement #
Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
*/

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here
    if (head==nullptr) {
      return head;
    }


    ListNode *prehead = head;
    int i=0;
    while ( i < p-2 ) {
      prehead = prehead->next;
      i++;

      if ( prehead == nullptr ) {
        return head;
      }
    }
    cout<< "prehead"<< prehead->value<<endl;
    ListNode *ptr = prehead->next;
    ListNode *prev = nullptr;
    i=0;
    while ( ptr!=nullptr && i < q-p+1 ) {
      ListNode *next = ptr->next;
      ptr->next = prev;
      prev = ptr;
      ptr = next;
      i++;
    }
    prehead->next->next = ptr;
    prehead->next = prev;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
