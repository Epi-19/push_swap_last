/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:40:49 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:40:50 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_ac_2(char **av)
{
	t_list	*a;
	t_list	*new;
	int		i;
	long	num;
	char	**strs;

	a = NULL;
	i = 0;
	strs = ft_split(av[1], 32);
	if (!strs)
		return (NULL);
	while (strs[i])
	{
		num = ft_atoi_sec(strs[i]);
		if (num == LONG_MIN)
			return (ft_free_split(strs), NULL);
		if (ft_is_duplicate(a, num))
			ft_error("duplicate input");
		new = ft_lstnew(num);
		ft_lstadd_back(&a, new);
		i++;
	}
	ft_free_split(strs);
	return (a);
}

t_list	*ft_pars(int ac, char **av)
{
	t_list	*a;
	t_list	*new;
	int		i;
	long	num;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error("invalid input");
	if (ac == 2)
		a = ft_ac_2(av);
	else
	{
		while (i < ac)
		{
			num = ft_atoi_sec(av[i++]);
			if (num == LONG_MIN)
				return (NULL);
			if (ft_is_duplicate(a, num))
				ft_error("duplicate input");
			new = ft_lstnew(num);
			ft_lstadd_back(&a, new);
		}
	}
	return (a);
}
