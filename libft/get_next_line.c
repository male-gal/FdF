/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: male-gal <male-gal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:30:47 by male-gal          #+#    #+#             */
/*   Updated: 2018/05/10 19:34:05 by male-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_str_joiner(char *s1, char *s2, size_t len)
{
	int			i;
	char		*out;
	int			index;

	index = 0;
	i = ft_strlen(s1) + ++len;
	out = ft_strnew(i);
	while (*s1)
	{
		out[index] = *s1++;
		index++;
	}
	while (*s2 && --len > 0)
	{
		out[index] = *s2++;
		index++;
	}
	out[index] = '\0';
	return (out);
}

static char			*ft_strchrcpy(char *save)
{
	if (ft_strchr(save, SEPARATOR))
	{
		ft_strcpy(save, ft_strchr(save, SEPARATOR) + 1);
		return (save);
	}
	if (ft_strlen_untilc(save, SEPARATOR) > 0)
	{
		ft_strcpy(save, ft_strchr(save, '\0'));
		return (save);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*save[OPEN_MAX];
	int			res;
	char		*ptr;

	if (!line || fd <= -1 || BUFF_SIZE < 1 || read(fd, buff, 0) < 0 ||
		(!(save[fd]) && (save[fd] = ft_strnew(0)) == NULL))
		return (-1);
	while (!(ft_strchr(save[fd], SEPARATOR)) && (res =
		read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = save[fd];
		save[fd] = ft_str_joiner(ptr, buff, res);
		free(ptr);
	}
	if (ft_strlen_untilc(save[fd], SEPARATOR) > 0)
		*line = ft_strsub(save[fd], 0, ft_strlen_untilc(save[fd], SEPARATOR));
	else
		return (0);
	if (ft_strchrcpy(save[fd]) == NULL)
		return (0);
	return (1);
}
