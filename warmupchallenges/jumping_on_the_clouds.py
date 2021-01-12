__author__ = "Ilay Gilman"

"""
Question Description :
There is a new mobile game that starts with consecutively numbered clouds.
 Some of the clouds are thunderheads and others are cumulus.
  The player can jump on any cumulus cloud having a number that is equal
   to the number of the current cloud plus 1 or 2. The player must avoid the thunderheads.
     Determine the minimum number of jumps it will take to jump
      from the starting position to the last cloud.
       It is always possible to win the game.

For each game, you will get an array of clouds numbered
 if they are safe or if they must be avoided.
 
Example:
c = [0, 1, 0, 0, 0, 1, 0]
 The number on each cloud is its index in the list so the player must avoid the clouds at indices 1 and 5.
  The player can follow 0>2>3>4>6 or 0>2>4>6. so the minimum jumps to win is 3.  

Full Description & Credit -
https://www.hackerrank.com/challenges/jumping-on-the-clouds/
"""


def jumping_on_clouds(c):
    """
    :param c: an array of binary integers
    :return: minimum jumps to win the game
    """
    jumps = 0
    clean_cloud = 0
    # checks available starting cloud (0 or 1 index in the c array)
    if c[0] == clean_cloud:
        # the first cloud is clean
        starting_cloud = 0
    else:
        # the second cloud should be clean
        starting_cloud = 1
    while starting_cloud < len(c) - 1:
        # checks which jump we can take
        if starting_cloud < len(c) - 2 and c[starting_cloud + 2] == clean_cloud:
            starting_cloud += 2
            jumps += 1
        else:
            starting_cloud += 1
            jumps += 1
    return jumps


# tests
# print(jumping_on_clouds([0, 0, 0, 1, 0, 0])) == 3
# print(jumping_on_clouds([0, 0, 1, 0, 0, 1, 0])) == 4

