/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:11:49 by ivork         #+#    #+#                 */
/*   Updated: 2020/11/23 13:27:30 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*temp;

	temp = str;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (const char)c)
			return ((char*)&temp[i]);
		i++;
	}
	return (0);
}
