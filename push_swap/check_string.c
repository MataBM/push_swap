/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:30 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/06 15:43:31 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*chartoint(char **arg_a)
{
	int i;
	int j;
	int *num

	i = 1;
	while (!arg_a[i])
	{
		j = 0;
		while (!arg_a[i][j])
		{
			if (ft_isdigit(arg_a[i][j]))
				num[i - 1] = arg_a[i][j];
		}
	}
}

int *check_string(char **arg_a)
{
	int i;
	int j;

	chartoint(arg_a);
}