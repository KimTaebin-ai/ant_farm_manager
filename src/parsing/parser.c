/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:05:20 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 15:55:33 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "struct.h"
#include "error.h"
#include "get_next_line.h"
#include "libft.h"

t_line_type classify_line(const char *line) {
    if (line[0] == '\n' || line[0] == '\0' || !line[0])
        return LINE_EMPTY;
    if (line[0] == '#' && line[1] == '#') { // start 랑 end 라면 정상적인 명령어
        if (ft_strcmp(line, "##start") == 0)
            return LINE_COMMAND_START;
        if (ft_strcmp(line, "##end") == 0)
            return LINE_COMMAND_END;
        return LINE_COMMAND_UNKNOWN;
    }
    if (line[0] == '#')             // # 으로 시작하면 그냥 주석
        return LINE_COMMENT;
    if (is_only_digits(line))       // number_of_ants
        return (LINE_NUMBER);
    if (has_dash(line))             // 0-0 형식이라면 링크
        return LINE_LINK;
    if (count_spaces(line) == 2)    // "name x y" 는 공백 2개
        return (LINE_ROOM);
    return LINE_INVALID;            // 위 조건이 전부 아니라면 에러
}

void main_process_by_type(t_farm *farm, const char *line, t_line_type type) {
    switch (type) {
        case LINE_NUMBER:
            parse_number_of_ants(line, farm);
            break;
        case LINE_COMMAND_START:
            if (farm->next_room_role != ROLE_NORMAL || farm->start)
                error_exit(farm);
            farm->next_room_role = ROLE_START;
            break;
        case LINE_COMMAND_END:
            if (farm->next_room_role != ROLE_NORMAL || farm->end)
                error_exit(farm);
            farm->next_room_role = ROLE_END;
            break;
        case LINE_ROOM: {
            t_room *room = parse_add_room(line, farm);
            
            if (!room)
                error_exit(farm);
            
            if (farm->next_room_role == ROLE_START) {
                room->is_start = 1;
                farm->start = room;
            } else if (farm->next_room_role == ROLE_END) {
                room->is_end = 1;
                farm->end = room;
            }
            
            farm->next_room_role = ROLE_NORMAL;
            break;
        }
        case LINE_LINK:
            parse_link_line(line, farm);
            break;
        default:
            break;
    }
}

#include "ft_printf.h"

void data_parse(t_farm *farm) {
    char    *line;
    // TODO stdin 입력하지 않았을 때의 예외처리 추가
    while ((line = get_next_line(0)) != NULL) {
        size_t len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        t_line_type type = classify_line(line);
        // ft_printf("[%d] %s", type, line);

        if (type == LINE_EMPTY || type == LINE_INVALID) {
            free(line);
            break;  // 입력 종료
        }
        
        main_process_by_type(farm, line, type);

        free(line); // GNL 할당한 메모리 해제 필수
    }

    // 디버깅용 출력
    print_room_list_for_debug(farm);
    print_room_link_for_debug(farm);
}