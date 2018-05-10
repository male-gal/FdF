/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:30:42 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/09 20:27:35 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_extension(char *filename)
{
	int i;

	i = ft_strlen(filename);
	i -= 4;
	if (i <= 0 || ft_strcmp(filename + i, ".fdf"))
		ft_disp_error(0);
}

void	ft_win_set(t_infos *infos, char *x, char *y)
{
	if (ft_atoi(x) < 700 || ft_atoi(x) > 2400 || ft_atoi(y) < 700 ||
		ft_atoi(y) > 1300)
		ft_disp_error(3);
	infos->width = ft_atoi(x);
	infos->height = ft_atoi(y);
}

int		main(int argc, char **argv)
{
	char	**in;
	t_infos	infos[1];

	if (argc > 1 && argc < 5)
	{
		ft_check_extension(argv[1]);
		if (argc == 4)
			ft_win_set(infos, argv[2], argv[3]);
		else
		{
			infos->width = 1700;
			infos->height = 1000;
		}
		in = get_map(argv[1]);
		ft_parse(in, infos);
		ft_graphical(infos);
		ft_strdel(in);
		ft_del_tab(infos);
	}
	ft_disp_error(0);
	return (0);
}
