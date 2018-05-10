/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:56:28 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/10 20:18:33 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "math.h"

typedef struct	s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int	dy;
	unsigned int	dx;
}				t_line;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_infos
{
	int		w;
	int		h;
	int		**tab;
	int		**proj;
	int		xmove;
	int		ymove;
	int		width;
	int		height;
	int		colorid;
	int		i;
	t_img	*mlx;
}				t_infos;

typedef struct	s_print
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		a;
	int		zoom;
	int		height;
	int		h;
	t_infos *infos;
}				t_print;

int				color_picker(int colorid);
int				deal_key(int key, t_print *print_sett);
int				deal_mouse(int key, int x, int y, t_print *print_sett);
char			**get_map(char *file);
void			ft_process(t_print *print_sett);
void			ft_parse(char **str, t_infos *infos);
void			ft_graphical(t_infos *infos);
void			ft_create_tab(t_infos *infos);
void			ft_del_tab(t_infos *infos);
void			display_main_function(int **tab, t_infos *infos);
void			display_infos(void *mlx_ptr, void *win_ptr, int colorid);
void			quart_four(t_line *line, int colorid, t_infos *infos);
void			quart_three(t_line *line, int colorid, t_infos *infos);
void			quart_two(t_line *line, int colorid, t_infos *infos);
void			quart_one(t_line *line, int colorid, t_infos *infos);
void			ft_disp_error(int type);
#endif
