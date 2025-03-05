/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:40:19 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:40:36 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "ERROR/n", 6);
	exit(1);
}

int	ft_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || (str[i] < '0' || str[i] > '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (!str[i]);
}

long int	ft_atoi_sec(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (!ft_is_valid_number(str))
		return (LONG_MIN);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ft_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > INT_MAX)
			return (LONG_MIN);
		if ((num * sign) < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	return ((int)(num * sign));
}

int	ft_is_duplicate(t_list *list, int num)
{
	while (list)
	{
		if (list->content == num)
			return (1);
		list = list->next;
	}
	return (0);
}
