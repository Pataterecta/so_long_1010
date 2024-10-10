#include "so_long.h"


int	key_press(int keycode, t_param *par)
{
	if (keycode == KEY_W)
	{
		move_up(par, par->p_y);
	}
	else if (keycode == KEY_S)
	{
		move_down(par, par->p_y);
	}
	else if (keycode == KEY_A)
	{
		move_left(par, par->p_y);
	}
	else if (keycode == KEY_D)
	{
		move_right(par, par->p_y);
	}
	else if (keycode == KEY_ESC)
		map_esc();
	printf("step: %d\n", par->move);
	//움직인 횟수 출력
	drawmap(par);
	//맵을 다시 그려줌
	return (0);
}

int	map_red_exit()
{
	printf("Exit : Red Button\n");
	exit(0);
	return (1);
}

int	map_esc()
{
	printf("Exit : ESC\n");
	exit(0);
	return (0);
}

int	ft_exit(t_param *map)
{
	map->move++;
	printf("Exit : GAME SUCCESS,total move = %d\n", map->move);
	exit(0);
	return (0);
}

