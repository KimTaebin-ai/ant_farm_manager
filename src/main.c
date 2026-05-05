/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:18:58 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 19:45:56 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 허용 함수
 * malloc, free
 * read, write
 * strerror, perror
 * exit
 */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "struct.h"
#include "parser.h"
#include "init.h"
#include "error_handler.h"
#include "algorithms.h"
#include "debug.h"

int main() {
    /*  
        Phase 1: 입력 파싱
        ├─ get_next_line으로 라인 단위 읽기
        ├─ 방, 링크 파싱
        ├─ 자료구조에 저장
        └─ 에러 처리

        Phase 2: 그래프 자료구조
        ├─ Adjacency list 구축
        ├─ 방 이름 → 포인터 hash
        └─ 입력 그대로 echo back (출력 형식 맞추기)

        Phase 3: BFS 구현
        ├─ 단일 최단 경로 찾기
        └─ 단순한 케이스 (Example 1, 2.1) 해결

        Phase 4: Multi-path 알고리즘
        ├─ Edmonds-Karp 또는 Suurballe 변형
        ├─ Vertex-disjoint paths 추출
        └─ Example 2.2, 3 해결

        Phase 5: 개미 분배
        ├─ 최적 분배 로직
        └─ 시뮬레이션 및 출력

        Phase 6: 최적화 + 에러 처리
        ├─ 4000개 방 시간 내 처리
        ├─ 메모리 누수 체크 (valgrind)
        └─ 엣지 케이스 처리
    */

    /*
        L1-2
        L1-3 L2-2
        L1-1 L2-3 L3-2
        L2-1 L3-3
        L3-1

        턴 1: L1-2              ← 1번 개미가 방 2로
        턴 2: L1-3  L2-2        ← 1번이 3으로, 2번이 2로
        턴 3: L1-1  L2-3  L3-2  ← 1번이 1(end)로, 2번이 3, 3번이 2
        턴 4: L2-1  L3-3        ← 1번은 도착했으니 빠짐
        턴 5: L3-1
    */
   
    t_farm *farm;
    t_path  *path;

    farm = init_farm();

    if (!farm)
        return 1;
    data_parse(farm);
    // 디버깅용 출력
    // print_queue_for_debug(farm);

    if (!bfs(farm)) {
        free_farm(farm);
        return 1;
    }

    path = extract_path(farm);
    if (!path) {
        free_farm(farm);
        return 1;
    }

    run_ant_simulation(farm, path);

    free_path(path);
    free_farm(farm);
    return 0;
}