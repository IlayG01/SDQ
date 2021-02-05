__author__ = "IlayG01"

"""
Question Description :
You are given an unordered array consisting of consecutive integers arr[1, 2, 3, ..., n]
 without any duplicates. You are allowed to swap any two elements.
  You need to find the minimum number of swaps required to sort the array in ascending order. 

Example:
i   arr                     swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

It took 5 swaps to sort the array.

Full Description & Credit -
https://www.hackerrank.com/challenges/minimum-swaps-2/
"""


def minimumSwaps(arr):
    ref_arr = sorted(arr)
    index_dict = {v: i for i, v in enumerate(arr)}
    swaps = 0

    for i, v in enumerate(arr):
        correct_value = ref_arr[i]
        if v != correct_value:
            to_swap_ix = index_dict[correct_value]
            arr[to_swap_ix], arr[i] = arr[i], arr[to_swap_ix]
            index_dict[v] = to_swap_ix
            index_dict[correct_value] = i
            swaps += 1

    return swaps


# option 2 - less effective
def minimumSwaps(arr):
    """
    given an unsorted array, return the min num of swaps in order to sort it
    """
    swaps = 0
    current_value_fixing = len(arr)
    sorted_arr = sorted(arr)
    while arr != sorted_arr:
        while arr[current_value_fixing - 1] == current_value_fixing:
            current_value_fixing -= 1
        # swap with current index
        current_index = arr.index(current_value_fixing)
        our_soulmate = arr.index(current_index + 1)
        arr[current_index], arr[our_soulmate] = arr[our_soulmate], arr[current_index]
        swaps += 1
    return swaps
