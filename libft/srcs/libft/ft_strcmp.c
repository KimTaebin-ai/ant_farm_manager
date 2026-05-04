/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:07:28 by taebkim           #+#    #+#             */
/*   Updated: 2026/05/04 22:38:28 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2) {
    unsigned char *_s1 = (unsigned char *)s1;
    unsigned char *_s2 = (unsigned char *)s2;

    while (*_s1 && *_s1 != '\n' && (*_s1 == *_s2)) {
        _s1++;
        _s2++;
    }

    if (*_s1 == '\n' && *_s2 == '\0')
        return (0);

    return (*_s1 - *_s2);
}