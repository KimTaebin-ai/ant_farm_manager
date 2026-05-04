/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:18:58 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/04 22:40:37 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 허용 함수
 * malloc, free
 * read, write
 * strerror, perror
 * exit
 */

#include "main.h"

int main() {
    /**
     *  Phase 1: 입력 파싱
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
    data_parse();


    return 0;
}