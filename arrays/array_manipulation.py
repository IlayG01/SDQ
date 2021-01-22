__author__ = "Ilay Gilman"

"""
Question Description :
Starting with a 1-indexed array of zeros and a list of operations,
 for each operation add a value to each the array element between two given indices, inclusive.
  Once all operations have been performed, return the maximum value in the array. 

Example:
n = 10, queries = [[1,5,3],[4,8,7],[6,9,1]]
Queries are interpreted as follows: 
a  b  k
1  5  3
4  8  7
6  9  1

Add the values of K between the indices A and B.

Full Description & Credit -
https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges
"""


def array_manipulation(n, queries):
    """
    :param n: umber of elements in the array
    :param queries: two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
    :return: the maximum value in the resultant array
    """
    a, b, k = 0, 1, 2
    initialized_arr = [0] * (n + 1)
    # placing in the first index +k, in the last+1 value -k
    for query in queries:
        if query[k] == 0:
            continue
        initialized_arr[query[a] - 1] += query[k]
        initialized_arr[query[b]] -= query[k]
    # iterating array in order to find the max number
    max_value = 0
    current_value = 0
    for value in initialized_arr:
        if value == 0:
            continue
        current_value += value
        if max_value <= current_value:
            max_value = current_value
    return max_value

# test
# print(array_manipulation(5, [[1,2,100],[2,5,100],[3,4,100]]))

# NOTICE - NOT EFFICIENT SOLUTION
# a, b, k = 0, 1, 2
# initialized_arr = [0] * n[1]
# for query in queries[1:]:
#     if query[k] == 0:
#         continue
#     for index in range(query[a]-1, query[b]):
#         initialized_arr[index] += query[k]
# return max(initialized_arr)
