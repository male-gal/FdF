/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:36:11 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/09 23:52:16 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_img(t_infos *infos, t_img *mlx, void *mlx_ptr)
{
	mlx->img_ptr = mlx_new_image(mlx_ptr, infos->width, infos->height);
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_l,
		&mlx->endian);
}

int		**to_isometric(t_infos *infos, int a, int zoom, int height)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < infos->h)
	{
		j = 0;
		while (j < infos->w)
		{
			infos->proj[k][0] = ((i * cos(a) * zoom + j * cos(a + 2) * zoom
				+ infos->tab[i][j] * cos(a - 2) * zoom / 20 * height) +
			(infos->height / 3)) + infos->ymove * 50;
			infos->proj[k][1] = ((i * sin(a) * zoom + j * sin(a + 2) * zoom
				+ infos->tab[i][j] * sin(a - 2) * zoom / 20 * height) +
			(infos->width / 2)) + infos->xmove * 50;
			++j;
			++k;
		}
		++i;
	}
	return (infos->proj);
}

void	ft_process(t_print *print_sett)
{
	t_img	mlx[1];

	ft_init_img(print_sett->infos, mlx, print_sett->mlx_ptr);
	print_sett->infos->mlx = mlx;
	to_isometric(print_sett->infos, print_sett->a,
		print_sett->zoom, print_sett->h);
	display_main_function(print_sett->infos->proj, print_sett->infos);
	mlx_put_image_to_window(print_sett->mlx_ptr, print_sett->win_ptr,
		print_sett->infos->mlx->img_ptr, 0, 0);
	display_infos(print_sett->mlx_ptr, print_sett->win_ptr,
		print_sett->infos->colorid);
	mlx_destroy_image(print_sett->mlx_ptr, print_sett->infos->mlx->img_ptr);
}

void	ft_graphical(t_infos *infos)
{
	t_print	print_sett[1];

	infos->xmove = 0;
	infos->ymove = 0;
	infos->colorid = 0;
	print_sett->a = 18;
	print_sett->zoom = 30;
	print_sett->h = 2;
	if (!(print_sett->mlx_ptr = mlx_init()))
		ft_disp_error(4);
	print_sett->win_ptr = mlx_new_window(print_sett->mlx_ptr, infos->width,
		infos->height, "FDF");
	print_sett->infos = infos;
	ft_create_tab(infos);
	ft_process(print_sett);
	mlx_hook(print_sett->win_ptr, 2, 5, deal_key, print_sett);
	mlx_mouse_hook(print_sett->win_ptr, deal_mouse, print_sett);
	mlx_loop(print_sett->mlx_ptr);
}
