/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:31:31 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/14 22:41:34 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	char	*line;
	char	*temp;
	int		i;
	int		j;
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
	printf("TEMP : \n%s\n", temp);
	map = ft_split(temp, '\n');
	i = 0;
	j = 0;

	int free_space = 0;
	int wall = 0;
	int collectible = 0;
	int exit = 0;
	int player = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				free_space++;
			else if (map[i][j] == '1')
				wall++;
			else if (map[i][j] == 'C')
				collectible++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				player++;
			else
				break ;
			j++;
		}
		i++;
	}
	printf("Row count : %d\n", i);
	printf("Column count : %d\n", j);
	close(fd);
	return (0);
}