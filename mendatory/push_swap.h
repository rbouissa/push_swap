/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:21:30 by rbouissa          #+#    #+#             */
/*   Updated: 2023/02/15 18:33:28 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_all
{
	char			*str;
	char			**s;
	int				numb;
	int				n;
	int				*tab;
	t_list			*stack_a;
	t_list			*stack_b;
	int				count;
}					t_all;
typedef struct s_sort
{
	int				count;
	int				mid;
	int				start;
	int				end;
}					t_sort;
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_atoi(char *s);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(int x);
void				ft_sa(t_list *a);
void				ft_sb(t_list *b);
void				ft_ss(t_list *b, t_list *a);
void				ft_ra(t_list **a);
void				ft_rr(t_list **a, t_list **b);
void				ft_rb(t_list **b);
void				ft_pb(t_list **b, t_list **a);
void				ft_pa(t_list **b, t_list **a);
t_list				*ft_last(t_list *a);
void				ft_rra(t_list **a);
void				ft_rrb(t_list **b);
void				ft_rrr(t_list **a, t_list **b);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *left_str, char *buff);
int					count_tab(char const *s, char c);
void				sort_3(t_list **a);
int					size_list(t_list *a);
int					getindex(t_list *stack_a, int a);
void				sort_5(t_list **stack_a, t_list **stack_b);
void				fuul_b_h(t_list **stack_a, t_list **stack_b, int range);
int					*full_tab(t_list *st_a);
int					sort_tab(int *tab, int size);
void				fuul_a_h(t_list **stack_a, t_list **stack_b);
void				ft_write(void);

#endif
