/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 06:47:18 by bmulamba          #+#    #+#             */
/*   Updated: 2018/08/25 15:51:57 by bmulamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char		*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(dup = (char*)malloc((i + 2) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		dup[i] = str[i];
	dup[i + 1] = '\0';
	return (dup);
}

char			*read_file(const int fd)
{
	int				i;
	int				len;
	char			buf[BUF_SIZE];
	char			*s;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char))))
		return (NULL);
	s[0] = '\0';
	while ((len = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
	{
		s = ft_strdup(s);
		s[i++] = buf[0];
	}
	return ((len == 0 && i == 0) ? NULL : s);
}

static void		fill_map(t_env *e, char *str, int j)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[len])
		len++;
	if (!(e->map[j] = (char*)malloc(len * sizeof(char))))
		exit(EXIT_FAILURE);
	len = 0;
	while (str[++i])
		if (str[i] != ' ')
			e->map[j][len++] = str[i];
}

void			ft_parser(t_env *e)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	if ((fd = open("map", O_RDONLY)) == -1)
	{
		write(1, "\e\x1b[31mCan not open the map!\n", 29);
		exit(EXIT_FAILURE);
	}
	if (!(e->map = (char**)malloc(24 * sizeof(char*))))
		exit(EXIT_FAILURE);
	while ((line = read_file(fd)) != NULL)
		fill_map(e, line, i++);
	free(line);
	close(fd);
}
