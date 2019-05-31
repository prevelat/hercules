/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:18:29 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:54:07 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = dest;
	s = src;
	while (n-- > 0)
		*p++ = *s++;
	return (dest);
}
