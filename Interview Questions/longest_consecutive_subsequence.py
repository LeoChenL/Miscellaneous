'''
Problem Statement
Given list of integers that contain numbers in random order, write a program to find the longest possible sub sequence of consecutive numbers in the array. Return this subsequence in sorted order. The solution must take O(n) time

For e.g. given the list 5, 4, 7, 10, 1, 3, 55, 2, the output should be 1, 2, 3, 4, 5

Note- If two arrays are of equal length return the array whose index of smallest element comes first.
'''

def longest_consecutive_subsequence(input_list):
    # store elements in a dictionary
    ele_dict = dict()
    for idx, ele in enumerate(input_list):
        ele_dict[ele] = idx

    # init global longest sequence
    longest_seq_len = 0
    longest_seq_str_idx = 0

    # traverse elements in list
    for ele in input_list:
        # print("longest len", longest_seq_len)
        # print("longest seq str", input_list[longest_seq_str_idx])
        # visited element
        if ele_dict[ele] == -1:
            continue

        seq_len = 1
        seq_str_idx = ele_dict[ele]
        ele_dict[ele] = -1

        # get the longest subsequence related to the current element
        up = ele + 1
        while up in ele_dict:
            seq_len += 1
            ele_dict[up] = -1
            up += 1

        down = ele - 1
        while down in ele_dict:
            seq_str_idx = ele_dict[down]
            seq_len += 1
            ele_dict[down] = -1
            down -= 1

        # update the globe longest length
        if seq_len > longest_seq_len:
            longest_seq_len = seq_len
            longest_seq_str_idx = seq_str_idx

    rst_seq = []
    ele_str = input_list[longest_seq_str_idx]
    for e in range(ele_str, ele_str+longest_seq_len):
        rst_seq.append(e)
    # print(rst_seq)
    return rst_seq

# # solution
# def longest_consecutive_subsequence(input_list):
#     element_dict = dict()
#
#     for index, element in enumerate(input_list):
#         element_dict[element] = index
#
#     max_length = -1
#     # 給 len() 跟 給 max = -999 一樣, 初值而已, 後面會替換掉
#     starts_at = len(input_list)
#
#     for index, element in enumerate(input_list):
#         current_starts = index
#         #當前這個 value 看過了, 先標記成 -1
#         #標成看過,  有一樣的就不用重複看 ex: 3,2,1 這三個看過後標-1, 則
#         #當 current value 是 2的時候, 3, 1 自然不用看, 下面while 有擋
#         element_dict[element] = -1
#         #計算連續的數量
#         current_count = 1
#
#         # check upwards, 如果現在value 是數字3, 那看看他下一個人 4
#         current = element + 1
#
#         while current in element_dict and element_dict[current] > 0:
#
#             #連續數量 + 1
#             current_count += 1
#             #把剛才4 標程 -1
#             element_dict[current] = -1
#             #如果 4 有, 再往上走 5
#             current = current + 1
#
#         #=> 因此, 走到這裡時, 已經把 current index value 往上相鄰的都算了
#
#         # check downwards, 往下看, ex: value 3, 現在看 2
#         current = element - 1
#         while current in element_dict and element_dict[current] > 0:
#             #把index 給 current_starts, 不可能是-1 因為上面擋了
#             #記錄下這波從哪個index 開始往下
#             current_starts = element_dict[current]
#             current_count += 1
#             element_dict[current] = -1
#             current = current - 1
#
#         #紀錄最大值
#         if current_count >= max_length:
#             if current_count == max_length and current_starts > starts_at:
#                 continue
#             starts_at = current_starts
#             max_length = current_count
#
#     start_element = input_list[starts_at]
#     return [element for element in range(start_element, start_element + max_length)]

# Test
def test_function(test_case):
    output = longest_consecutive_subsequence(test_case[0])
    if output == test_case[1]:
        print("Pass")
    else:
        print("Fail")

test_case_1 = [[5, 4, 7, 10, 1, 3, 55, 2], [1, 2, 3, 4, 5]]
test_function(test_case_1)
test_case_2 = [[2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6 ], [8, 9, 10, 11, 12]]
test_function(test_case_2)
test_case_3 = [[0, 1, 2, 3, 4], [0, 1, 2, 3, 4]]
test_function(test_case_3)
