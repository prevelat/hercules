/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:54:44 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:54:47 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *p;

	p = dest;
	while (*p)
		p++;
	while ((*p++ = *src++))
		;
	return (dest);
}