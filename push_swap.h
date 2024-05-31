/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:34 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/24 15:02:39 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				init;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instructions
{
	char					*content;
	struct s_instructions	*next;
}	t_ins;

enum	e_bool
{
	false,
	true
};

size_t			my_strlen(const char *s);
char			*my_strjoin(char *s1, char const *s2);
char			**join_arr(char **numbers, char **arr);
char			**catch_data(char **av, int ac);
t_stack			*my_lstlast(t_stack *lst);
t_stack			*new_element(int value);
t_stack			*find_a(t_stack **a, int n);
long int		ft_atoi_l(const char *str_n);
unsigned int	stack_len(t_stack *stack);
unsigned int	has_an_error(int ac, char **av);
unsigned int	is_int(char *token);
unsigned int	is_number(char *token);
unsigned int	has_double(char **av, int ac, int index);
unsigned int	all_in_one_string_error(char **av);
unsigned int	is_sorted(t_stack *a);
unsigned int	is_greatest(t_stack *a, int b);
unsigned int	is_new_min(t_stack *b, int n);
unsigned int	is_new_max(t_stack *b, int n);
unsigned int	is_new_min(t_stack *stack, int n);
unsigned int	is_new_max(t_stack *stack, int n);
unsigned int	find_greatest_index(t_stack **stack);
int				search_big_than_a(t_stack **b, int n);
int				search_big_than_b(t_stack **a, int n);
int				find_max(t_stack **stack);
int				find_min_i(t_stack *a);
int				count_instructs_size(char **arr);
int				find_cheapest_n(t_stack **stack);
int				search_big_than_a(t_stack **b, int n);
int				search_big_than_b(t_stack **a, int n);
int				get_j(int i_a, int i_b, int l_a, int l_b);
int				find_cheapest(t_stack **a, t_stack **b, unsigned int l_a);
int				find_four(t_stack **a);
int				find_five(t_stack **a);
int				find_index_of_five(t_stack **a);
int				create_stack_next(t_stack **a, char **av, int i);
int				count_el_in_arr(char **arr);
int				join_arr_next(char **n_arr, char **arr, int i);
void			my_lstadd_back(t_stack **lst, t_stack *new);
int				create_stack(t_stack **a, char **av, int ac);
void			insert_end(t_stack **stack, int value);
void			free_arr(char **arr);
void			free_stack(t_stack **stack, int i);
void			free_instructs(t_ins **ins);
void			free_ab(t_stack **stack);
int				push_in_instructs(t_ins **instructs, char *str);
void			del(t_stack **stack);
int				very_quick_sort(t_stack *a, t_ins **instructs);
void			quick_sort(t_stack **a, t_ins **instructs);
void			sort_five(t_stack **a, t_stack **b, t_ins **ins);
void			push_swap(t_stack **a, t_stack **b, t_ins **instructs);
void			donto_sort(t_stack **a, int l_a, t_ins **instructs);
void			very_donto_sort(t_stack **a, int i, int l_a, t_ins **ins);
void			sort_few(t_stack **a, t_stack **b, t_ins **ins, int len_a);
int				tiny_sort(t_stack **a, t_stack **b, t_ins **ins);
void			show_instructs(t_ins **ins);
void			sort_five(t_stack **a, t_stack **b, t_ins **ins);
void			cost_lb_2(t_stack *a, int i_b, int i_a, int l_a);
void			cost_one(t_stack *a, int i_b, int i_a, int l_a);
void			cost_two(t_stack *a, int i_b, int i_a, int l_a);
void			cost_three(t_stack *a, int i_b, int i_a, int l_b);
void			cost_three_next(t_stack **a, int i_b, int i_a, int l_b);
void			cost_four(t_stack *a, int i_b, int i_a, int l_b);
void			case_lb_2(t_stack **a, t_stack **b, int i_a, t_ins **ins);
void			case_lb_2_next(t_stack **a, t_stack **b, int i_a, t_ins **ins);
void			case_one(t_stack **a, t_stack **b, t_ins **ins, int i_b);
void			case_one_next(t_stack **a, t_stack **b, t_ins **ins, int j);
void			case_two(t_stack **a, t_stack **b, t_ins **ins, int i_b);
void			case_three(t_stack **a, t_stack **b, t_ins **ins, int i_b);
void			case_four(t_stack **a, t_stack **b, t_ins **ins, int i_b);
void			clean_instructs(t_stack **a, t_stack **b);
void			exec_ins_ab(t_stack **a, t_stack **b, int i_a, t_ins **ins);
void			final_sort(t_stack **a, t_stack **b, t_ins **instructs);
void			push_swap(t_stack **a, t_stack **b, t_ins **instructs);
void			exec_ins(t_stack **a, t_stack **b, t_ins **ins, int i_a);
void			push_cost_a(t_stack *a, t_stack **b, int i_b, int i_a);
int				sa(t_stack *a, t_ins **instructs);
void			sb(t_stack *b, t_ins **instructs);
void			ss(t_stack *a, t_stack *b, t_ins **instructs);
void			pa(t_stack **a, t_stack **b, t_ins **instructs);
void			pb(t_stack **b, t_stack **a, t_ins **instructs);
void			ra(t_stack **a, t_ins **instructs);
void			rb(t_stack **b, t_ins **instructs);
void			rr(t_stack **a, t_stack **b, t_ins **instructs);
void			rra(t_stack **a, t_ins **instructs);
void			rrb(t_stack **b, t_ins **instructs);
void			rrr(t_stack **a, t_stack **b, t_ins **instructs);

#endif
