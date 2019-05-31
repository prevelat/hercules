/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:18:11 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:53:57 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	res = malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
