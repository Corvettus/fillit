/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:37:38 by tlynesse          #+#    #+#             */
/*   Updated: 2019/04/11 20:29:08 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TETRO_H
# define FT_TETRO_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1000
# define LIMIT 26

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_tetros
{
	t_vector		cell[4];
	int				count;
	int				position;
	struct s_tetros	*next;
	struct s_tetros *prev;
}					t_tetros;

char				*reading_map(char *filename);
int					ft_validator(char *filename, t_tetros **ft_figset);
t_tetros			*write_lst(char *str, int i);
void				ft_fill(t_tetros *figure, int numbers);
int					kostya(char *str);
int					counter(char *str);
char				*empty_map(int power);
char				*clear_tetramin(char *str, int number);

#endif
