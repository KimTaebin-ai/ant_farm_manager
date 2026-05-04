/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:44:51 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/04 22:36:28 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

// TODO 관련 에러 처리 전체 필요

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