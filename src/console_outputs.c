/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_outputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:40:34 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/10 20:12:20 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int type)
{
	if (type == 0)
	{
		ft_putstr_fd("fdf : usage : ./fdf <map_file.fdf> {window width}", 2);
		ft_putendl_fd(" {window heigth} | width and height optionnal", 2);
	}
	if (type == 1)
	{
		ft_putstr_fd("fdf : The map must have the same number of points", 2);
		ft_putendl_fd("	on each line.", 2);
	}
	if (type == 2)
		ft_putendl_fd("fdf : malloc, open, close or read error", 2);
	if (type == 3)
	{
		ft_putstr_fd("fdf : width should be between 700px & 2400px. heigth", 2);
		ft_putendl_fd(" between 700px and 1300px", 2);
	}
	if (type == 4)
		ft_putendl_fd("fdf : mlx was unable to launch", 2);
	exit(0);
}
