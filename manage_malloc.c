/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:38:20 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 13:59:55 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_protect_dbptr(char **p)
{
	if (!p)
	{
		p = NULL;
		exit(1);
	}
}

void	malloc_protect(char ***p, int size)
{
	if (!(**p))
	{
		free_double(*p, size);
		**p = NULL;
		exit(1);
	}
}
