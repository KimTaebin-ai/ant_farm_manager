/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:54:52 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/08 11:26:34 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_path t_path;

typedef enum e_line_type {
    // for describe number_of_ants
    LINE_NUMBER,
    
    // Type for Classifier
    LINE_COMMAND_START,
    LINE_ROOM,
    
    LINE_COMMAND_END,
    LINE_LINK,
    
    // # is Comment
    LINE_COMMENT,

    // Type for Error
    LINE_EMPTY,
    LINE_COMMAND_UNKNOWN,    
    LINE_INVALID
} t_line_type;

typedef enum e_next_room_role {
    ROLE_NORMAL,
    ROLE_START,
    ROLE_END,
} t_next_room_role;

typedef struct s_link {
    struct s_room *to;
    struct s_link *next;

    // Edmonds-Karp 
    int capacity;
    int flow;
    struct s_link *reverse; // 역방향 edge
} t_link;

typedef struct s_room {
    char *name;
    int x;
    int y;
    int is_start;
    int is_end;
    t_link *links;
    struct s_room *next;

    // for BFS
    int visited;
    int distance;
    struct s_room *parent;
    int ant_id;

    // for Edmonds-Karp 
    int in_flow;
    t_link *parent_link;
} t_room;

typedef struct s_farm {
    int number_of_ants;
    t_room *rooms;
    int room_count;
    t_room *start;
    t_room *end;
    t_next_room_role next_room_role;

    // for Edmonds-Karp 
    t_path **paths;
    int path_count;
} t_farm;

typedef struct s_queue {
    t_room **data;
    int head;
    int tail;
    int size;
} t_queue;

typedef struct s_path {
    t_room **rooms;    // 경로 상의 방 배열
    int length;        // 경로 길이 (방 개수)
    int assigned_ants; // 이 경로에 할당된 개미 수 (나중에 쓸 것)
} t_path;

typedef struct s_ant {
    int id;
    t_path *path;
    int position;
} t_ant;

#endif