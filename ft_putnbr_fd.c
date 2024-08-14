/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:14:49 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 11:44:42 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	count_digit(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	pow_ten(int len)
{
	if (len == 0)
		return (1);
	else
		return (10 * pow_ten(len - 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len_int;
	char	c;

	len_int = count_digit(n);
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		while (len_int)
		{
			c = (n / pow_ten(len_int - 1)) + '0';
			write(fd, &c, 1);
			n %= pow_ten(len_int - 1);
			len_int--;
		}
	}
}
