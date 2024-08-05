/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:21:08 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/05 12:21:11 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* A FUNCTION TO READ FROM THE FILE DESCRIPTOR

1. using 'read' function (<unistd.h>) - it loads the contents of a file into 
memory using its fd:
- fd
- pointer to a temp. storage
- size in bytes to read
loops until 0 (nothing to read) or \n is included.
2. returns -1 if there is an error, frees allocated memory, exits.
3. save chars into 'hold' variable.

If we try an extremely large BUFFER_SIZE, like 2147483647, 
we might notice a fatal error : stack overflow =>
MALLOC THE BUFFER! */

/* not just  ft_strjoin(hold, buffer); */
char	*reader(int fd, char *hold)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && (!gnl_newline_found(hold)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		hold = gnl_strjoin(hold, buffer);
	}
	free(buffer);
	return (hold);
}

/* A FUNCTION TO GET THE LINE TO RETURN

If this function is called, we know there is a \n or there is nothing 
left to read. We will extract the characters up to the \n to 
get the line we must later return:

- count the number of characters to and including the \n if there is one
- malloc a string of the counted size, + 1 for the final \0
- copy the characters until the \n or the \0 and add the final \0
- return the malloc’d string */
char	*cleaner(char *hold)
{
	char	*line;
	int		i;

	i = 0;
	if (!hold[i])
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		line[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
	{
		line[i] = hold[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* A FUNCTION TO SAVE EXTRA READ CHARS 
if \n is present (otherwise free/return):
We must now “reset” the static variable by taking all the 
characters after the \n:

- measure the size of the string in the static variable, 
minus the number of characters until the \n (included!), 
+ 1 for the final \0,
- malloc a string of that size,
- copy the characters and add the final \0,
- return the new malloc’d string. */
char	*garbage_collector(char *hold)
{
	char	*garbage;
	int		i;
	int		j;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (!hold[i])
	{
		free (hold);
		return (NULL);
	}
	garbage = malloc((gnl_strlen(hold) - i + 1) * sizeof(char));
	if (!garbage)
		return (NULL);
	i++;
	j = 0;
	while (hold[i])
		garbage[j++] = hold[i++];
	garbage[j] = '\0';
	free(hold);
	return (garbage);
}

/* including check for invalid fd */
char	*get_next_line(int fd)
{
	static char	*hold;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold = reader(fd, hold);
	if (!hold)
		return (NULL);
	line = cleaner(hold);
	hold = garbage_collector(hold);
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

// Casting argc to quiet the compiler's warnings.
	(void)argc;
// Open the file given as an argument at program launch
	fd = open(argv[1], O_RDONLY);
// Initialize this variable to be able to use it in the following loop
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
*/