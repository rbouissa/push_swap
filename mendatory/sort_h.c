/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:16:41 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:21 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_up(t_list **stack_a, int data, int mid)
{
	int	n;

	n = getindex(*stack_a, data);
	while ((*stack_a)->data != data)
	{
		if (n <= mid)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	to_up_b(t_list **stack_b, t_list **stack_a, int *tab, int *count)
{
	int	n;
	int	mid;
	int	data;
	int	is_next;

	data = tab[*count];
	n = getindex(*stack_b, data);
	mid = *count / 2 - 1;
	is_next = 0;
	while (*stack_b && (*stack_b)->data != data)
	{
		if ((*stack_b)->data == tab[(*count) - 1] && !is_next)
		{
			ft_pa(stack_b, stack_a);
			is_next = 1;
			(*count)--;
		}
		else if (n <= mid)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
	ft_pa(stack_b, stack_a);
	if (is_next)
		ft_sa(*stack_a);
}

void	tmp_null(t_list **stack_a, t_sort *p, int range, t_list **temp)
{
	*temp = *stack_a;
	p->start -= range;
	p->end += range;
	if (p->start < 0 || p->end >= p->count)
	{
		p->start = 0;
		p->end = p->count - 1;
	}
}

void	fuul_b_h(t_list **stack_a, t_list **stack_b, int range)
{
	t_sort	p;
	t_list	*temp;
	int		*tab;

	tab = full_tab(*stack_a);
	p.count = size_list(*stack_a);
	p.mid = p.count / 2 - 1;
	p.end = p.mid + range;
	p.start = p.mid - range;
	temp = NULL;
	sort_tab(tab, p.count);
	while (*stack_a)
	{
		if (!temp)
			tmp_null(stack_a, &p, range, &temp);
		if (temp->data >= tab[p.start] && temp->data <= tab[p.end])
		{
			(to_up(stack_a, temp->data, p.mid), ft_pb(stack_b, stack_a));
			if (temp->data <= tab[p.mid])
				ft_rb(stack_b);
			temp = *stack_a;
		}
		else
			temp = temp->next;
	}
}

void	fuul_a_h(t_list **stack_a, t_list **stack_b)
{
	int		*tab;
	int		count;
	int		i;
	int		k;
	t_list	*tmp;

	i = 0;
	tab = full_tab(*stack_b);
	count = size_list(*stack_b);
	k = size_list(*stack_b) - 1;
	sort_tab(tab, count);
	tmp = *stack_b;
	while (*stack_b)
	{
		count--;
		to_up_b(stack_b, stack_a, tab, &count);
	}
}
