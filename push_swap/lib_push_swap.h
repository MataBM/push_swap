/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:26 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/13 20:25:36 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP
# define LIB_PUSH_SWAP

# include "libft/libft.h"
# include "printf/ft_printf.h"



int *check_string(char **arg_a);

void printlist(t_list *stk);

void    editstk_S(t_list **stk, char c, int limit);

void    editstk_P(t_list **stk, t_list **dst, char c);

void	editstk_R(t_list **stk, char *type, int limit);

#endif