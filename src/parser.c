/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:32:25 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/10 20:20:10 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_file_len(char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_disp_error(2);
	while (get_next_line(fd, &tmp) > 0)
	{
		++i;
		free(tmp);
	}
	if (close(fd) != 0)
		ft_disp_error(2);
	return (i);
}

char	**get_map(char *file)
{
	int		fd;
	int		i;
	char	**out;

	i = 0;
	if (!(out = (char**)malloc(sizeof(char *) * (get_file_len(file) + 1))))
		ft_disp_error(2);
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_disp_error(2);
	while (get_next_line(fd, out + i) > 0)
		i++;
	if (close(fd) != 0)
		ft_disp_error(2);
	out[i] = NULL;
	return (out);
}

int		*chartotab(char *str, t_infos *infos)
{
	char	**nbs;
	int		*out;
	int		i;

	i = 0;
	nbs = ft_strsplit(str, ' ');
	while (nbs[i])
		i++;
	if (!(out = (int *)malloc(sizeof(int) * i)))
		ft_disp_error(2);
	i = 0;
	while (nbs[i])
	{
		out[i] = ft_atoi(nbs[i]);
		++i;
	}
	if (infos->w == 0)
		infos->w = i;
	if (infos->w != i)
		ft_disp_error(1);
	ft_strfree(nbs);
	return (out);
}

void	ft_parse(char **str, t_infos *infos)
{
	int **tab;
	int i;

	i = 0;
	while (str[i])
		i++;
	if (!(tab = (int **)malloc(sizeof(int *) * i)))
		ft_disp_error(2);
	i = 0;
	infos->w = 0;
	while (str[i] != NULL)
	{
		tab[i] = chartotab(str[i], infos);
		++i;
	}
	if (i == 0)
		ft_disp_error(6);
	infos->h = i;
	infos->tab = tab;
}
