'''
Problem Statement
Given an integer array, find and return all the subsets of the array. The order of subsets in the output array is not important. However the order of elements in a particular subset should remain the same as in the input array.

Note: An empty set will be represented by an empty list

Example 1

arr = [9]

output = [[]
          [9]]
Example 2

arr = [9, 12, 15]

output =  [[],
           [15],
           [12],
           [12, 15],
           [9],
           [9, 15],
           [9, 12],
           [9, 12, 15]]
'''


import copy
def subsets(arr):
    """
    :param: arr - input integer array
    Return - list of lists (two dimensional array) where each list represents a subset
    TODO: complete this method to return subsets of an array
    """
    # print("arr", arr)
    sets = [[]]
    if len(arr) == 0:
        pass
    elif len(arr) == 1:
        sets.append(arr)
    else:
        sets = []
        element = arr.pop(0)
        sub_arr = copy.deepcopy(arr)
        sub_sets = subsets(sub_arr)
        for s in sub_sets:
            s.insert(0, element)
            # print("s", s)
            sets.append(s[1:])
            sets.append(s)
            # print("set append", sets)
    # print("sets", sets)
    return sets

# # Solution
# def subsets(arr):
#     return return_subsets(arr, 0)
#
# def return_subsets(arr, index):
#     if index >= len(arr):
#         return [[]]
#
#     small_output = return_subsets(arr, index + 1)
#
#     output = list()
#     # append existing subsets
#     for element in small_output:
#         output.append(element)
#
#     # add current elements to existing subsets and add them to the output
#     for element in small_output:
#         current = list()
#         current.append(arr[index])
#         current.extend(element)
#         output.append(current)
#     return output


def test_function(test_case):
    arr = test_case[0]
    solution = test_case[1]

    output = subsets(arr)

    output.sort()
    solution.sort()

    if output == solution:
        print("Pass")
    else:
        print("Fail")


arr = [9]
solution = [[], [9]]
test_case = [arr, solution]
test_function(test_case)
arr = [5, 7]
solution = [[], [7], [5], [5, 7]]
test_case = [arr, solution]
test_function(test_case)
arr = [9, 12, 15]
solution = [[], [15], [12], [12, 15], [9], [9, 15], [9, 12], [9, 12, 15]]
test_case = [arr, solution]
test_function(test_case)
