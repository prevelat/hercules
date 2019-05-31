/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:46:24 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:55:26 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*p;
	size_t	l;

	l = ft_strlen(s);
	RETURN_VAL_IF_FAIL(NULL, (res = ft_strnew(l)));
	p = res;
	while ((*p++ = *s++))
		;
	return (res);
}
