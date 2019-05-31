/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:04:57 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:52:48 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

int	ft_atoi(const char *str)
{
	char				*p;
	int					mult;
	unsigned long long	res;

	mult = 0;
	res = 0;
	p = (char *)str;
	while (IS_WHITESPACE(*p))
		p++;
	mult = (*p == '-' && (p++ || 1)) ? -1 : mult;
	mult = ((*p == '+' && !mult && (p++ || 1)) || !mult) ? 1 : mult;
	while (*p >= '0' && *p <= '9' && res <= 9223372036854775807)
		res = (res * 10) + (*p++ - '0');
	if (res > 9223372036854775807)
		return ((mult == -1) ? 0 : -1);
	return (res * mult);
}
