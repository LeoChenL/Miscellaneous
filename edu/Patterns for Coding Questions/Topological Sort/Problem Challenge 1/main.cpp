/*
Reconstructing a Sequence (hard) #
Given a sequence originalSeq and an array of sequences, write a method to find
if originalSeq can be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only
sequence such that all sequences in the array are subsequences of it.

Example 1:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order
of numbers
in the 'originalSeq'.
Example 2:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct
[1, 2, 3, 4]. There are two possible sequences we can construct from the given
sequences:
1) [1, 2, 3, 4]
2) [1, 2, 4, 3]
Example 3:

Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct
[3, 1, 4, 2, 5].

Time complexity #
In step ‘d’, each number can become a source only once and each edge (a rule)
will be accessed and removed once. Therefore, the time complexity of the above
algorithm will be O(V+E), where ‘V’ is the count of distinct numbers and
‘E’ is the total number of the rules. Since, at most, each pair of numbers can
give us one rule, we can conclude that the upper bound for the rules is O(N)
where ‘N’ is the count of numbers in all sequences. So, we can say that the time
complexity of our algorithm is O(V+N).

Space complexity #
The space complexity will be O(V+N), since we are storing all of the
rules for each number in an adjacency list.
*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class SequenceReconstruction {
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    vector<int> sortedOrder;
    if (originalSeq.size() <= 0) {
      return false;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (auto seq : sequences) {
      for (int i = 0; i < seq.size(); i++) {
        inDegree[seq[i]] = 0;
        graph[seq[i]] = vector<int>();
      }
    }

    // b. Build the graph
    for (auto seq : sequences) {
      for (int i = 1; i < seq.size(); i++) {
        int parent = seq[i - 1], child = seq[i];
        graph[parent].push_back(child);
        inDegree[child]++;
      }
    }

    // if we don't have ordering rules for all the numbers we'll not able to uniquely construct the
    // sequence
    if (inDegree.size() != originalSeq.size()) {
      return false;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      if (sources.size() > 1) {
        return false;  // more than one sources mean, there is more than one way to reconstruct the
                       // sequence
      }
      if (originalSeq[sortedOrder.size()] != sources.front()) {
        return false;  // the next source (or number) is different from the original sequence
      }
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder's size is not equal to original sequence's size, there is no unique way to
    // construct
    return sortedOrder.size() == originalSeq.size();
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
