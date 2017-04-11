#include "list.h"

/**
 * @file list.c contains implementation of functions for managing the word lists
 * used by the program.
 **/

#ifdef WITH_LEVENSHTEIN
/**
 * @param first the first string to compare
 * @param first_len the number of characters in the first string to compare
 * @param second the second string to compare
 * @param second_len the number of characters in the second string to compare
 * @return the minimum number of edits required to turn the first string into
 * the second string 
 **/
int levenshtein(const char * first, int first_len, 
                const char * second, int second_len)
{
        int shorten_both, shorten_first, shorten_second;

        /* if either string is shorter than the threshold, difference is 
           inserting all chars from the other
         */
        if (first_len < THRESHOLD) return second_len;
        if (second_len < THRESHOLD) return first_len;
        printf("%s:%s\n", first, second);
        /* if the difference in the length of the strings is greater than the 
         * threshold, they are not similar
         */
        if(abs(strlen(first) - strlen(second)) > THRESHOLD)
        {
                return INT_MAX;
        }

        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (first[first_len] == second[first_len])
                return levenshtein(first, first_len - 1, second, 
                                   second_len - 1);

        /* else try:
         *      changing last letter of first to that of second; or
         *      remove last letter of first; or
         *      remove last letter of second,
         * any of which is 1 edit plus editing the rest of the strings
         */
        shorten_both = levenshtein(first, first_len - 1, second, 
                                   second_len - 1);
        shorten_first = levenshtein(first, first_len,     second, 
                                    second_len - 1);
        shorten_second = levenshtein(first, first_len - 1, second, 
                                     second_len    );
        return (shorten_both <= shorten_first) ? 
                ((shorten_both <=  shorten_second) ? 
                 shorten_both + 1 : shorten_second + 1)
                : shorten_first + 1;
}
#endif/* WITH_LEVENSHTEIN */
