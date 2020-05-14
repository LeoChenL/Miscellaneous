'''
Problem statement
In an encryption system where ASCII lower case letters represent numbers in the pattern a=1, b=2, c=3... and so on, find out all the codes that are possible for a given input number.

Example 1

number = 123
codes_possible = ["aw", "abc", "lc"]
Explanation: The codes are for the following number:

1 . 23 = "aw"
1 . 2 . 3 = "abc"
12 . 3 = "lc"
Example 2

number = 145
codes_possible = ["ade", "ne"]
Return the codes in a list. The order of codes in the list is not important.

Note: you can assume that the input number will not contain any 0s
'''
def all_codes(number):
    """
    :param: number - input integer
    Return - list() of all codes possible for this number
    TODO: complete this method and return a list with all possible codes for the input number
    """
    # print(number)
    if number < 0:
        print("invalid input")
        return
    if number == 0:
        return ['']

    codes = []
    if number < 10:
        codes = [chr(number + 96)]
    else:
        res = number % 10
        res_number = number // 10
        for c in all_codes(res_number):
            c += chr(res + 96)
            codes.append(c)

        res = number % 100
        if res < 27:
            res_number = number // 100
            for c in all_codes(res_number):
                c += chr(res + 96)
                codes.append(c)
    # print("codes", codes)
    return codes



def test_function(test_case):
    number = test_case[0]
    solution = test_case[1]

    output = all_codes(number)

    output.sort()
    solution.sort()

    if output == solution:
        print("Pass")
    else:
        print("Fail")

number = 123
solution = ['abc', 'aw', 'lc']
test_case = [number, solution]
test_function(test_case)
number = 145
solution =  ['ade', 'ne']
test_case = [number, solution]
test_function(test_case)
number = 1145
solution =  ['aade', 'ane', 'kde']
test_case = [number, solution]
test_function(test_case)
number = 4545
solution = ['dede']
test_case = [number, solution]
test_function(test_case)
