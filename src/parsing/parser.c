/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:05:20 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/04 22:41:03 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "get_next_line.h"

/**
 * 
    get_next_line으로 라인 단위 읽기
    방, 링크 파싱
    자료구조에 저장
    에러 처리
*/

/**
  *
  * number_of_ants  개미 수
    the_rooms       방 정보
    ㄴ 이름 x좌표 y좌표
    the_links       연결 정보 
    ㄴ 0-4 방0과 방4가 연결되어있다는 의미
*/

/**
 * 입력 예시
    3
    ##start
    1 23 3
    2 16 7
    #comment
    3 16 3
    4 16 5
    5 9 3
    6 1 5
    7 4 8
    ##end
    0 9 5
    0-4
    0-6
    1-3
    4-3
    ... 
 * 
 */


/**
 * 
    LINE_NUMBER,            0
    LINE_COMMAND_START,     1
    LINE_ROOM,              2
    LINE_COMMAND_END,       3
    LINE_LINK,              4
    LINE_COMMENT,           5
    LINE_EMPTY,             6
    LINE_COMMAND_UNKNOWN,   7 
    LINE_INVALID            8
 */

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
    if (line[0] == '#') // # 으로 시작하면 그냥 주석
        return LINE_COMMENT;
    if (is_only_digits(line)) // number_of_ants
        return (LINE_NUMBER);
    if (has_dash(line)) // 0-0 형식이라면 링크
        return LINE_LINK;
    if (count_spaces(line) == 2)  // "name x y" 는 공백 2개
        return (LINE_ROOM);
    return LINE_INVALID; // 위 조건이 전부 아니라면 에러
}

void data_parse() {
    char    *line;
    
    // TODO stdin 입력하지 않았을 때의 예외처리 추가
    while ((line = get_next_line(0)) != NULL)
    {
        t_line_type type = classify_line(line);
        ft_printf("[%d] %s", type, line);
        free(line); // GNL 할당한 메모리 해제 필수
    }
}