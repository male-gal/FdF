/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:36:11 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/10 19:36:40 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_disp_error(int type)
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
	if (type == 5)
		ft_putendl_fd("fdf : End of session. Bye !", 1);
	if (type == 6)
		ft_putendl_fd("fdf : file is empty or has no valid points", 1);
	exit(0);
}

void	draw_line_2(int **tab, t_infos *infos)
{
	t_line line[1];

	line->x1 = tab[infos->i][1];
	line->x2 = tab[infos->i + infos->w][1];
	line->y1 = tab[infos->i][0];
	line->y2 = tab[infos->i + infos->w][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		quart_one(line, infos->colorid, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		quart_two(line, infos->colorid, infos);
	if (line->dx == 0)
		quart_three(line, infos->colorid, infos);
	if (line->dy == 0)
		quart_four(line, infos->colorid, infos);
}

void	draw_line_1(int **tab, t_infos *infos)
{
	t_line line[1];

	line->x1 = tab[infos->i][1];
	line->x2 = tab[infos->i + 1][1];
	line->y1 = tab[infos->i][0];
	line->y2 = tab[infos->i + 1][0];
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->dx >= line->dy && line->dx != 0 && line->dy != 0)
		quart_one(line, infos->colorid, infos);
	if (line->dx < line->dy && line->dx != 0 && line->dy != 0)
		quart_two(line, infos->colorid, infos);
	if (line->dx == 0)
		quart_three(line, infos->colorid, infos);
	if (line->dy == 0)
		quart_four(line, infos->colorid, infos);
}

void	display_infos(void *mlx_ptr, void *win_ptr, int colorid)
{
	mlx_string_put(mlx_ptr, win_ptr, 20, 20, color_picker(colorid),
		"============== FDF : INFOS ==============");
	mlx_string_put(mlx_ptr, win_ptr, 20, 40, color_picker(colorid),
		"esc          = (rage)QUIT");
	mlx_string_put(mlx_ptr, win_ptr, 20, 60, color_picker(colorid),
		"+ / -        = Increase/Decrease Altitude");
	mlx_string_put(mlx_ptr, win_ptr, 20, 80, color_picker(colorid),
		"z / x        = Zoom In/Out");
	mlx_string_put(mlx_ptr, win_ptr, 20, 100, color_picker(colorid),
		"up / down    = Move UP/Down");
	mlx_string_put(mlx_ptr, win_ptr, 20, 120, color_picker(colorid),
		"left / right = Move Left/Right");
	mlx_string_put(mlx_ptr, win_ptr, 20, 140, color_picker(colorid),
		"o            = Rotate View");
	mlx_string_put(mlx_ptr, win_ptr, 20, 160, color_picker(colorid),
		"i            = Switch Color");
}

void	display_main_function(int **tab, t_infos *infos)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while (i < infos->w * infos->h - 1)
	{
		if ((i != (infos->w * x) - 1))
		{
			infos->i = i;
			draw_line_1(tab, infos);
		}
		else
			++x;
		++i;
	}
	i = 0;
	while (i < infos->w * infos->h - infos->w)
	{
		infos->i = i;
		draw_line_2(tab, infos);
		++i;
	}
}
