/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:44:51 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 16:33:41 by taebkim          ###   ########.fr       */
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

#include "ft_printf.h"

void print_room_list_for_debug(t_farm *farm) {
    ft_printf("count: %d\n", farm->number_of_ants);

    t_room *current;

    if (!farm || !farm->rooms)
        ft_printf("출력할 수 있는 방 없음\n");
    
    current = farm->rooms;

    while (current != NULL) {
        ft_printf("%s: (%d, %d)\n", current->name, current->x, current->y);
        current = current->next;
    }
}

void print_room_link_for_debug(t_farm *farm) {
    t_room *curr_room;
    t_link *curr_link;

    if (!farm || !farm->rooms) {
        ft_printf("출력할 연결 정보 없음\n");
        return;
    }

    curr_room = farm->rooms;
    while (curr_room != NULL) {
        ft_printf("Room [%s] 연결된 엣지: ", curr_room->name);
        
        curr_link = curr_room->links;
        if (curr_link == NULL) {
            ft_printf("없음");
        } else {
            while (curr_link != NULL) {
                // curr_link->to는 연결된 상대방 t_room의 포인터
                ft_printf("%s", curr_link->to->name);
                
                curr_link = curr_link->next;
                if (curr_link != NULL)
                    ft_printf(", "); // 다음 연결이 있으면 쉼표 표시
            }
        }
        ft_printf("\n");
        curr_room = curr_room->next;
    }
}