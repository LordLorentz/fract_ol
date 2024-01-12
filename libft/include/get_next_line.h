/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:07:55 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/11 14:11:18 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define BFSZ BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dict
{
	struct s_dict	*nxt;
	void			*cnt;
	int				ndx;
}	t_dict;

char	*get_next_line(int fd);

#endif
