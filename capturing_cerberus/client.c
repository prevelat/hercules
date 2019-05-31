/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:49:47 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/18 18:58:31 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cerberus.h"

int			validate_request(const char *buff, char **hostname)
{
	char	*tmp;

	printf("REQUEST:\n%s\n", buff);
	if ((tmp = ft_strstr(buff, "Host: ")) == NULL)
		return (E_INVALID_REQUEST);
	tmp += 6;
	while (IS_WHITESPACE(*tmp))
		tmp++;
	if (!*tmp)
		return (E_INVALID_REQUEST);
	*hostname = ft_strdupchr(tmp, '\n');
	return (0);
}

/*
** The function handle_client runs in a thread, the exit(0) at the end prevents
** the thread from going back to the main loop.
*/

void		handle_client(int client_fd)
{
	char	buff[8193];
	int		aux;
	char	*hostname;
	char	*error;

	error = NULL;
	hostname = NULL;
	fcntl(client_fd, F_SETFL, fcntl(client_fd, F_GETFL) | O_NONBLOCK);
	ft_bzero(buff, 8193);
	if ((aux = read(client_fd, buff, 8192)) < 0)
		error = ft_strdup("No read from client.");
	else if ((aux = validate_request(buff, &hostname)) < 0)
		error = ft_strdup("Invalid request.");
	else if ((aux = do_proxy(client_fd, hostname, buff)) < 0)
		error = ft_strdup("Duck duck error.");
	if (error)
	{
		send(client_fd, error, ft_strlen(error), 0);
		printf("Error: %s\n", error);
	}
	ft_strdel(&error);
	ft_strdel(&hostname);
	exit(0);
}
