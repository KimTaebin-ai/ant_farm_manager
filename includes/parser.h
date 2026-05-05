/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:35:41 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 14:48:31 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <fcntl.h>
#include "struct.h"

// debug
void print_room_list_for_debug(t_farm *farm);
void print_room_link_for_debug(t_farm *farm);

void data_parse(t_farm *farm);

// util functions for parsing
int is_only_digits(const char *s);
int has_dash(const char *s);
int count_spaces(const char *s);
int count_tokens(char **tokens);

// function for ant counting
void parse_number_of_ants(const char *data, t_farm *farm);

// function for add rooms info
t_room *parse_add_room(const char *data, t_farm *farm);
t_room *create_room(const char *name, int x, int y);

// function for add relation of room
void parse_link_line(const char *data, t_farm *farm);

#endif