/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:37:38 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:37:40 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
the fd parameter is to allow writing the char c
to different dests based on the provided file descriptor.
fd can be set to 1 to write the char to the standard output
or it can be set to a file descriptor obtained by opening a
specific file to write the character to that file.
you can control where the output is directed, enabling 
the function to write chars to various files or input or output
resources as needed.
*/