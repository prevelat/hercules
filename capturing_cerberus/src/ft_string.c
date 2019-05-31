/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:55:51 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:55:52 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cerberus.h"

static size_t	ft_strdupsz(char **dest, const char *s)
{
	size_t	res;
	char	*p;

	res = ft_strlen(s);
	*dest = malloc(sizeof(**dest) * (res + 1));
	p = *dest;
	while ((*p++ = *s++))
		;
	return (res);
}

t_string		*ft_string_new(const char *s)
{
	t_string *self;

	self = malloc(sizeof(*self));
	if (s)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		self->length = 0;
		self->data = NULL;
	}
	self->append = &ft_string_append;
	self->destroy = &ft_string_destroy;
	return (self);
}

void			ft_string_prepend(t_string *self, const char *s)
{
	ssize_t tmp;
	char	*old;

	if (self->data == NULL)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		tmp = ft_strlen(s);
		old = self->data;
		self->data = malloc(self->length + tmp + 1);
		self->data[0] = 0;
		ft_strcat(self->data, s);
		ft_strcat(self->data, old);
		self->length += tmp;
		self->data[self->length] = 0;
		ft_strdel(&old);
	}
}

void			ft_string_append(t_string *self, const char *s)
{
	ssize_t tmp;

	if (self->data == NULL)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		tmp = ft_strlen(s);
		self->data = ft_reallocsz(
			self->data, self->length, self->length + tmp + 1);
		self->length += tmp;
		self->data[self->length] = 0;
		while (tmp >= 0)
			self->data[self->length - tmp--] = *s++;
	}
}

void			ft_string_destroy(t_string **self)
{
	ft_strdel(&(*self)->data);
	free(*self);
	*self = NULL;
}
