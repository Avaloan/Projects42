/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 01:38:28 by snedir            #+#    #+#             */
/*   Updated: 2017/08/31 03:43:51 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "./gnl/libft/get_next_line.h"
# include <stdio.h>
# define MLX fdf->mlx
# define WIN fdf->win
# define IMG fdf->img
# define SL fdf->sl
# define BPP fdf->bpp
# define ZOOM fdf->zoom
# define IMG_PTR fdf->img_ptr
# define ZOOM fdf->zoom
# define END fdf->end

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*img;
	int			*sl;
	int			bpp;
	int			end;
	int			zoom;
}				t_fdf;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				straight;
}					t_map;

#endif
