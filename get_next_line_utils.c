/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryl <maryl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:05:22 by maryl             #+#    #+#             */
/*   Updated: 2026/09/30 01:50:58 by maryl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;
    
    if (!str)
        return(0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int has_newline(const char *str)
{
    size_t  i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    join(const char *stash, const char *buffer)
{
    char    *new_stash;
    size_t  full_len;
    size_t  i;
    size_t  y;

    if (!buffer)
		return (NULL);
    new_stash = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
    if (!new_stash)
        return (NULL);
    i = 0;
    y = 0;
    if (stash)
    {
        while (stash[i])
        {
            new_stash[i] = stash[i];
            i++;
        }
    }
    while (buffer[y])
        new_stash[i++] = buffer[y++];
    new_stash[i] = '\0';
    return (new_stash);
}
char    *split_to_return(const char *stash)
{
    char    *line;
    size_t  i;
    size_t  j;

    if (!stash || !stash[0])
        return (NULL);
    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    while (j < i)
    {
        line[j] = stash[j];
        j++;
    }
    line[i] = '\0';
    return (line);
}

char    *update_stash(const char *old_stash)
{
    char    *new_stash;
    size_t  i;
    size_t  j;

    if (!old_stash)
        return (NULL);
    i = 0;
    while (old_stash[i] && old_stash[i] != '\n')
        i++;
    if (old_stash[i] == '\0' || !old_stash[i + 1])
        return (free(old_stash), NULL);//if no reminder
    i++;
    new_stash = malloc(ft_strlen(old_stash + i) + 1);
    if (!new_stash)
        return (free(old_stash), NULL);//if bad malloc
    j = 0;
    while (old_stash[i])
        new_stash[j++] = old_stash[i++];
    new_stash[j] = '\0';
    free(old_stash);
    return (new_stash);
}
