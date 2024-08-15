/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:38:20 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 09:06:40 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_exit(void *ptr)
{
	if (!ptr)
		exit(1);
}

void	check_fd(int fd)
{
	if (fd == -1)
		exit (1);
}

void	check_arg(int arg, char *name, int *fd)
{
	if (arg == 2 && is_dotber(name))
		*fd = open(name, O_RDONLY);
	else
		ft_exit("Parametre invalide\n", 1);
}
