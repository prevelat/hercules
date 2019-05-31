/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:56:27 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:56:29 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tok;
	char *ned;

	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	ned = (char *)needle;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tok = (char *)haystack;
			while (*tok == *ned && *tok && *ned)
			{
				tok++;
				ned++;
			}
			if (!*ned)
				return ((char *)haystack);
			ned = (char *)needle;
		}
		haystack++;
	}
	return (NULL);
}
