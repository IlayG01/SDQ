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

/* opt 1 - 100% rate*/
// Complete the minimumBribes function below.
void minimumBribes(int q_count, int* q)
{
    int bribes_counter = 0;
    /* first checking for too chaotic scenario, can saves us a lot of calculations */
    for (int i = 0; i < q_count; i++)
    {
        if ((i+1) < (q[i] - 2))
        {
            printf("Too chaotic\n");
            return;
        }
    }
    /* we know the case is valid, starting the calculations */
    for (int i = 0; i < q_count; i++)
    {
        /* a bribe occurred - by index | [1,2,5,3,4] - 5 number is in index 3 */
        if ((i+1) < q[i])
        {
            /* updating bribes */
            bribes_counter += (q[i] - (i+1));
        }
        /* checking if a bribe occurred - by order | [3,2,1,4] - 2 number is in index 2, but bribed 1 */
        else
        {
            /* choosing a batter travel option */
            if (i > q_count/2)
            {
                /* running till the end, checking if the q[i] bribed someone */
                for (int j = i; j < q_count; j++)
                {
                    if (q[j] < q[i])
                    {
                        bribes_counter++;
                        /* a bribe can be index fixed,
                         only if it was a single bribe that was taken over by double bribe */
                        break;
                    }
                }
            }
            else
            {
                int c = 0;
                /* running back to the start, checking if all the numbers that below the current is there */
                for (int j = i; j >= 0; j--)
                {
                    if (q[j] < q[i])
                    {
                        c++;
                    }
                }
                if (c < q[i] - 1)
                {
                    bribes_counter++;
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
