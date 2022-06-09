#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
    size_t    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char	*ft_strchr(char *s, int c)
{
    size_t    i;

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
    char    *result;
    size_t    i;
    size_t    j;

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

char	*strcfln(char *work)
/*
** String clear first line
** Take a string, creates a new string ignoring the first line inside it freeing
** the string passed and returning the new string.
 */
{
	char	*final;

	if(!work)
		return NULL;
	final = ft_substr(work, strfnl(work), ft_strlen(work));
	if(!final)
		return NULL;
	free(work);
	return (final);
}
