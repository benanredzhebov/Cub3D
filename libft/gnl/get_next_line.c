/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:33:27 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:33:28 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rd_str(int fd, char *input_str)
{
	char	*buffer;
	char	*temp;
	int		rd_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(input_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(buffer), free(input_str), NULL);
		buffer[rd_bytes] = '\0';
		temp = ft_strjoin(input_str, buffer);
		free(input_str);
		input_str = temp;
	}
	return (free(buffer), input_str);
}

char	*ft_extract_line(char *input_str, int i)
{
	char	*str;

	if (!input_str[i])
		return (NULL);
	while (input_str[i] && input_str[i] != '\n')
		i++;
	if (input_str[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (input_str[i] && input_str[i] != '\n')
	{
		str[i] = input_str[i];
		i++;
	}
	if (input_str[i] == '\n')
	{
		str[i] = input_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *input_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (input_str[i] && input_str[i] != '\n')
		i++;
	if (!input_str[i])
		return (free(input_str), NULL);
	str = malloc((ft_strlen(input_str) - i + 1) * sizeof(char));
	if (!str)
		return (free(input_str), NULL);
	i++;
	j = 0;
	while (input_str[i])
		str[j++] = input_str[i++];
	str[j] = '\0';
	return (free(input_str), str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*input_str;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!input_str)
		input_str = ft_strdup("");
	input_str = ft_rd_str(fd, input_str);
	if (!input_str)
		return (NULL);
	line = ft_extract_line(input_str, i);
	input_str = ft_new_str(input_str);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/