/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocsz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:15:08 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:54:28 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

void	*ft_reallocsz(void *ptr, size_t len, size_t new_len)
{
	void *res;

	RETURN_VAL_IF_FAIL(ptr, (len != new_len));
	if (!new_len)
	{
		if (ptr)
			ft_memdel(&ptr);
		return (NULL);
	}
	if (!(res = malloc(new_len)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(res, ptr, (new_len < len) ? new_len : len);
		ft_memdel(&ptr);
	}
	return (res);
}
