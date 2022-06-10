/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:42:11 by lguedes           #+#    #+#             */
/*   Updated: 2022/06/10 17:42:19 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*work;
	char		*result;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	work = read_fl(fd, work);
	if (!work)
		return (NULL);
	result = strgln(work);
	work = strgal(work);
	if(!ft_strlen(result))
	{
		free(work);
		free(result);
		return (NULL);
	}
	return (result);
}

char	*read_fl(int fd, char *work)
{
	int		rbamount;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rbamount = 1;
	while (!ft_strchr(work, '\n') && rbamount != 0)
	{
		rbamount = read(fd, buff, BUFFER_SIZE);
		if (rbamount == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rbamount] = '\0';
		work = ft_strjoin(work, buff);
	}
	free(buff);
	return (work);
}
