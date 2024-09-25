#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct	s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}				t_stock_str;

#endif

--------------------------------------------------------



  #include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	char	*buffer;

	buffer = (char*)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!buffer)
		return (0);
	dest = buffer;
	while (*src)
		*buffer++ = *src++;
	*buffer = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	t_stock_str *buffer;
	int			index;

	stock = (t_stock_str*)malloc(sizeof(*stock) * (ac + 1));
	if (!stock)
		return (NULL);
	buffer = stock;
	index = 0;
	while (index < ac)
	{
		buffer->size = ft_strlen(*av);
		buffer->str = *av;
		buffer->copy = ft_strdup(*av);
		av++;
		buffer++;
		index++;
	}
	buffer->str = 0;
	return (stock);
}

----------------------------------------------------------------------------------------
#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
	
int	main(int argc, char *argv[])
{
	t_stock_str	*stock;
	
	if (argc > 1)
	{
		stock = ft_strs_to_tab(argc - 1, ++argv);
		while (stock->str)
		{
			printf("str: %s\n", stock->str);
			printf("copy: %s\n", stock->copy);
			printf("size: %d\n", stock->size);
			stock++;
			printf("\n");
		}
	}
	printf("\n");
	return (0);
}
