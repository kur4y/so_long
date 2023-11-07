/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:08:48 by tanota            #+#    #+#             */
/*   Updated: 2023/09/19 17:09:02 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_data *data)
{
	int	i;
	int	j;

	if (data->nb_line == data->nb_column)
		return (0);
	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->matrix[i][j] && data->matrix[i][j] != '\n')
			j++;
		if (j != data->nb_column)
			return (0);
		i++;
	}
	return (1);
}
