/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:18:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/21 15:28:29 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readstatic(ssize_t *bytesread, int fd, char **tmp, char **sbuff)
{
	*bytesread = read(fd, *tmp, BUFFER_SIZE);
	if (*bytesread <= 0)
	{
		free(*tmp);
		if (*bytesread == 0)
			return ;
		free(*sbuff);
		*sbuff = NULL;
		return ;
	}
}

void	read_join(int fd, char **sbuff)
{
	char	*tmp;
	char	*tmp2;
	ssize_t	bytesread;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(*sbuff);
		*sbuff = NULL;
		return ;
	}
	bytesread = 1;
	while (bytesread > 0 && ft_strlen_gnl(*sbuff, '\n') == -1)
	{
		readstatic(&bytesread, fd, &tmp, sbuff);
		if (bytesread <= 0)
			return ;
		tmp[bytesread] = '\0';
		tmp2 = *sbuff;
		*sbuff = ft_strjoin_gnl(*sbuff, tmp);
		free(tmp2);
	}
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*sbuff;
	char		*line;
	char		*tmp2;
	ssize_t		num;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(sbuff), sbuff = NULL, NULL);
	if (ft_strlen_gnl(sbuff, '\n') == -1)
		read_join(fd, &sbuff);
	line = ft_substr_gnl(sbuff, 0, ft_gnl_strlen2(sbuff, '\n') + 1);
	if (!line)
		return (free(line), free(sbuff), sbuff = NULL, NULL);
	tmp2 = sbuff;
	num = ft_gnl_strlen2(sbuff, '\n') + 1;
	sbuff = ft_substr_gnl(sbuff, num, ft_gnl_strlen2(sbuff, '\0'));
	free(tmp2);
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int fd = open("file.txt", O_RDWR);
// 	if (fd < 0)
// 		exit(1);
// 	int i= 0;
// 	char *str;
// 	while (i < 10)
// 	{
// 		str = get_next_line(fd);
// 		printf("->%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
