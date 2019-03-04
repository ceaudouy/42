/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:47:21 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/02/21 10:47:22 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_map(t_struct *all)
{
    char    **line;
    char    *tmp;
    int     i;

    all->y = 0;
    i = 0;
    if (!(line = (char**)malloc(sizeof(*line) * 1)))
        return;
    if (!(all->map = (char**)malloc(sizeof(*all->map) * 1024)))
        return;
    while ((get_next_line(all->fd, &*line) > 0))
    {
        tmp = ft_strjoin(*line, "\n");
        all->map[i] = tmp;
        free(*line);
        i++;
        all->y++;
    }
    free(line);
}

int     deal_key(int key, t_struct *all)
{
    int i;
    int j;

    i = 0;
    if (key == 53)
        exit (1);
    if (key == 18)
    {
        free_pos(all);
        mlx_clear_window(all->mlx_ptr, all->win_ptr);
        ft_pos(all);
        ft_draw(all);
    }
    if (key == 19)
    {
        free_pos(all);
        mlx_clear_window(all->mlx_ptr, all->win_ptr);
        isometrique(all);
        ft_draw(all);
    }
    ft_putnbr(key);
    return (0);
}

void    ft_exec(t_struct *all, char **av)
{
    ft_map(all);
    ft_alt(all);
    ft_pos(all);
    all->mlx_ptr = mlx_init();
    all->win_ptr = mlx_new_window(all->mlx_ptr, 1500, 1000, av[1]);
    all->img_ptr = mlx_new_image(all->mlx_ptr, all->size[0], all->y);
    mlx_key_hook(all->win_ptr, deal_key, all);
    mlx_loop(all->mlx_ptr);
}

int     main(int ac, char **av)
{
    t_struct *all;

    if (!(all = malloc(sizeof(t_struct) * 1)))
        return (0);
    all->fd = open(av[1], O_RDONLY);
    if (all->fd < 0)
    {
        ft_putstr("error fd\n");
        return (0);
    }
    ft_exec(all, av);
    close(all->fd);
    free(all);
    return (0);
}