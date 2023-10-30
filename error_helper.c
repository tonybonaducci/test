/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:24 by rmenezes          #+#    #+#             */
/*   Updated: 2023/10/30 15:45:37 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(void)
{
	putstr_fd(ERROR_MESSAGE, 1);
	exit(EXIT_FAILURE);
}
