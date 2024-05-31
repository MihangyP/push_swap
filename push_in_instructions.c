/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:49 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/04 06:05:56 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_in_instructs_next(t_ins **ins, char *str)
{
	t_ins	*last;

	last = (t_ins *)ft_lstlast((t_list *)(*ins));
	if (NULL == last)
		return (0);
	last->next = (t_ins *)malloc(sizeof(t_ins));
	if (NULL == last->next)
		return (0);
	last->next->content = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (NULL == last->next->content)
		return (0);
	last->next->content[ft_strlen(str)] = '\0';
	ft_memcpy(last->next->content, str, ft_strlen(str));
	last->next->next = NULL;
	return (1);
}

int	push_in_instructs(t_ins **instructs, char *str)
{
	t_ins	*last;
	int		str_size;

	str_size = ft_strlen(str);
	if (NULL == *instructs)
	{
		*instructs = (t_ins *)malloc(sizeof(t_ins));
		if (NULL == *instructs)
			return (0);
		(*instructs)->content = malloc((str_size + 1) * sizeof(char));
		if (NULL == (*instructs)->content)
			return (0);
		(*instructs)->content[ft_strlen(str)] = '\0';
		ft_memcpy((*instructs)->content, str, ft_strlen(str));
		(*instructs)->next = NULL;
	}
	else
		return (push_in_instructs_next(instructs, str));
	return (1);
}
