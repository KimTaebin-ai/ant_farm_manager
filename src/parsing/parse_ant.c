/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:39:58 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 15:05:04 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "ft_printf.h"

void parse_number_of_ants(const char *data, t_farm *farm) {
    int count = ft_atoi(data);
    
    if (count <= 0)
        exit(1);
        
    farm->number_of_ants = count;
}