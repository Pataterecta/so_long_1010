#include "so_long.h"

int	check_element_map(t_param *par)
{
	int	i;

	i = 0;
	while (par->result[i] != '\0')
	{
		if (par->result[i] != '0' && par->result[i] != '1'
			&& par->result[i] != 'C' && par->result[i] != 'E'
			&& par->result[i] != 'P' && par->result[i] != '\n')
		{
			printf("NO u no eyes!? INVALID components\n");
			return (1); // 오류가 있으면 1 반환
		}
		i++;
	}
	return (0); // 모든 문자가 유효하면 0 반환
}

int	check_empty_line(t_param *par)
{
	int	i;

	i = 0;
	if (par->result[0] == '\n')
	{
		printf("Error\nempty line found\n");
		return (1);
	}
	while (par->result[i] != '\0')
	{
		if (par->result[i] == '\n' && par->result[i + 1] == '\n')
		{
			printf("Error\nempty line found\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			printf("Error\nwall line missing\n");
			return (1);
		}
		i++;
	}
	return (0);
}
int	check_one_boundaries(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (1);
	while (str[i])
	{
		i++;
	}
	if (str[i - 1] == '1')
		return (0);
	return (1);
}

//배열의 마지막줄이 몇번째 줄인지 확인하는 함수
void	howmanylines(t_param *par)
{
	int i;

	i = 0;
	while (par->splited_res[i] != NULL)
	{
		i++;
	}
	par->n_of_lines = i - 1;
}