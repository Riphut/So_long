/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:07:18 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 17:15:14 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Get next line utils */
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dest == NULL)
		return (0);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, size_t len)
{
	size_t	i;
	char	*fl;

	i = -1;
	if (!s || len == 0)
		return (NULL);
	fl = malloc(sizeof(char) * (len + 1));
	if (!fl)
		return (NULL);
	while (++i < len)
		fl[i] = s[i];
	fl[i] = '\0';
	return (fl);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*combo;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	combo = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!combo)
		return (NULL);
	while (s1[++i])
		combo[i] = s1[i];
	while (s2[j])
		combo[i++] = s2[j++];
	combo[i] = '\0';
	return (free((void *)s1), combo);
}
