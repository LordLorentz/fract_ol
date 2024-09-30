/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_ol.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:25:10 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 21:06:19 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <pthread.h>
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

# define JUST 0.0078125

# ifndef DEPTH
#  define DEPTH 32
# endif

# define ZOOM_CONST 0.98

# define FASTSCROLL 5
# define SLOWSCROLL 0.1

# define CHAR_2PI 40.5845104884

# define THREAD_MAX 1

typedef 			void *(*t_sr)(void *);
typedef 			void (*t_loop)(void *);

typedef struct s_complex
{
	double	real;
	double	imgn;
}	t_complex;

typedef				unsigned int (t_occ)(t_complex, unsigned long, long);

typedef struct s_cam
{
	t_occ	*occlusion;
	double	zoom;
	long	x_offset;
	long	y_offset;
	int		width;
	int		height;
}	t_cam;

typedef mlx_image_t	t_img;

typedef struct s_fractal
{
	t_complex	c;
	uint32_t	(*get_color)(t_complex, t_occ *, struct s_fractal);
	double		symmetry;
	long		depth;
}	t_fractal;

typedef				unsigned int (t_gc)(t_complex, t_occ *, t_fractal);

struct s_screenstate;

typedef struct s_threadstate
{
	pthread_t				thread;
	int						bias;
	struct s_screenstate	*screen;
}	t_threadstate;

typedef struct s_screenstate
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			camera;
	t_fractal		fractal;
	t_threadstate	threadstate[THREAD_MAX];
	bool			continue_drawing;
}	t_screenstate;



////////////					I/O									////////////

t_screenstate		read_args(char **in);
void				print_params(void);
void				print_params_2(void);
int					check_state(t_screenstate state);
void				output_state(t_screenstate *state, char *filename);

////////////					Controls							////////////

void				zoom_to_cursor(mlx_t *mlx, t_cam *cam, double direction);

int					check_other(t_screenstate *state, t_cam *camera);
int					check_qert(mlx_t *mlx, t_fractal *fractal);
int					check_wasd(mlx_t *mlx, t_fractal *fractal);
int					check_arrow_keys(mlx_t *mlx, t_cam *cam);

////////////					Rendering							////////////

void				blank_image(t_img *img);

void				initialize_threadstate(t_screenstate *screen);
void				create_draw_threads(t_screenstate *screen);
void				join_draw_threads(t_screenstate *screen);
void				draw_cycle(t_screenstate *screen);

void				*draw_fract(t_threadstate *state);

////////////					Fractals							////////////

uint32_t			gc_j_2(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_2(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_3(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_3(t_complex z, t_occ *occlusion, t_fractal fractal);

uint32_t			gc_j_g(t_complex z, t_occ *occlusion, t_fractal fractal);
uint32_t			gc_b_g(t_complex z, t_occ *occlusion, t_fractal fractal);

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
unsigned int		occ_depth(t_complex z, unsigned long i, long depth);
unsigned int		occ_plane(t_complex z, unsigned long i, long depth);
unsigned int		occ_beam(t_complex z, unsigned long i, long depth);
unsigned int		occ_curse(t_complex z, unsigned long i, long depth);

////////////					Hooks								////////////

void				ft_scroll_hook(double dx, double dy, t_screenstate *state);
void				ft_resize_hook(int32_t w, int32_t h, t_screenstate *state);
void				ft_key_hook(mlx_key_data_t keydata, t_screenstate *state);
void				ft_close_hook(t_screenstate *state);
void				ft_loop_hook(t_screenstate *state);

void				output_nonblocking(t_screenstate *state);

////////////					Error handling						////////////

void				ft_exit(int state, const char *function, int line);

#endif
