/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:41:13 by jasminelage       #+#    #+#             */
/*   Updated: 2024/11/16 20:43:50 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// for read() and open()
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}					t_list;
// next node of string

char				*get_next_line(int fd);
void				create_list(t_list **list, int fd);
char				*get_a_line(t_list *list);
void				polish_list(t_list **list);
int					found_newline(t_list *list);
void				append(t_list **list, char *buff);
int					length_to_newline(t_list *list);
void				copy_str(t_list *list, char *str);
t_list				*find_last_node(t_list *list);
void				dealloc(t_list **list, t_list *clean_node, char *buff);

#endif
