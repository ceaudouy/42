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

int     deal_key(int key, t_struct *all)
{
    if (key == 53)
        exit (1);
   // if (key == 35)
    //{
        
    //}
    ft_putnbr(key);
    return (0);
}

void    ft_map(t_struct *all)
{
    char    **line;
    char    *tmp;
    int     i;

    i = 0;
    if (!(line = (char**)malloc(sizeof(*line) * 1)))
        return;
    if (!(all->map = (char**)malloc(sizeof(*all->map) * 1024)))
        return;
    while ((get_next_line(all->fd, &*line) > 0))
    {
        tmp = ft_strjoin(*line, "\n");
        all->map[i] = tmp;
        //free(*line);
        //free(tmp);
        i++;
        all->y++;
    }
    //free(line);
}

void    ft_exec(t_struct *all, char **av)
{
    ft_map(all);
    ft_alt(all);
    all->mlx_ptr = mlx_init();
    all->win_ptr = mlx_new_window(all->mlx_ptr, 1500, 1000, av[1]);
    mlx_key_hook(all->win_ptr, deal_key, (void*)0);
    ft_pos(all);
    //isometrique(all);
    ft_draw(all);
    //put_pixel(all);
    mlx_loop(all->mlx_ptr);
}

int     main(int ac, char **av)
{
    t_struct *all;

    if (!(all = malloc(sizeof(t_struct) * 1)))
        return (0);
    all->y = 0;
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