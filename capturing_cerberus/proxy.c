/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:58:21 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/22 12:18:52 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cerberus.h"

static int	create_proxy(const char *hostname)
{
	int				fd;
	int				port;
	char			*aux;
	struct hostent	*host;
	t_addr			addr;

	port = 80;
	if ((aux = ft_strchr(hostname, ':')) && ft_isdigit(*(aux + 1)))
		port = ft_atoi(aux + 1);
	if (!(host = gethostbyname(hostname)))
		return (E_NO_HOST);
	if ((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return (E_OUR);
	ft_bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	bcopy((char *)host->h_addr, (char *)&addr.sin_addr.s_addr, host->h_length);
	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0)
	{
		close(fd);
		return (E_CONNECT);
	}
	return (fd);
}

int			do_proxy(int client_fd, const char *hostname, const char *buff)
{
	int			proxy_fd;
	char		res_buff[1024];
	t_string	*str;
	int			n;

	if ((proxy_fd = create_proxy(hostname)) < 0)
		return (proxy_fd);
	send(proxy_fd, buff, ft_strlen(buff), 0);
	str = ft_string_new(NULL);
	ft_bzero(res_buff, sizeof(res_buff));
	while (1)
	{
		if ((n = read(proxy_fd, res_buff, sizeof(res_buff) - 1)) > 0)
			ft_string_append(str, res_buff);
		else
			break ;
		ft_bzero(res_buff, sizeof(res_buff));
		usleep(100);
	}
	write(client_fd, str->data, str->length);
	write(1, str->data, str->length);
	ft_string_destroy(&str);
	close(proxy_fd);
	return (0);
}
