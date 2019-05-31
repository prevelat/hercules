/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cerberus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprevela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:49:25 by fprevela          #+#    #+#             */
/*   Updated: 2019/05/22 12:29:34 by fprevela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CERBERUS_H
# define CERBERUS_H

# include <sys/types.h>
# include <stdio.h>
# include <netdb.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <netinet/in.h>
# include <sys/socket.h>

# define PORT 5555
# define _IW2(x)			(x == '\r' || x == '\v' || x == '\f')
# define IS_WHITESPACE(x)	(x == ' ' || x == '\t' || x == '\n' || _IW2(x))
# define RETURN_IF_FAIL(x)			({ if (!x) return ; })
# define RETURN_VAL_IF_FAIL(x, y)	({ if (!y) return (x); })
# define _S_SADDRIN struct sockaddr_in

enum					e_errors
{
	E_START,
	E_TIMEOUT = -1,
	E_NO_RESPONSE = -2,
	E_NO_HOST = -3,
	E_OUR = -4,
	E_CONNECT = -5,
	E_INVALID_REQUEST = -6,
	E_CLIENT_CONNECT = -7,
	E_FORK = -8,
	E_PROXY_FD = -9
};

typedef _S_SADDRIN		t_addr;

typedef struct			s_string
{
	char				*data;
	size_t				length;
	void				(*append)(struct s_string *self, const char *s);
	void				(*destroy)(struct s_string **self);
}						t_string;

typedef struct			s_socket
{
	int					fd;
	t_addr				address;
}						t_socket;

int						do_proxy(int client_fd, const char *hostname,
									const char *buff);
int						init_server(t_socket **r_server);
void					handle_client(int client_fd);
void					ft_memdel(void **ap);
t_socket				*ft_socket_new(void);
t_socket				*ft_socket_new_with_port(int port);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strdup(const char *s);
char					*ft_strdupchr(const char *str, char c);
void					ft_strdel(char **as);
void					ft_bzero(void *s, size_t n);
t_string				*ft_string_new(const char *s);
void					ft_string_append(t_string *self, const char *s);
void					ft_string_destroy(t_string **self);
void					ft_string_prepend(t_string *self, const char *s);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);
char					*ft_strnew(size_t size);
char					*ft_strndup(const char *s, size_t len);
char					*ft_strchr(const char *s, int c);
void					*ft_reallocsz(void *ptr, size_t len, size_t new_len);
char					*ft_strcat(char *dest, const char *src);
int						ft_strcmp(const char *s1, const char *s2);
void					*ft_memalloc(size_t size);
void					*ft_memcpy(void *dest, const void *src, size_t n);
char					*ft_strcpy(char *dst, const char *src);

#endif
