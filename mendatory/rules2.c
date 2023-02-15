/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:17:18 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:24 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	if (!*b || !*a)
		return ;
	ft_ra(a);
	ft_rb(b);
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **a)
{
	t_list	*temp1;
	t_list	*temp;

	temp1 = *a;
	temp = (ft_last(*a));
	if (!*a)
		return ;
	while (temp1->next->next)
	{
		temp1 = temp1->next;
	}
	temp1->next = NULL;
	ft_lstadd_front(a, temp);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b)
{
	t_list	*temp1;
	t_list	*temp;

	temp1 = *b;
	temp = (ft_last(*b));
	if (!*b)
		return ;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_front(b, temp);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	if (!*a || !*b)
		return ;
	ft_rrb(b);
	ft_rra(a);
	write(1, "rrr\n", 4);
}
