/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:59:56 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:40:37 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(void)
// {
// 	t_list	*stack_a;
//     t_list *stack_b;

//     if(check_sort(stack_a)&& !stack_b)
//         write(1,"ko\n",1);

// }

int	check_sort(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check(t_list **a, char *rule, t_list **b)
{
	if (!ft_strcmp(rule, "sa\n"))
		ft_sa(*a);
	else if (!ft_strcmp(rule, "sb\n"))
		ft_sb(*b);
	else if (!ft_strcmp(rule, "pa\n"))
		ft_pa(b, a);
	else if (!ft_strcmp(rule, "pb\n"))
		ft_pb(b, a);
	else if (!ft_strcmp(rule, "ss\n"))
		ft_ss(*b, *a);
	else if (!ft_strcmp(rule, "ra\n"))
		ft_ra(a);
	else if (!ft_strcmp(rule, "rb\n"))
		ft_rb(b);
	else if (!ft_strcmp(rule, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(rule, "rra\n"))
		ft_rra(a);
	else if (!ft_strcmp(rule, "rrb\n"))
		ft_rrb(b);
	else if (!ft_strcmp(rule, "rrr\n"))
		ft_rrr(a, b);
	else
		(write(1, "Error\n", 6), exit(1));
}
