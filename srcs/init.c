/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:08:48 by tanota            #+#    #+#             */
/*   Updated: 2023/09/19 17:09:04 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->steps_count = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->matrix[i][j] && data->matrix[i][j] != '\n')
		{
			if (data->matrix[i][j] == 'P')
			{
				data->p_j = j;
				data->p_i = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	img_init(t_data *data)
{
	data->img_floor = mlx_xpm_file_to_image(data->mlx, \
	"images/floor.xpm", &data->width, &data->height);
	if (data->img_floor == 0)
		return (0);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, \
	"images/wall.xpm", &data->width, &data->height);
	if (data->img_wall == 0)
		return (0);
	data->img_consumable = mlx_xpm_file_to_image(data->mlx, \
	"images/consumable.xpm", &data->width, &data->height);
	if (data->img_consumable == 0)
		return (0);
	data->img_player = mlx_xpm_file_to_image(data->mlx, \
	"images/player1.xpm", &data->width, &data->height);
	if (data->img_player == 0)
		return (0);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, \
	"images/exit.xpm", &data->width, &data->height);
	if (data->img_exit == 0)
		return (0);
	return (1);
}

int	put_value_in_data(t_data *data, char *map_path)
{
	data->matrix = ft_create_matrix(data, map_path);
	if (data->matrix == 0)
		return (ft_putendl_fd("Error\nNot valid file", 2), \
		free(data->center), free(data), 0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_matrix(data->matrix, data->nb_line), free(data->center),
			free(data), ft_putendl_fd("Error\nInvalid path", 2), 0);
	ft_init_data(data);
	if (!img_init(data))
		return (ft_putendl_fd("Error\nImage not valid", 2), free_all(data), 0);
	get_max_column(data);
	if (data->nb_column == data->nb_line)
		return (ft_putendl_fd("Error\nMap not rectangle", 2), free_all(data), 0);
	player_data(data);
	return (1);
}

int	malloc_data_center(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->center = malloc(sizeof(t_center));
	if (!(*data)->center)
		return (free((*data)), 0);
	(*data)->center->idx_down = 0;
	(*data)->center->idx_up = 0;
	(*data)->center->idx_left = 0;
	(*data)->center->idx_right = 0;
	return (1);
}

void	*ft_create_img(t_data *data, char c)
{
	if (c == '0' || c == 'P')
		return (data->img_floor);
	else if (c == '1')
		return (data->img_wall);
	else if (c == 'C')
		return (data->img_consumable);
	else if (c == 'E')
		return (data->img_exit);
	ft_putendl_fd("Error\nNot a 0 1 C P or E", 2);
	return (NULL);
}
