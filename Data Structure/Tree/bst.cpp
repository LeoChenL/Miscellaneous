#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
  // binary tree node
  int data;
  Node* left;
  Node* right;
};

class BST {
private:
  Node* root;

  Node* insert(Node* rt, int x) {
    if ( rt == NULL ) {
      Node* new_node = get_new_node(x);
      rt = new_node;
    } else {
      if ( x <= rt->data ) {
        rt->left = insert(rt->left, x);
      } else {
        rt->right = insert(rt->right, x);
      }
    }
    return rt;
  }

  Node* search(Node* rt, int x) {
    if ( rt == NULL ) {
      return NULL;
    }
    else {
      if ( x == rt->data ) {
        return rt;
      }
      else if ( x < rt->data ) {
        return search(rt->left, x);
      } else {
        return search(rt->right, x);
      }
    }
  }

  Node* delete_node(Node* rt, int x) {
    if ( rt == NULL ) {
      return NULL;
    }
    else if ( x < rt->data ) {
      rt->left = delete_node(rt->left, x);
    }
    else if ( x > rt->data ) {
      rt->right = delete_node(rt->right, x);
    }
    else {
      // Left Node
      if ( rt->left == NULL && rt->right == NULL ) {
        delete rt;
        rt = NULL;
      }
      // Only has right node
      else if ( rt->left == NULL ) {
        Node* tmp = rt;
        rt = rt->right;
        delete tmp;
      }
      // Only has left node
      else if ( rt->right == NULL ) {
        Node* tmp = rt;
        rt = rt->left;
        delete tmp;
      }
      // Two child nodes
      else {
        Node* tmp = get_min_node(rt->right);
        rt->data = tmp->data;
        rt->right = delete_node(rt->right, tmp->data);
      }
    }
    return rt;
  }

  Node* get_min_node(Node* rt){
    Node* tmp = rt;
    while (tmp->left != NULL) {
      tmp = tmp->left;
    }
    return tmp;
  }

  int get_height(Node* rt) {
    if ( rt == NULL ) {
      return -1;
    }
    int left_h = get_height(rt->left);
    int right_h = get_height(rt->right);
    return max(left_h, right_h) + 1;
  }

  Node* get_new_node(int x) {
    Node* new_node = new(Node);
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  void traverse_in_order(Node* rt) {
    if (rt->left != NULL) {traverse_in_order(rt->left);}
    cout << rt->data << ' ';
    if (rt->right != NULL) {traverse_in_order(rt->right);}
  }

public:
  BST(){
    root = NULL;
  }

  Node* get_root() {
    return root;
  }

  void insert(int x) {
    root = insert(root, x);
  }

  bool search(int x) {
    if ( search(root, x) ) {
      cout << "Found" << endl;
      return true;
    } else {
      cout << "Not Found" << endl;
      return false;
    }
  }

  void delete_node(int x) {
    root = delete_node(root, x);
  }

  int get_height() {
    int h;
    if ( root == NULL ) {
      h = 0;
    } else {
      h = get_height(root);
    }
    cout << h <<endl;
    return h;
  }

  Node* get_min_node(){
    if ( root == NULL ) {
      cout << "NULL Tree" << endl;
      return NULL;
    } else {
      Node* min_node = get_min_node(root);
      cout << "min:" << min_node->data << endl;
      return min_node;
    }
  }

  Node* get_max_node() {
    if ( root == NULL ) {
      cout << "NULL" << endl;
      return NULL;
    } else {
      Node* tmp = root;
      while (tmp->right != NULL) {
        tmp = tmp->right;
      }
      cout << "max:" << tmp->data << endl;
      return tmp;
    }
  }

  void traverse_in_order() {
    if ( root == NULL ) {
      cout << "Empty Tree" << endl;
      return;
    } else {
      traverse_in_order(root);
    }
    cout << endl;
  }

  void traverse_level_order() {
    if ( root == NULL ) {
      cout << "Empty Tree" << endl;
      return;
    }
    queue<Node*> q;
    q.push(root);
    while ( !q.empty() ) {
      Node* tmp = q.front();
      cout << tmp->data << ' ';
      if (tmp->left  != NULL) {q.push(tmp->left);}
      if (tmp->right != NULL) {q.push(tmp->right);}
      q.pop();
    }
    cout << endl;
  }

  Node* get_successor(int x) {
    Node* nd = search(root, x);
    if (nd == NULL)
    {
      return NULL;
    }
    // has right subtree
    if ( nd->right != NULL ) {
      return get_min_node(nd->right);
    }
    // no right subtree
    else {
      Node* successor = NULL;
      Node* ancester = root;
      while ( ancester != nd ) {
        if (ancester->data > nd->data) {
          successor = ancester;
          ancester = ancester->left;
        } else {
          ancester = ancester->right;
        }
      }
      return successor;
    }
  }

}; // end class bst

bool is_BST(Node* rt) {
  if ( rt == NULL ) {
    return true;
  }

  bool left_ok = (rt->left  == NULL) || (rt->left  != NULL && is_BST(rt->left)
                                        && rt->left->data <= rt->data);
  bool right_ok = (rt->right  == NULL) || (rt->right != NULL && is_BST(rt->left)
                                          && rt->right->data > rt->data);

  if ( left_ok && right_ok) {
    return true;
  } else{
    return false;
  }
}

int main(int argc, char const *argv[]) {
  BST tree;
  tree.insert(5);
  tree.insert(2);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  cout << "Is a BST" << endl;
  if ( is_BST(tree.get_root()) ) {
    cout << "Is BST" << endl;
  } else {
    cout << "Not BST" << endl;
  }
  cout << endl;

  cout << "Height of tree" << endl;
  tree.get_height();
  cout << endl;

  cout << "Min in the tree" << endl;
  tree.get_min_node();
  cout << endl;

  cout << "Max in the tree" << endl;
  tree.get_max_node();
  cout << endl;

  cout << "Search 3 in the tree" << endl;
  tree.search(3);
  cout << endl;

  cout << "Level order" << endl;
  tree.traverse_level_order();
  cout << endl;

  cout << "In order" << endl;
  tree.traverse_in_order();
  cout << endl;

  cout << "Successor" << endl;
  Node* s_node = tree.get_successor(3);
  cout << s_node->data << endl;


  cout << "Delete Node 3" << endl;
  tree.delete_node(3);
  cout << endl;

  cout << "In order" << endl;
  tree.traverse_in_order();
  cout << endl;
  return 0;
}
