/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:26:58 by cfischer          #+#    #+#             */
/*   Updated: 2021/09/14 11:36:03 by cfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*s_start;
	char	*sub;
	char	*sub_iter;

	if (!s)
	{
		return (NULL);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
	{
		return (NULL);
	}
	s_start = (char *)s;
	s_len = ft_strlen(s);
	sub_iter = sub;
	s += start;
	while (((size_t)(s - s_start) < s_len) && len--)
	{
		*sub_iter++ = *s++;
	}
	*sub_iter = '\0';
	return (sub);
}
