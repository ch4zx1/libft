/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:30:05 by cfischer          #+#    #+#             */
/*   Updated: 2021/09/19 19:23:29 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(char *str, size_t size, unsigned int num,
unsigned int isnegative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num /= 10;
	}
	if (isnegative)
	{
		str[0] = '-';
	}
	return (str);
}

size_t	ft_count(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
	{
		len++;
	}
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			count;
	unsigned int	isnegative;
	char			*str;

	count = ft_count(n);
	isnegative = 0;
	if (n < 0)
	{
		isnegative = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	return (convert(str, count, (unsigned int)n, isnegative));
}
