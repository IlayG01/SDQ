__author__ = "Ilay Gilman"

"""
Question Description:
Alex works at a clothing store.
 There is a large pile of socks that must be paired by color for sale.
  Given an array of integers representing the color of each sock,
   determine how many pairs of socks with matching colors there are.
Example:
There are n = 7 socks with color arr = [1,2,1,2,1,3,2].
 There is one pair of color 1 and one of color 2.
  There are three odd socks left, one of each color.
   The number of pairs is 2.
Full Description & Credit -
https://www.hackerrank.com/challenges/sock-merchant/
"""


def sock_merch(n, arr):
    """
    calculating how many pairs of socks with matching colors there are in received pile.
    :param n: number of sock in the pile
    :param arr: the colors of each sock in the pile
    :return: int representing the number of matching pairs
    """
    # edge case
    if n < 1:
        return 0
    match_holder = {}  # creating key for each color we have
    match_counter = 0
    for sock in range(n):
        current_sock = arr[sock]
        if current_sock in match_holder.keys():
            match_holder[current_sock] = match_holder[current_sock] + 1
            if match_holder[current_sock] % 2 == 0:
                match_holder[current_sock] = 0
                match_counter += 1
        else:
            match_holder[current_sock] = 1
    return match_counter

# tests
# print(sock_merch(7, [1, 2, 1, 2, 1, 3, 2]))
# print(sock_merch(10, [1, 1, 3, 1, 2, 1, 3, 3, 3, 3]))
# print(sock_merch(9, [10, 20, 20, 10, 10, 30, 50, 10, 20]))
