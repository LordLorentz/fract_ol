/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 13:26:06 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/22 14:47:57 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	print_params(void);
void	print_params_2(void);

int	main(int argc, char **argv)
{
	t_screenstate	state;
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc == 1)
		print_params();
	ft_strlcpy(argv[0], "standard", 9);
	state = read_args(argv);
	mlx = mlx_init(state.camera.width, state.camera.height, "fract_ol", true);
	if (!mlx)
		ft_exit(1, __func__, __LINE__);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_exit(1, __func__, __LINE__);
	draw_fract(img, state.camera, state.fractal);
	state.mlx = mlx;
	state.img = img;
	mlx_scroll_hook(mlx, &ft_scroll_hook, &state);
	mlx_resize_hook(mlx, &ft_resize_hook, &state);
	mlx_key_hook(mlx, &ft_key_hook, &state);
	mlx_close_hook(mlx, &ft_close_hook, &state);
	mlx_loop_hook(mlx, &ft_loop_hook, &state);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return ((void)argc, EXIT_SUCCESS);
}

void	print_params(void)
{
	ft_printf("You can give any fractal files or parameters as arguments.\n\n");
	ft_printf("---Static parameters---\n");
	ft_printf("To dictate what kind of fractal should be shown, pass:\n");
	ft_printf("Fractal = mbrot_2\tOr: julia_2, mbrot_n, julia_n, etc.\n");
	ft_printf("_2, _3, _g, _n, _t, _x\n");
	ft_printf("All give different fractals when used as a suffix\n\n");
	ft_printf("To dictate the color blending and occlusion used, pass:\n");
	ft_printf("Occlusion = substraction\tOr: cutoff, angle, depth, plane,\n");
	ft_printf("beam, recursive\n\n");
	ft_printf("---Dynamic parameters---\nThese can be changed at runtime.\n\n");
	ft_printf("C is the constant used for navigating the julia fractal set.\n");
	ft_printf("It has no effect on the mandelbrot fractal.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("C.real = 0.1807\tOr: Any real number.\n");
	ft_printf("C.imgn = -0.7890\tOr: Any real number.\n");
	ft_printf("You can modify it at runtime using the WASD keys.\n\n");
	ft_printf("Symmetry is the exponent used when iterating over Z.\n");
	ft_printf("It changes how many copies of the fractal exist per layer.\n");
	ft_printf("It does nothing for the _2 and _3 suffixes.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("Symmetry = -1.890\tOr: Any real number.\n");
	ft_printf("You can modify it at runtime using the Q and E keys.\n\n");
	ft_printf("Depth is the amount of iterations done over Z\n");
	ft_printf("It changes how many layers can be found when zooming in.\n");
	print_params_2();
}

void	print_params_2(void)
{
	ft_printf("If the program is very slow, try reducing the depth.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("Depth = 16\tOr: Any positive integer.\n");
	ft_printf("You can modify it at runtime using the R and T keys.\n\n");
	ft_printf("---Camera parameters---\nThese move the camera.\n\n");
	ft_printf("To change position and zoom, pass:\n");
	ft_printf("Zoom = 0.1807\tOr: Any real number.\n");
	ft_printf("X_offset = -256\tOr: Any integer.\n");
	ft_printf("Y_offset = -256\tOr: Any integer.\n");
	ft_printf("They can also be scrolled using the arrow keys and mouse\n\n");
	ft_printf("To change the window size, pass:\n");
	ft_printf("Width = 256\tOr: Any positive integer.\n");
	ft_printf("Heigh = 256\tOr: Any positive integer.\n\n");
	ft_printf("Files follow the same syntax as the command line.\n");
	ft_printf("Press Enter and input a filename to write the ");
	ft_printf("program's state to a file.\n");
	exit(0);
}
