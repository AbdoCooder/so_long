/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:19:02 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/24 12:21:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen_gnl(const char *s, char c)
{
	ssize_t	count;

	if (!s)
		return (-1);
	count = 0;
	while (s[count] && s[count] != c)
		count++;
	if (s[count] == c)
		return (count);
	return (-1);
}

ssize_t	ft_gnl_strlen2(const char *s, char c)
{
	ssize_t	count;

	if (!s)
		return (-1);
	count = 0;
	while (s[count] && s[count] != c)
		count++;
	if (s[count] == c)
		return (count);
	return (count - 1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup_gnl(s2));
	if (s1 && !s2)
		return (ft_strdup_gnl(s1));
	i = 0;
	j = 0;
	str = malloc(ft_strlen_gnl(s1, '\0') + ft_strlen_gnl(s2, '\0') + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_gnl_strlen2(s, '\0');
	if (start >= s_len)
		return (NULL);
	i = 0;
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start])
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup_gnl(const char *src)
{
	int		slen;
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	slen = 0;
	while (src[slen])
		slen++;
	dest = (char *)malloc(sizeof(char) * slen + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
