#include "slide_line.h"

/**
 * slide_left - slides and merges array elements to the left
 * @line: array to slide
 * @size: size of the array
 *
 * Return: 1 on success
 */
static int slide_left(int *line, size_t size)
{
	size_t i, write_pos = 0;
	int merged = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (write_pos > 0 && line[write_pos - 1] == line[i] && !merged)
			{
				line[write_pos - 1] *= 2;
				merged = 1;
			}
			else
			{
				line[write_pos] = line[i];
				write_pos++;
				merged = 0;
			}
		}
	}

	while (write_pos < size)
	{
		line[write_pos] = 0;
		write_pos++;
	}

	return (1);
}

/**
 * slide_right - slides and merges array elements to the right
 * @line: array to slide
 * @size: size of the array
 *
 * Return: 1 on success
 */
static int slide_right(int *line, size_t size)
{
	size_t i, write_pos;
	int merged = 0;

	if (size == 0)
		return (1);

	write_pos = size - 1;

	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			if (write_pos < size - 1 && line[write_pos + 1] == line[i - 1] && !merged)
			{
				line[write_pos + 1] *= 2;
				merged = 1;
			}
			else
			{
				line[write_pos] = line[i - 1];
				if (write_pos > 0)
					write_pos--;
				merged = 0;
			}
		}
	}

	while (write_pos < size)
	{
		line[write_pos] = 0;
		if (write_pos == 0)
			break;
		write_pos--;
	}

	return (1);
}

/**
 * slide_line - slides and merges an array of integers
 * @line: array to slide and merge
 * @size: size of the array
 * @direction: direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	else
		return (0);
}
