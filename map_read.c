
#include "so_long.h"
#define BUFFER_SIZE 42

int	add_lines(t_param *par) //
{
	char *str;
	char *temp;

	temp = NULL;
	par->result = ft_strdup("");
	if (!par->result)
		return (1);
	while (1)
	{
		str = get_next_line(par->fd);
		if (str == NULL)
			break ;
		temp = ft_strjoin(par->result, str);
		free(par->result);
		free(str);
		if (temp == NULL)
			return (0);
		par->result = temp;
	}
	if (temp == NULL)
	{
		printf("Error\nnothing to read.\n");
		return (2);
	}
	return (1);
}

//배열의 중간줄들에 1~막줄 전까지 1__1 확인하는 함수

void	error_message(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

// int drawmap(t_param *par)
// {
//     char        *str;
//     int         x;
//     int         y;
//     int         i;

//     x = 0;
//     y = 0;
//     i = 0;
//     mlx_clear_window(par->mlx, par->win);
//     str = par->result;
//     while (str[i] != '\0')
//     {
//         if (str[i] == '\n')
//         {
//             x = 0;
//             y += par->he;
//         }
//         else
//         {
//             draw_imag(str[i], par, x, y);
//             x += par->wi;
//         }
//         i++;
//     }
//     return(0)
// }
// void    draw_img(char a, t_param *par, int x, int y)
// {
//     if (a == '0')
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
//     else if (a == '1')
//     {
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
//         mlx_put_image_to_window(par->mlx, par->win, par->w, x, y);
//     }
//     else if (a == 'P' || a == 'C' || a == 'E')
//     {
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);//땅그리기 먼저
//         if (a == 'P')
//             mlx_put_image_to_window(par->mlx, par->win, par->p, x, y);
//         else if (a == 'C')
//             mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
//         else if (a == 'E')
//             mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
//     }
// }
