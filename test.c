/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:31:31 by jaehejun          #+#    #+#             */
/*   Updated: 2023/08/10 20:57:46 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	char	*line;
	char	*temp;
	int		i;
	if (argc != 2)
	{
		write(1, "Error : Invalid parameters\n", 27);
		exit (1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	
	if (fd == -1)
	{
		write(1, "Error : Invalid file\n", 21);
		exit (1);
	}

	i = -1;
	line = strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = ft_strjoin(temp, line);
	}
	printf("TEMP : %s\n", temp);
	map = ft_split(temp, '\n');
	printf("MAP : %s\n", map[0]);
	printf("MAP : %s\n", map[1]);
	printf("MAP : %s\n", map[2]);
	printf("MAP : %s\n", map[3]);
	printf("MAP : %p\n", map[4]);
	close(fd);
	return (0);
}