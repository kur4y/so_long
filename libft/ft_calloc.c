/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:08:48 by tanota            #+#    #+#             */
/*   Updated: 2023/09/19 17:09:37 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t x, size_t y)
{
	unsigned char	*str;

	if (y > 0 && x * y / y != x)
		return (0);
	str = malloc(x * y);
	if (!str)
		return (0);
	ft_bzero(str, x * y);
	return (str);
}
