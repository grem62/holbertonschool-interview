#include <stdio.h>
#include <stdlib.h>

/**
 * menger - Prints a Menger sponge of a given level.
 *
 * @level: The level of the Menger sponge to print.
 */
void menger(int level)
{
	int i, j, size, x, y; /* Declare variables i, j, size, x, y */
	char c; /* Declare character variable c */

	if (level < 0) /* Check if level is less than 0 */
		return; /* Exit the function if level is less than 0 */

	size = 1 << level; /* Calculate the size of the Menger based on the level */
	for (i = 0; i < size; i++) /* Loop through rows */
	{
		for (j = 0; j < size; j++) /* Loop through columns */
		{
			x = i; /* Set x to the current row */
			y = j; /* Set y to the current column */
			c = '#'; /* Set c to '#' by default */

			while (x > 0 || y > 0) /* Loop until both x and y are 0 */
			{
				if (x % 3 == 1 && y % 3 == 1) /* Check if x and y are both 1 */
					c = ' '; /* Set c to ' ' if x and y satisfy the condition */

				x /= 3; /* Divide x by 3 */
				y /= 3; /* Divide y by 3 */
			}
			printf("%c", c); /* Print the character c */
		}
		printf("\n"); /* Print a new line */
	}
}


