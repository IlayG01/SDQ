/* Author: IlayG01 */
/**********************************************************************************************************************\
 * Question Description :
 * It is New Year's Day and people are in line for the Wonderland roller coaster ride.
   Each person wears a sticker indicating their initial position in the queue from 1 to n.
   Any person can bribe the person directly in front of them to swap positions,
   but they still wear their original sticker. One person can bribe at most two others.
   Determine the minimum number of bribes that took place to get to a given queue order.
   Print the number of bribes, or, if anyone has bribed more than two people, print 'Too chaotic'.

 * Example:
 * q = [1, 2, 3, 5, 4, 6, 7, 8]
   If person bribes person , the queue will look like above - Only bribe 1 is required. Print '1'.
 * q = [4, 1, 2, 3]
   Person 4 had to bribe 3 people to get to the current position. Print 'Too chaotic'.

 * Full Description & Credit -
 * https://www.hackerrank.com/challenges/new-year-chaos/
\**********************************************************************************************************************/

/* opt 1 */
void minimumBribes(int q_count, int* q)
{
    int bribes_counter = 0;
    for (int i = 0; i < q_count; i++)
    {
        /* a bribe occurred - by index */
        if ((i+1) < q[i])
        {
            /* more than 2 bribes - too chaotic */
            if ((i+1) < (q[i] - 2))
            {
                printf("Too chaotic\n");
                return;
            }
            /* updating bribes */
            else
            {
                bribes_counter += (q[i] - (i+1));
            }
        }
        /* checking if a bribe occurred - by order */
        else
        {
            /* running till the end, checking if the q[i] bribed someone */
            for (int j = i; j < q_count; j++)
            {
                if (q[j] < q[i])
                {
                    bribes_counter++;
                    break; /* a bribe can be index fixed, only if it was a single bribe that was taken over by double bribe */
                }
            }
        }
        if (i == (q_count-1))
        {
            printf("%d\n", bribes_counter);
        }
    }
    return;
}

/* opt 2 - less effective */
void minimumBribes(int q_count, int* q)
{
    int bribes_counter = 0;
    for (int i = 0; i < q_count; i++)
    {
        if (q[i] - 2 > i + 1)
        {
            printf("Too chaotic\n");
            return;
        }
        for (int j = 0; j < i; j++)
        {
            if (q[j] > q[i])
            {
                bribes_counter++;
            }
        }
    }
    printf("%d\n", bribes_counter);
    return;
}
