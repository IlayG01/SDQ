__author__ = "Ilay Gilman"

"""
Question Description :
There is a string, S, of lowercase English letters that is repeated infinitely many times.
 Given an integer, N, find and print the number of letter a's in the first letters of the infinite string.

Example:
s = 'abcac' n = 10
 The substring we consider is abcacabcac, 
  the first characters of the infinite string.
   There are 4 occurrences of 'a' in the substring. 

Full Description & Credit -
https://www.hackerrank.com/challenges/repeated-string/
"""


def repeated_string(s, n):
    """
    :param s: string to repeat
    :param n: number of characters to consider
    :return: the frequency of a in the substring
    """
    ## bad solution ##
    # index = 0
    # a_counter = 0
    # while index < n:
    #     if s[index % len(s)] == 'a':
    #         a_counter += 1
    #     index += 1
    #     print(a_counter)
    # return a_counter
    ## lets use math ##
    a_counter = 0
    if n < len(s):  # in case the string bigger than the number
        for index in range(n):
            if s[index] == 'a':
                a_counter += 1
        return a_counter
    else:
        for letter in s:  # calc in a full string
            if letter == 'a':
                a_counter += 1
        a_counter = a_counter * (n / len(s))  # how many full string we have in the infinite string
        for i in range(n % len(s)):  # calc in the reminder string
            if s[i] == 'a':
                a_counter += 1
        return a_counter

# tests
# print(repeated_string('a', 1000000000000)) == 1000000000000
# print(repeated_string('aba', 10)) == 7
