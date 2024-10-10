#include "so_long.h"

int	main(void)
{
	t_param par;

	par.fd = open("./map1.ber", O_RDONLY);
	if (par.fd == -1)
	{
		perror("파일 열기 실패");
		return (1);
	}
	if (add_lines(&par) == 2)
	{
		close(par.fd);
		exit(EXIT_FAILURE);
	}
	if (!par.result)
	{
		perror("파일 읽기 실패");
		close(par.fd);
		return (1);
	}
	close(par.fd);
	// map_checker(&par);
	// free(par.result);
	if (map_checker(&par) != 0)
	{
		free(par.result);
		error_message("Error : invalid map!");
		return (1);
	}
	free(par.result);
	par.mlx = mlx_init();
	if (!par.mlx)
	{
		error_message("mlx_init() 실패");
		return (1);
	}
	par.win = mlx_new_window(par.mlx, par.win_width, par.win_height, "So_long");
	if (!par.win)
	{
		error_message("mlx_new_window() 실패");
		return (1);
	}
	mlx_loop(par.mlx);
	return (0);
}