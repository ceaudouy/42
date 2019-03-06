/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:47:21 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/03/05 18:55:50 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map(t_struct *all)
{
	char	**line;
	char	*tmp;
	int		i;

	all->y = 0;
	i = 0;
	if (!(line = (char**)malloc(sizeof(*line) * 1)))
		exit(1);
	if (!(all->map = (char**)malloc(sizeof(*all->map) * 1024)))
		exit(1);
	while ((get_next_line(all->fd, &*line) > 0))
	{
		tmp = ft_strjoin(*line, "\n");
		check_error(tmp);
		all->map[i] = tmp;
		free(*line);
		i++;
		all->y++;
	}
	free(line);
}

int		deal_key(int key, t_struct *all)
{
	if (key == 53)
	{
		free_tab(all);
		close(all->fd);
		free(all);
		exit(1);
	}
	key_para(all, key);
	key_iso(all, key);
	if (key == 18 || key == 116 || (key >= 123 && key <= 126) || key == 121)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
		ft_pos(all);
		ft_draw(all);
	}
	if (key == 19 || key == 13 || (key >= 0 && key <= 3) || key == 15)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
		isometrique(all);
		ft_draw(all);
	}
	return (0);
}

void	ft_exec(t_struct *all, char **av)
{
	ft_map(all);
	ft_alt(all);
	ft_pos(all);
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, 1500, 1000, av[1]);
	mlx_key_hook(all->win_ptr, deal_key, all);
	mlx_loop(all->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_struct *all;

	if (ac != 2)
	{
		ft_putstr("too many arguments\n");
		return (0);
	}
	if (!(all = malloc(sizeof(t_struct) * 1)))
		return (0);
	all->fd = open(av[1], O_RDONLY);
	if (all->fd < 0)
	{
		ft_putstr("error fd\n");
		return (0);
	}
	all->posx = 0;
	all->posy = 0;
	all->coef = 0;
	ft_exec(all, av);
	return (0);
}
