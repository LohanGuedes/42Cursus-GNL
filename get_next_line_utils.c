/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:31:11 by lguedes           #+#    #+#             */
/*   Updated: 2022/06/10 17:39:43 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0);
}

char	*ft_strjoin(char *work_str, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!work_str)
	{
		work_str = malloc(1 * sizeof(char));
		work_str[0] = '\0';
	}
	if (!work_str || !buff)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(work_str) + ft_strlen(buff) + 1));
	if (!result)
		return (NULL);
	i = -1;
	if (work_str)
		while (work_str[++i])
			result[i] = work_str[i];
	j = 0;
	while (buff[j])
		result[i++] = buff[j++];
	result[ft_strlen(work_str) + ft_strlen(buff)] = '\0';
	free(work_str);
	return (result);
}

char	*strgln(char *work)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!work)
		return (NULL);
	while (work[i] && work[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (work[i] && work[i] != '\n')
	{
		result[i] = work[i];
		i++;
	}
	if (work[i] == '\n')
	{
		result[i] = work[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*strgal(char *work)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	while (work[i] && work[i] != '\n')
		i++;
	if (!work[i])
	{
		free(work);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(work) - i + 1));
	if (!result)
		return (NULL);
	j = 0;
	i++;
	while (work[i])
		result[j++] = work[i++];
	result[j] = '\0';
	free(work);
	return (result);
}
