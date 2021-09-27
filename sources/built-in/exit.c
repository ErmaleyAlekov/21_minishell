/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:53 by nephilister       #+#    #+#             */
/*   Updated: 2021/09/27 20:34:11 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_exit(int a)
{
	if (a == 0)
	{
		// printf("%sExit\n", RED);
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Exit\n", 2);
		exit(0);
	}
}
