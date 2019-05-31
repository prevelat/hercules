#include "cerberus.h"

void					error(char *str)
{
	perror(str);
	exit(0);
}

int						main(int ac, char **ag)
{
	int					socket_fd;
	int					port;
	int					n;
	struct sockaddr_in	addr;
	struct hostent		*server;
	char				buffer[8196];
	t_string			*str;

	if (ac != 4)
	{
		fprintf(stderr, "usage %s hostname port file\n", ag[0]);
		exit(0);
	}
	ft_bzero(buffer, sizeof(buffer));
	ft_strcpy(buffer, ag[3]);
	port = atoi(ag[2]);
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		error("socket error");
	if (!(server = gethostbyname(ag[1])))
		error("host error");
	ft_bzero((char *)&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);
	addr.sin_port = htons(port);
	if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		error("connect error");
	if (send(socket_fd, buffer, ft_strlen(buffer), 0) < 0)
		error("send error");
	ft_bzero(buffer, sizeof(buffer));
	str = ft_string_new(NULL);
	fcntl(socket_fd, F_SETFL, fcntl(socket_fd, F_GETFL) | O_NONBLOCK);
	int first = 1;
	while (first == 1 || errno == EAGAIN || errno == EWOULDBLOCK)
	{
		printf("Here.\n");
		if ((n = recv(socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0)
			ft_string_append(str, buffer);
		else
			continue ;
		ft_bzero(buffer, sizeof(buffer));
		if (first == 1)
			first = 2;
		usleep(100);
	}
	printf("%d\n", n);
	printf(">> %s", str->data);
	ft_string_destroy(&str);
	close(socket_fd);
	return (0);
}
