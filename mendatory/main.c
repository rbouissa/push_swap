/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:15:36 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:44:19 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int *tab, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k)
	{
		j = i + 1;
		while (j < k)
		{
			if (tab[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	sort_all(t_list *stack_a, t_list *stack_b, int count)
{
	int	*tab;

	if (count <= 16)
		sort_5(&stack_a, &stack_b);
	else if (count > 16 && count <= 100)
	{
		fuul_b_h(&stack_a, &stack_b, count / 8);
		fuul_a_h(&stack_a, &stack_b);
	}
	else if (count > 100)
	{
		fuul_b_h(&stack_a, &stack_b, count / 18);
		fuul_a_h(&stack_a, &stack_b);
	}
}

void	check_split(int argc, char **s)
{
	int		i;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(s[i], ' ');
		if (*str == NULL)
			ft_write();
		i++;
	}
}

void	split_all(t_all *p)
{
	p->n = 0;
	p->s = ft_split(p->str, ' ');
	p->tab = malloc(4 * count_tab(p->str, ' '));
	while (p->n < count_tab(p->str, ' '))
	{
		p->numb = ft_atoi(p->s[p->n]);
		p->tab[p->n] = p->numb;
		ft_lstadd_back(&p->stack_a, ft_lstnew(p->numb));
		p->n++;
	}
	if (check_dup(p->tab, count_tab(p->str, ' ')))
		ft_write();
	free(p->tab);
}

int	main(int argc, char **argv)
{
	t_all	*p;

	p = malloc(sizeof(t_all));
	p->n = 1;
	p->str = NULL;
	p->stack_a = NULL;
	p->stack_b = NULL;
	if (argc > 1)
	{
		check_split(argc, argv);
		while (p->n < argc)
		{
			if (argv[p->n][0] == '\0')
				ft_write();
			p->str = ft_strjoin(p->str, " ");
			p->str = ft_strjoin(p->str, argv[p->n]);
			p->n++;
		}
		split_all(p);
		p->count = size_list(p->stack_a);
		sort_all(p->stack_a, p->stack_b, p->count);
	}
	else
		exit(0);
}
