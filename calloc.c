/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:30:47 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:31:25 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t all, size_t size)
{
	void	*ptr;
	size_t	i;

	i = all * size;
	ptr = malloc(all * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}
