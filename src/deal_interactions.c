/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_interactions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:36:11 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/09 23:45:35 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int key, int x, int y, t_print *print_sett)
{
	x = 0;
	y = 0;
	mlx_clear_window(print_sett->mlx_ptr, print_sett->win_ptr);
	if (key == 4)
		print_sett->zoom++;
	if (key == 5)
		print_sett->zoom--;
	ft_process(print_sett);
	return (0);
}

void	deal_key2(int key, t_print *print_sett)
{
	if (key == 34)
	{
		if (print_sett->infos->colorid == 4)
			print_sett->infos->colorid = 0;
		else
			print_sett->infos->colorid++;
	}
}

int		deal_key(int key, t_print *print_sett)
{
	if (key == 53)
		ft_disp_error(5);
	mlx_clear_window(print_sett->mlx_ptr, print_sett->win_ptr);
	if (key == 69)
		print_sett->h++;
	if (key == 78 && print_sett->h > 0)
		print_sett->h--;
	if (key == 6)
		print_sett->zoom++;
	if (key == 7 && print_sett->zoom > 0)
		print_sett->zoom--;
	if (key == 123)
		print_sett->infos->xmove--;
	if (key == 124)
		print_sett->infos->xmove++;
	if (key == 126)
		print_sett->infos->ymove--;
	if (key == 125)
		print_sett->infos->ymove++;
	if (key == 31)
		print_sett->a++;
	else
		deal_key2(key, print_sett);
	ft_process(print_sett);
	return (0);
}
