/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:37:47 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:37:48 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

/*
ft_putendl_fd takes a string s and a file descriptor 
as parameters. It uses a while loop to iterate over
each char of the string s. Inside the loop, it
writes each char to the given file descriptor fd using
the write function. After the loop, it writes a 
newline char ('\n') to the file descriptor to add
a newline at the end of the string.
*/