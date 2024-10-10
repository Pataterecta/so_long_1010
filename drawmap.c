
#include "so_long.h"

void	draw_img(char a, t_param *par, int x, int y)
{
	if (a == '0')
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
	else if (a == '1')
	{
		mlx_put_image_to_window(\
		par->mlx, par->win, par->g, x, y);
		mlx_put_image_to_window(\
		par->mlx, par->win, par->w, x, y);
	}
	else if (a == 'P' || a == 'C' || a == 'E')
	{
		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
		if (a == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->p, x, y);
		else if (a == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
		else if (a == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
	}
}

// void	draw_img(char a, t_param *par, int x, int y)
// {
// 	if (a == '0')
// 		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
// 	else if (a == '1')
// 	{
// 		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
// 		mlx_put_image_to_window(par->mlx, par->win, par->w, x, y);
// 	}
// 	else if (a == 'P' || a == 'C' || a == 'E')
// 	{
// 		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
// 		if (a == 'P')
// 			mlx_put_image_to_window(par->mlx, par->win, par->p, x, y);
// 		else if (a == 'C')
// 			mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
// 		else if (a == 'E')
// 			mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
// 	}
// }

int	drawmap(t_param *data)
{
	char		**map_data;
	char		*str;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	mlx_clear_window(data->mlx, data->win);
	map_data = data->splited_res;
	while (map_data[i] != NULL)
	{
		str = map_data[i];
		while (*str != '\0')
		{
			draw_img(*str, data, x, y);
			str++;
			x = x + 64;
		}
		i++;
		x = 0;
		y = y + 64;
	}
	return (0);
}

int	win_map_size(t_param *par)
{
	par->win_height = 64 * par->he;
	par->win_width = 64 * par->wi;
	return (0);
}