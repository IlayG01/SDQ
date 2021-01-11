"""
Question Description:
create a function that receives (number of steps, path) of a hike.
 each step is an uphill(U) or downhill(D), and the function need to record
  how many valleys traversed during the hike.
Example:
There are steps = 8, path = [DDUUUUDD].
 The hiker first enters a valley 2 units deep.
  Then they climb out and up onto a mountain 2 units high.
   Finally, the hiker returns to sea level and ends the hike.
   The number of alleys traversed during the hike is 1.
                                                            /\
                                                      _    /  \_
                                                       \  /
                                                        \/
Full Description & Credit -
https://www.hackerrank.com/challenges/counting-valleys/
"""


def counting_valleys(num_steps, path):
    """
    :param num_steps: number of steps
    :param path: the taken path of the hiker
    :return: number of alleys traversed during the hike
    """
    current_level = 0
    is_above_equal_sea_level = True  # hikes always starts at sea level
    number_of_alleys = 0
    for step in path:
        # updating sea level
        if step == 'D':
            current_level -= 1
        if step == 'U':
            current_level += 1
        # if we cross sea level downhill
        if current_level >= 0:
            is_above_equal_sea_level = True
            continue
        else:
            if is_above_equal_sea_level:
                is_above_equal_sea_level = False
                number_of_alleys += 1
    return number_of_alleys

# tests
# (8, UDDDUDUU) == 1
# (12, DDUUDDUDUUUD) == 2
