/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:18:18 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/23 17:25:05 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\nMap not found\n", 20);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
		so_long(argv[1]);
	else
	{
		write(1, "Error\nToo many arguments\n", 25);
		exit(EXIT_FAILURE);
	}
	return (0);
}
