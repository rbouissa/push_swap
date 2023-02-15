/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:16:18 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:36:59 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *a)
{
	int	tmp;

	tmp = a->data;
	a->data = a->next->data;
	a->next->data = tmp;
}

void	ft_sa(t_list *a)
{
	if (!a || !a->next)
		return ;
	ft_swap(a);
}

void	ft_sb(t_list *b)
{
	if (!b || b->next)
		return ;
	ft_swap(b);
}

void	ft_ss(t_list *b, t_list *a)
{
	if (!b || !a || !b->next || !a->next)
		return ;
	ft_swap(a);
	ft_swap(b);
}

void	ft_pa(t_list **b, t_list **a)
{
	t_list	*temp;

	temp = (*b);
	if (!*b)
		return ;
	(*b) = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp);
}
