#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: Pointer to the binary string (composed of '0' and '1' characters).
 *
 * Return: The converted unsigned integer, or 0 if an invalid character
 *         or NULL string is encountered.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = (result << 1) + (*b - '0');
		b++;
	}
	return (result);
}
