/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:46:42 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:55:40 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

char	*ft_strdupchr(const char *str, char c)
{
	char *res;
	char *tmp;

	RETURN_VAL_IF_FAIL(NULL, str);
	if (!(tmp = ft_strchr(str, c)))
		return (ft_strdup(str));
	res = ft_strndup(str, tmp - str);
	return (res);
}
