/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toberemoved.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:26:14 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/03 13:18:57 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "execution.h"

char	*handle_lstatus_var(void)
{
	return (ft_itoa(get_status()));
}
