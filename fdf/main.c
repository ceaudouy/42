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

/*int     deal_key(int key, void *param)
{
    ft_putnbr(key);
    return (0);
}
*/
void    ft_map(t_struct *all)
{
    int     i;
    int     j;
    char    **line;
    char    *tmp;
    char    *tmp2;


    if (!(line = (char**)malloc(sizeof(*line) * 1)))
        return;
    if (!(all->map = (char**)malloc(sizeof(*all->map) * 1)))
        return;
    j = 0;
    i = 0;
    all->map[1] = ft_strnew(1);

    while ((get_next_line(all->fd, &*line) > 0))
    {
        tmp = ft_strjoin(*line, "\n");
        tmp2 = all->map[i];
        all->map[i] = tmp;
        free(*line);
       // free(tmp);
        //free(tmp2);
        i++;
        all->y++;
    }
    i = 0;
    while (i < all->y)
        ft_putstr(all->map[i]);
    all->x = ft_strlen(all->map[1]);
    free(line);
}

int     main(int ac, char **av)
{
    t_struct *all;

    if (!(all = malloc(sizeof(t_struct) * 1)))
        return (0);
    all->y = 0;
    all->fd = open(av[1], O_RDONLY);
    if (all->fd < 0)
        ft_putstr("error fd\n");
    ft_map(all);
    //all->mlx_ptr = mlx_init();
    // all->win_ptr = mlx_new_window(all->mlx_ptr, 500, 500, "42");
    //mlx_key_hook(all->win_ptr, deal_key, (void*)0);
    //mlx_loop(all->mlx_ptr);
    close(all->fd);
    free(all);
    return (0);
}