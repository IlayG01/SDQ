/* Author: IlayG01 */
/********************************************************************************************************************************\
 * Question Description :
 * A left rotation operation on an array shifts each of the array's elements 1 unit to the left.
   Given an array a of n integers and a number, d, perform d left rotations.
   Return the updated array to be printed as a single line of space-separated integers.

 * Example:
 * [1, 2, 3, 4, 5] after 2 left rotation will look like [3, 4, 5, 1, 2]
   Note that the lowest index item moves to the highest index in a rotation. This is called a circular array. 

 * Full Description & Credit -
 * https://www.hackerrank.com/challenges/ctci-array-left-rotation/
\*******************************************************************************************************************************/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char **split_string(char *);

int *rotLeft(int a_count, int *a, int d, int *result_count)
{
    int ret_arr[a_count];
    int reminder = d % a_count;
    for (int i = 0; i < a_count; i++)
    {
        /* creating the rotated array */
        reminder %= a_count;
        ret_arr[i] = *(a + reminder);
        reminder++;
    }
    for (int i = 0; i < a_count; i++)
    {
        /* copying rotated array to a */
        a[i] = ret_arr[i];
    }
    *result_count = a_count; /* we asked to do it for hackerrank tests */
    return a;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char **nd = split_string(readline());

    char *n_endptr;
    char *n_str = nd[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char *d_endptr;
    char *d_str = nd[1];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char **a_temp = split_string(readline());

    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        char *a_item_endptr;
        char *a_item_str = *(a_temp + i);
        int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        }

        *(a + i) = a_item;
    }

    int a_count = n;

    int result_count;
    int *result = rotLeft(a_count, a, d, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line)
        {
            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    }
    else
    {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
