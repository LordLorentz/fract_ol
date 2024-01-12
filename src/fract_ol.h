/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_ol.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:25:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 17:12:40 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# ifndef WIDTH
#  define WIDTH 256
# endif

# ifndef HEIGHT
#  define HEIGHT WIDTH
# endif

# define JUST 2.0 / WIDTH

# ifndef DEPTH
#  define DEPTH 32
# endif

# define ZOOM_CONST 0.98

# define FASTSCROLL 5

# define CHAR_2PI 40.5845104884

typedef struct s_complex {
	double	real;
	double	imgn;
}	t_complex;

typedef struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
}	t_rect;

typedef				uint32_t (t_occ)(t_complex, unsigned long, long);

typedef struct s_cam {
	t_occ	*occlusion;
	double	zoom;
	int		x_offset;
	int		y_offset;
}	t_cam;

typedef mlx_image_t	t_img;

typedef struct s_fractal {
	t_complex	c;
	uint32_t	(*get_color)(t_complex, t_occ *, struct s_fractal);
	double		symmetry;
	long		depth;
}	t_fractal;

typedef struct s_screenstate {
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_cam		camera;
	t_fractal	fractal;
}	t_screenstate;

////////////					I/O									////////////

void				output_state(t_screenstate state);
void				output_lock(t_screenstate state);

////////////					Controls							////////////

void				zoom_to_cursor(mlx_t *mlx, t_cam *cam, double direction);

int 				check_other(mlx_t *mlx, t_fractal *fractal, t_cam *camera);
int					check_qert(mlx_t *mlx, t_fractal *fractal);
int					check_wasd(mlx_t *mlx, t_fractal *fractal);
int					check_arrow_keys(mlx_t *mlx, t_cam *cam);

////////////					Rendering							////////////

void				draw_fract(t_img *img, t_cam cam, t_fractal fractal);

////////////					Fractals							////////////

uint32_t			gc_j_2(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_2(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_3(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_3(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_n(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_n(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_t(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_t(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_x(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_x(t_complex z, t_occ *occlusion, t_fractal fractal);

////////////					Occlusion modes						////////////

unsigned int		occ_cutoff(t_complex z, unsigned long i, long depth);
unsigned int		occ_sub(t_complex z, unsigned long i, long depth);
unsigned int		occ_angle(t_complex z, unsigned long i, long depth);

////////////					Hooks								////////////

void				ft_scroll_hook(double dx, double dy, void *param);
void				ft_resize_hook(int32_t width, int32_t height, void* param);
void				ft_loop_hook(void *param);

////////////					Error handling						////////////

void				ft_exit(int state, const char *function, int line);

#endif
