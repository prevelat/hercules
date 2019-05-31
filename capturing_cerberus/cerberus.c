/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cerberus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:48:27 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 19:04:24 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cerberus.h"

int		server_loop(t_socket *server)
{
	int			client_fd;
	int			fres;

	while (1)
	{
		if ((client_fd = accept(server->fd, NULL, NULL)) < 0)
		{
			if (errno != EWOULDBLOCK)
				return (E_CLIENT_CONNECT);
			sleep(1);
			continue ;
		}
		printf("New request.\n");
		fres = fork();
		if (fres == -1)
			return (E_FORK);
		else if (fres == 0)
			handle_client(client_fd);
	}
	return (0);
}

int		init_server(t_socket **r_server)
{
	t_socket	*server;
	int			op;

	op = 1;
	server = ft_socket_new_with_port(PORT);
	if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op)) != 0)
	{
		printf("setsocket error.\n");
		return (E_OUR);
	}
	fcntl(server->fd, F_SETFL, fcntl(server->fd, F_GETFL) | O_NONBLOCK);
	if (bind(server->fd, (const struct sockaddr *)&server->address,
		sizeof(server->address)) < 0)
	{
		printf("Bind error.\n");
		return (E_OUR);
	}
	if (listen(server->fd, 8) < 0)
	{
		printf("Listen error.\n");
		return (E_OUR);
	}
	*r_server = server;
	return (0);
}

int		main(void)
{
	t_socket	*server;
	int			res;

	if ((res = init_server(&server)) != 0)
	{
		printf("Proxy start error %d\n", res);
		return (res);
	}
	printf("Proxy running.\n");
	res = server_loop(server);
	close(server->fd);
	ft_memdel((void **)&server);
	return (res);
}
