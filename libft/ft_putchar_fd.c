/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:20:54 by jlager            #+#    #+#             */
/*   Updated: 2024/10/05 19:39:37 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// writes a char c to a file descriptor

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}