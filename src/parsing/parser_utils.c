/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:44:51 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 18:55:44 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_room *find_room_by_name(t_farm *farm, const char *name) {
    t_room *current;

    if (!farm || !name)
        return NULL;
    
    current = farm->rooms;
    while (current != NULL) {
        // 방 이름이 일치하면 해당 방의 포인터를 반환
        if (ft_strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

int is_only_digits(const char *s) {
    if (s == NULL || *s == '\0' || *s == '\n')
        return 0;
    
    while (*s && *s != '\n') {
        if (!ft_isdigit(*s))
            return 0;
        s++;
    }

    return (*s == '\0' || *s == '\n');
}

int has_dash(const char *s) {
    return ft_strchr(s, '-') ? 1 : 0;
}

int count_spaces(const char *s) {
    int count = 0;

    while (*s != '\0') {
        if (*s == ' ') count++;
        s++;
    }

    return count;
}

int count_tokens(char **tokens) {
    int count = 0;

    if (tokens == NULL)
        return 0;

    while (tokens[count] != NULL)
        count++;

    return count;
}