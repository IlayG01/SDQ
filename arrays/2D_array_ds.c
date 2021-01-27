/* Author: IlayG01 */
/********************************************************************************************************************************\
 * Question Description :
 * Given a 6X6 2D Array, arr.
   An hourglass in A is a subset of values with indices falling in this pattern in arr's graphical representation
   a b c
     d
   e f g
   There are 16 hourglasses in arr. An hourglass sum is the sum of an hourglass' values.
   Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum.
   The array will always be 6X6.

 * Example:
 *  -9 -9 -9  1 1 1
     0 -9  0  4 3 2
    -9 -9 -9  1 2 3
     0  0  8  6 6 0
     0  0  0 -2 0 0
     0  0  1  2 4 0
 * the 16 hourglasses sums are -
    -63, -34, -9, 12,
    -10,   0, 28, 23,
    -27, -11, -2, 10,
      9,  17, 25, 18
 * The highest hourglass sum is 28 from the hourglass beginning at row 1, column 2:
    0 4 3
      1
    8 6 6

 * Full Description & Credit -
 * https://www.hackerrank.com/challenges/2d-array/
\*******************************************************************************************************************************/


/* Complete the hourglassSum function below. */
int hourglassSum(int arr_rows, int arr_columns, int** arr)
{
    int biggest_hourglass = -9 * 7;
    int max_index_to_travel = arr_columns - 2;
    /* running through 0,1,2,3 rows */
    for (int row = 0; row < max_index_to_travel; row++)
    {
        /* running through 0,1,2,3 cols */
        for (int col = 0; col < max_index_to_travel; col++)
        {
            /* each index we travel ia the top-left corner of a hour glass
               so we need to sum the rest of the hour glass */
            int current_sum = hourglassSumHelper(arr, row, col);
            if (biggest_hourglass < current_sum)
            {
                biggest_hourglass = current_sum;
            }
        }
    }
    return biggest_hourglass;
}

int hourglassSumHelper(int** arr, int current_row, int current_col)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i % 2 == 0)
        {
            sum += arr[current_row + i][current_col] + arr[current_row + i][current_col + 1] + arr[current_row + i][current_col + 2];
        }
        else
        {
            sum += arr[current_row + i][current_col + 1];
        }
    }
    return sum;
}