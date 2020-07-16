/*
Problem Statement #
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
*/

class PairWithTargetSum {

  public static int[] search(int[] arr, int targetSum) {
    int left = 0, right = arr.length - 1;
    while (left < right) {
      int currentSum = arr[left] + arr[right];
      if (currentSum == targetSum)
        return new int[] { left, right }; // found the pair

      if (targetSum > currentSum)
        left++; // we need a pair with a bigger sum
      else
        right--; // we need a pair with a smaller sum
    }
    return new int[] { -1, -1 };
  }

  public static void main(String[] args) {
    int[] result = PairWithTargetSum.search(new int[] { 1, 2, 3, 4, 6 }, 6);
    System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
    result = PairWithTargetSum.search(new int[] { 2, 5, 9, 11 }, 11);
    System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
  }
}

// An Alternate approach hashtable
// import java.util.HashMap;
//
// class PairWithTargetSum {
//
//   public static int[] search(int[] arr, int targetSum) {
//     HashMap<Integer, Integer> nums = new HashMap<>(); // to store numbers and their indices
//     for (int i = 0; i < arr.length; i++) {
//       if (nums.containsKey(targetSum - arr[i]))
//         return new int[] { nums.get(targetSum - arr[i]), i };
//       else
//         nums.put(arr[i], i); // put the number and its index in the map
//     }
//     return new int[] { -1, -1 }; // pair not found
//   }
//
//   public static void main(String[] args) {
//     int[] result = PairWithTargetSum.search(new int[] { 1, 2, 3, 4, 6 }, 6);
//     System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
//     result = PairWithTargetSum.search(new int[] { 2, 5, 9, 11 }, 11);
//     System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
//   }
// }
