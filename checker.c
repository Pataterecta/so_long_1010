#include "so_long.h"

int	middle_lines(t_param *par)
{
	int	i;

	i = 1;
	while (i < par->n_of_lines)
	{
		if (check_one_boundaries(par->splited_res[i]) != 0)
		{
			printf("Error\nwall column fked up");
			return (1);
		}
		i++;
	}
	return (0);
}

//요소 갯수 체크하기
int	count_compo(t_param *par)
{
	int	i;

	par->C = 0;
	par->P = 0;
	par->E = 0;
	i = 0;
	while (par->result[i])
	{
		if (par->result[i] == 'C')
			par->C += 1;
		if (par->result[i] == 'P')
			par->P += 1;
		if (par->result[i] == 'E')
			par->E += 1;
		i++;
	}
	if (par->C < 1 || par->E != 1 || par->P != 1)
	{
		printf("Error\nCompenents problem.");
		return (1);
	}
	return (0);
}

//스플릿 한 애들의 길이를 다 비교한다 comparer la taille de chaque ligne qui est "SPLITed"
int	length_compare(t_param *par)
{
	int		i;
	size_t     len;

	i = 1;
	len = ft_strlen(par->splited_res[0]);
	while (par->splited_res[i])
	{
		if (ft_strlen(par->splited_res[i]) != len)
		{
			printf("EACH lines arent the same length");
			return (1);
		}
		i++;
	}
    par->win_width = len * 64;
    par->win_height = i * 64;
	return (0);
}

int	map_checker(t_param *par)
{
	int i;

	i = 0;
	par->splited_res = ft_split(par->result, '\n');
	howmanylines(par);
	if (check_element_map(par) != 0)
		exit(EXIT_FAILURE);
	if (length_compare(par) != 0)
		exit(EXIT_FAILURE);
	if (check_empty_line(par) != 0)
		exit(EXIT_FAILURE);
	if (check_all_ones(par->splited_res[0]) != 0)
		exit(EXIT_FAILURE);
	if (check_all_ones(par->splited_res[par->n_of_lines]) != 0)
		exit(EXIT_FAILURE);
	if (middle_lines(par) != 0)
		exit(EXIT_FAILURE);
	if (count_compo(par) != 0)
		exit(EXIT_FAILURE);
	return (0);
}
