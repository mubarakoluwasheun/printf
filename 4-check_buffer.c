#include "main.h"

# define BUFFER_SIZE 1024

/**
 * buffer_add_char - Function to add a character
 * to the buffer
 * @buffer: Pointer to the buffer structure
 * @c: The character to add
 */
void buffer_add_char(buffer_t *buffer, char c)
{
	buffer->data[buffer->index++] = c;

	if (buffer->index >= BUFFER_SIZE)
	{
		write(1, buffer->data, BUFFER_SIZE);
		buffer->index = 0;
	}
}

/**
 * buffer_flush - Function to flush any remaining
 * character in the buffer
 * @buffer: Pointer to the buffer structure
 */
void buffer_flush(buffer_t *buffer)
{
	if(buffer->index > 0)
		write(1, buffer->data, buffer->index);
}
