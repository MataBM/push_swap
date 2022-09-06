/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:33 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/06 15:43:34 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int main(int arg_n, char **arg_a)
{
    if (arg_n > 1)
        check_string(arg_a);
    else
        ft_putstr("argumentos insuficientes");
    return (0);
}