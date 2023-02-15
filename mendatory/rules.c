/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:16:18 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:26 by rbouissa         ###   ########.fr       */
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
	if (!a)
		return ;
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *b)
{
	if (!b)
		return ;
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *b, t_list *a)
{
	if (!b || !a)
		return ;
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
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
	write(1, "pa\n", 3);
}
