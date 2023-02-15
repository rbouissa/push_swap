/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:16:28 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:18 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **st_a, int size)
{
	int	a;
	int	b;

	if (size == 2)
	{
		a = (*st_a)->data;
		b = (*st_a)->next->data;
	}
	if (a > b)
		ft_sa(*st_a);
}

void	sort_3(t_list **st_a)
{
	int	a;
	int	b;
	int	c;

	a = (*st_a)->data;
	b = (*st_a)->next->data;
	c = (*st_a)->next->next->data;
	if (a < b && a < c && b > c)
	{
		ft_rra(st_a);
		ft_sa(*st_a);
	}
	else if (a > b && b < c && a < c)
		ft_sa(*st_a);
	else if (a > b && b > c && a > c)
	{
		ft_sa(*st_a);
		ft_rra(st_a);
	}
	else if (a < b && b > c && c < a)
		ft_rra(st_a);
	else if (a > b && b < c && c < a)
		ft_ra(st_a);
}

int	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	rotate_tab(int count, t_list **stack_a, int *tab, t_list **stack_b)
{
	int	i;

	while (count > 3)
	{
		i = getindex(*stack_a, *tab);
		while ((*stack_a)->data != *tab)
		{
			if (i <= count / 2)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		ft_pb(stack_b, stack_a);
		count--;
		tab++;
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	i;
	int	count;

	tab = full_tab(*stack_a);
	count = size_list(*stack_a);
	if (sort_tab(tab, count) == 0)
		exit(1);
	if (count <= 2)
		sort_2(stack_a, count);
	else
	{
		rotate_tab(count, stack_a, tab, stack_b);
		sort_3(stack_a);
		while (*stack_b)
			ft_pa(stack_b, stack_a);
	}
}
