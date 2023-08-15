/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:31:31 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/15 19:53:51 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	**map;
	char	*line;
	char	*temp;

	if (argc != 2)
	{
		write(1, "Error : Invalid parameters\n", 27);
		exit (1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	printf("FD : %d\n", fd);
	if (fd == -1)
	{
		write(1, "Error : Fail to open map file\n", 21);
		exit (1);
	}

	line = strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = ft_strjoin(temp, line);
	}
	
	// split 전에 map 유효성 검사
	int	t = 0;
	int t_len = ft_strlen(temp);
	while (temp[t] != '\0')
	{
		if (temp[0] == '\n' || temp[t_len - 1] == '\n')
		{
			write(1, "Error : Map starts or ends with newline\n", 40);
			exit (1);
		}
		if (temp[t] == '\n' && temp[t + 1] == '\n')
		{
			write(1, "Map has empty line\n", 20);
			exit (1);
		}	
		t++;
	}
	
	printf("TEMP : \n%s\n", temp);
	map = ft_split(temp, '\n');

	
	int	row = 0;
	int	column = 0;

	int free_space = 0;
	int wall = 0;
	int collectible = 0;
	int escape = 0;
	int player = 0;
	int column_count = 0;

	// map 돌면서 component++, rectangle check, invalid component check
	while (map[row] != NULL)
	{
		while (map[row][column] != '\0')
		{
			if (map[row][column] == '0')
				free_space++;
			else if (map[row][column] == '1')
				wall++;
			else if (map[row][column] == 'C')
				collectible++;
			else if (map[row][column] == 'E')
				escape++;
			else if (map[row][column] == 'P')
				player++;
			else
			{
				write(1, "Invalid component exists!\n", 26);
				exit (1);
			}
			column++;
		}
		if (row == 0)
			column_count = column;
		printf("col : %d, col_count : %d\n", column, column_count);
		if (column_count != column)
		{
			write(1, "Map is not rectangular!\n", 24);
			exit (1);
		}
		column = 0;
		row++;
	}
	// component number check
	if (collectible < 1 || escape != 1 || player != 1)
	{
		write(1, "Wrong number of components!\n", 28);
		exit (1);
	}

	int	i = 0;
	int	j = 0;
	// map 돌면서 wall check
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (i == 0 || i == (row - 1))
			{
				if (map[i][j] != '1')
				{
					write(1, "Map is not surrounded by walls!\n", 32);
					exit (1);
				}
			}
			if (j == 0 || j == (column_count - 1))
			{
				if (map[i][j] != '1')
				{
					write(1, "Map is not surrounded by walls!\n", 32);
					exit (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	
	printf("Row count : %d\n", row);
	printf("Column count : %d\n", column_count);

	
	i = 0;
	j = 0;
	// check valid route
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				printf("P_low : %d\nP_col : %d\n", i, j);
				check_valid_route(map, i, j, collectible, escape);
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	close(fd);
	return (0);
}


void	check_valid_route(char **map, int i, int j, int collectible, int escape)
{
	// up
	//map[i - 1][j]
	// right
	//map[i][j + 1]
	// down
	//map[i + 1][j]
	// left
	//map[i][j - 1]

	if (map[i - 1][j] != 1)
	{
		if (map[i-1][i] == 'C')
			collectible--;
		if (map[i-1][i] == 'E')
			escape--;
		check_valid_route(map, i - 1, j, collectible, escape);
	}
	if (map[i][j + 1] != 1)
	{
		if (map[i][j + 1] == 'C')
			collectible--;
		if (map[i][j + 1] == 'E')
			escape--;
		check_valid_route(map, i, j + 1, collectible, escape);
	}
	if (map[i + 1][j] != 1)
	{
		if (map[i + 1][j] == 'C')
			collectible--;
		if (map[i + 1][j] == 'E')
			escape--;
		check_valid_route(map, i + 1, j, collectible, escape);
	}
	if (map[i][j - 1] != 1)
	{
		if (map[i][j - 1] == 'C')
			collectible--;
		if (map[i][j - 1] == 'E')
			escape--;
		check_valid_route(map, i, j - 1, collectible, escape);
	}
	printf("collectible : %d\n", collectible);
	printf("escape : %d\n", escape);
}