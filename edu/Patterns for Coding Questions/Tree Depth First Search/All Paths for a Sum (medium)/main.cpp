/*
Problem Statement #
Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that
the sum of all the node values of each path equals ‘S’.


Time complexity #
The time complexity of the above algorithm is O(N^2), where ‘N’ is the total
number of nodes in the tree. This is due to the fact that we traverse each node
once (which will take O(N), and for every leaf node we might have to store its
path which will take O(N).

We can calculate a tighter time complexity of O(NlogN) from the space
complexity discussion below.

Space complexity #
If we ignore the space required for the allPaths list, the space complexity of
the above algorithm will be O(N) in the worst case. This space will be used to
store the recursion stack. The worst case will happen when the given tree is a
linked list (i.e., every node has only one child).
How can we estimate the space used for the allPaths array? Take the example of
the following balanced tree: Here we have seven nodes (i.e., N = 7). Since, for
binary trees, there exists only one path to reach any leaf node, we can easily
say that total root-to-leaf paths in a binary tree can’t be more than the number
of leaves. As we know that there can’t be more than N/2 leaves in a binary tree,
therefore the maximum number of elements in allPaths will be O(N/2) = O(N). Now,
each of these paths can have many nodes in them. For a balanced binary tree,
each leaf node will be at maximum depth. As we know that the depth (or height)
of a balanced binary tree is O(logN) we can say that, at the most, each path can
have logNlogN nodes in it. This means that the total size of the allPaths list
will be O(N*logN). If the tree is not balanced, we will still have the same
worst-case space complexity.
From the above discussion, we can conclude that the overall space complexity of
our algorithm is O(N*logN).

Also from the above discussion, since for each leaf node, in the worst case, we
have to copy log(N) nodes to store its path, therefore the time complexity of
our algorithm will also be O(N*logN).
*/

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    findPathsRecursive(root, sum, currentPath, allPaths);
    return allPaths;
  }

 private:
  static void findPathsRecursive(TreeNode *currentNode, int sum, vector<int> &currentPath,
                                 vector<vector<int>> &allPaths) {
    if (currentNode == nullptr) {
      return;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);

    // if the current node is a leaf and its value is equal to sum, save the current path
    if (currentNode->val == sum && currentNode->left == nullptr && currentNode->right == nullptr) {
      allPaths.push_back(vector<int>(currentPath));
    } else {
      // traverse the left sub-tree
      findPathsRecursive(currentNode->left, sum - currentNode->val, currentPath, allPaths);
      // traverse the right sub-tree
      findPathsRecursive(currentNode->right, sum - currentNode->val, currentPath, allPaths);
    }

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
