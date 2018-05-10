/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:36:11 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/09 20:27:04 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_picker(int colorid)
{
	if (colorid == 0)
		return (0xffffff);
	if (colorid == 1)
		return (0xffcc00);
	if (colorid == 2)
		return (0x00bfff);
	if (colorid == 3)
		return (0x99ff33);
	if (colorid == 4)
		return (0xff66ff);
	return (0);
}

void	ft_del_tab(t_infos *infos)
{
	int i;

	i = 0;
	while (i < infos->h * infos->w)
	{
		free(infos->proj[i]);
		i++;
	}
	free(infos->proj);
}

void	ft_create_tab(t_infos *infos)
{
	int **proj;
	int i;

	i = 0;
	if (!(proj = (int **)malloc(sizeof(int *) * (infos->w * infos->h))))
		ft_disp_error(2);
	while (i < infos->h * infos->w)
	{
		if (!(proj[i] = (int *)malloc(sizeof(int) * 2)))
			ft_disp_error(2);
		i++;
	}
	infos->proj = proj;
}
