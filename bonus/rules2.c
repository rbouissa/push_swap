/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:17:18 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:36:54 by rbouissa         ###   ########.fr       */
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
}

void	ft_rr(t_list **a, t_list **b)
{
	if (!*b || !*a)
		return ;
	ft_ra(a);
	ft_rb(b);
}

void	ft_rra(t_list **a)
{
	t_list	*temp1;
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp1 = *a;
	temp = (ft_last(*a));
	while (temp1->next->next)
	{
		temp1 = temp1->next;
	}
	temp1->next = NULL;
	ft_lstadd_front(a, temp);
}

void	ft_rrb(t_list **b)
{
	t_list	*temp1;
	t_list	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp1 = *b;
	temp = (ft_last(*b));
	while (temp1->next->next)
		temp1 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_front(b, temp);
}

void	ft_rrr(t_list **a, t_list **b)
{
	if (!*a || !*b)
		return ;
	ft_rrb(b);
	ft_rra(a);
}
