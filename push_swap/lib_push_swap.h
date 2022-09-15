/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:26 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/15 17:19:23 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

int		*check_string(char **arg_a);
void	printlist(t_list *stk);
void	editstk_s(t_list **stk, char c, int limit);
void	editstk_p(t_list **stk, t_list **dst, char c);
void	editstk_r(t_list **stk, char *type, int limit);
int		check_if_complete(t_list *stk, int *stk_array, int size);
void	less_ten(t_list **stk, int stk_array, int size);

#endif