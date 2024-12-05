/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rng <rng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:31 by rng               #+#    #+#             */
/*   Updated: 2024/12/05 15:27:38 by rng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180);
}

double	rad_to_deg(double rad)
{
	return (rad * 180 / PI);
}

double	normalise_angle(double degree)
{
	if (degree < 0)
		degree += 360;
	else if (degree > 360)
		degree -= 360;
	return (degree);
}

void	print_error_and_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
