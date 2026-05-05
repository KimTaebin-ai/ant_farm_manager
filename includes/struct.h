/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:54:52 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/05 15:02:05 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
} t_link;

typedef struct s_room {
    char *name;
    int x;
    int y;
    int is_start;
    int is_end;
    t_link *links;
    struct s_room *next;
} t_room;

typedef struct s_farm {
    int number_of_ants;
    t_room *rooms;
    int room_count;
    t_room *start;
    t_room *end;
    t_next_room_role next_room_role;
} t_farm;


#endif