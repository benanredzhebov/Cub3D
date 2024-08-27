/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:54:42 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/23 12:56:54 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split_string(char **arr, int j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
}

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = -1;
	arr = (char **)ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!arr || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i)
		{
			arr[++j] = ft_substr(s, start, i - start);
			if (arr[j] == NULL)
				return (free_split_string(arr, j), NULL);
		}
	}
	return (arr);
}

// void	print_str_array(char **arr)
// {
// while (*arr != NULL)
// {
// 	printf("%s\n", *arr);
// 	arr++;
// }
// }

// // Function to free the memory allocated for the array of strings
// void	free_str_array(char **arr)
// {
// char	**temp = arr;
// while (*temp != NULL)
// {
// 	free(*temp);
// 	temp++;
// }
// free(arr);
// }

// int	main()
// {
// // Test count_words function
// char	*test_string = "This is a test string";
// char	delimiter = ' ';
// int	word_count = count_words(test_string, delimiter);

// printf("Word count: %d\n", word_count);

// // Test ft_split function
// char	**result = ft_split(test_string, delimiter);

// // Print the result
// if (result != NULL)
// {
// 	printf("Original string: %s\n", test_string);
// 	printf("Split string:\n");
// 	print_str_array(result);

// 	// Free the allocated memory
// 	free_str_array(result);
// }
// else
// {
// 	printf("Error: ft_split returned NULL.\n");
// }

// return 0;
// }
