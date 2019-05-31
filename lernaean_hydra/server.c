/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:43:15 by fprevela          #+#    #+#             */
/*   Updated: 2019/03/09 20:18:51 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>

void					error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int						reply(int accept_fd, int n)
{
	char				buffer[256];

	bzero(buffer, 256);
	if (read(accept_fd, buffer, 255) < 0)
		error("read failed");
	if (n == 0)
		printf("Incoming msg: %s", buffer);
	if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "close", 5) == 0)
	{
		write(accept_fd, "Connection terminated.", 22);
		return (1);
	}
	if (strncmp(buffer, "ping", 4) == 0)
	{
		if (write(accept_fd, "pong pong", 9) < 0)
			error("write failed");
	}
	else if (write(accept_fd, "The answer is 42.", 17) < 0)
		error("write error");
	return (0);
}

int						server(char *argv, int n)
{
	int					server_fd;
	int					accept_fd;
	int					addr_len;
	struct sockaddr_in	address;

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0)
		error("socket failed");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(atoi(argv));
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
		error("bind failed");
	if (listen(server_fd, 5) < 0)
		error("listen failed");
	addr_len = sizeof(address);
	while (1)
	{
		if ((accept_fd = accept(server_fd, (struct sockaddr *)&address,
						(socklen_t *)&(addr_len))) < 0)
			error("accept failed");
		if (reply(accept_fd, n) == 1)
			exit(1);
	}
	return (0);
}

int						main(int argc, char **argv)
{
	pid_t				p_id;
	pid_t				s_id;

	if (argc == 3 && strcmp(argv[1], "-D") == 0)
	{
		if ((p_id = fork()) < 0)
			error("fork failed");
		if (p_id > 0)
			exit(EXIT_SUCCESS);
		umask(0);
		if ((s_id = setsid()) < 0)
			error("setsid failed");
		return (server(argv[2], 1));
	}
	else if (argc == 2)
		return (server(argv[1], 0));
	else
	{
		printf("%s", "Usage: ./server [-D] port\n");
		exit(1);
	}
	return (0);
}
