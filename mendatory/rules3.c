/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:17:24 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:23 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **b, t_list **a)
{
	t_list	*temp;

	temp = (*a);
	if (!*a)
		return ;
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
	write(1, "pb\n", 3);
}

void	ft_ra(t_list **a)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	write(1, "ra\n", 3);
}

void	ft_write(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	getindex(t_list *stack_a, int a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (a == stack_a->data)
			return (i);
		else
			i++;
		stack_a = stack_a->next;
	}
	return (0);
}

int	*full_tab(t_list *st_a)
{
	int	*tab;
	int	i;
	int	count;

	i = 0;
	count = size_list(st_a);
	tab = malloc(count * 4);
	while (i < count)
	{
		tab[i] = (st_a)->data;
		st_a = (st_a)->next;
		i++;
	}
	return (tab);
}
