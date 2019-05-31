/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:16:33 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:56:10 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	i;

	RETURN_VAL_IF_FAIL(NULL, (res = ft_memalloc(len + 1)));
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
