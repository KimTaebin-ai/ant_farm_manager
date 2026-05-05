/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:52:43 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:33:57 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include <stdlib.h>
#include "struct.h"

void free_tokens(char **tokens);
void free_links(t_link *links);
void free_rooms(t_room *rooms);
void free_farm(t_farm *farm);
void error_exit(t_farm *farm);

int validate_farm(t_farm *farm);

#endif