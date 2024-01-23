/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _error_handling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 13:56:22 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/23 14:30:23 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_exit(int state, const char *function, int line)
{
	ft_printf("\033[31mExiting with state %d in function %s at line %d\033[39m\n",
		state, function, line);
	exit(state);
}

int		check_state(t_screenstate state)
{
	if (state.camera.width < 1 || state.camera.width > 3000)
		return (ft_printf("\033[31mBad width! < 1 or > 3000\033[39m\n"), 1);
	if (state.camera.height < 1 || state.camera.height > 3000)
		return (ft_printf("\033[31mBad height! < 1 or > 3000\033[39m\n"), 1);
	if (state.fractal.depth > 1024)
		ft_printf("\033[31mDepth > 1024! Timeout very likely.\033[39m\n");
	if (state.fractal.depth < 1)
		return (ft_printf("\033[31mBad depth! < 1\033[39m\n"), 1);
	
	return (0);
}

void	print_params(void)
{
	ft_printf("You can give any fractal files or parameters as arguments.\n\n");
	ft_printf("\033[37m---Static parameters---\033[39m\n");
	ft_printf("To dictate what kind of fractal should be shown, pass:\n");
	ft_printf("\t\033[36mFractal = mbrot_2\tOr: julia_t.\033[39m\n");
	ft_printf("The following suffixes create different fractals:\n");
	ft_printf("\t\033[36m_2, _3, _g, _n, _t, _x\033[39m\n\n");
	ft_printf("To dictate the color blending and occlusion used, pass:\n");
	ft_printf("\t\033[36mOcclusion = substraction\n");
	ft_printf("\tOr: cutoff, angle, depth, plane, beam, recursive\033[39m\n\n");
	ft_printf("\033[37m---Dynamic parameters---\033[39m\n");
	ft_printf("These can be changed at runtime.\n\n");
	ft_printf("C is the constant used for navigating the julia fractal set.\n");
	ft_printf("It has no effect on the mandelbrot fractal.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("\t\033[36mC.real = 0.1807\t\tOr: Any real number.\n");
	ft_printf("\tC.imgn = -0.7890\tOr: Any real number.\033[39m\n");
	ft_printf("You can modify it at runtime using the WASD keys.\n\n");
	ft_printf("Symmetry is the exponent used when iterating over Z.\n");
	ft_printf("It changes how many copies of the fractal exist per layer.\n");
	ft_printf("It does nothing for the _2 and _3 suffixes.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("\t\033[36mSymmetry = -1.890\tOr: Any real number.\033[39m\n");
	ft_printf("You can modify it at runtime using the Q and E keys.\n\n");
	ft_printf("Depth is the amount of iterations done over Z\n");
	print_params_2();
}

void	print_params_2(void)
{
	ft_printf("It changes how many layers can be found when zooming in.\n");
	ft_printf("If the program is very slow, try reducing the depth.\n");
	ft_printf("To modify it pass:\n");
	ft_printf("\t\033[36mDepth = 16\tOr: Any positive integer.\033[39m\n");
	ft_printf("You can modify it at runtime using the R and T keys.\n\n");
	ft_printf("\033[37m---Camera parameters---\033[39m\n");
	ft_printf("These move the camera.\n\n");
	ft_printf("To change position and zoom, pass:\n");
	ft_printf("\t\033[36mZoom = 0.1807\tOr: Any real number.\n");
	ft_printf("\tX_offset = -256\tOr: Any integer.\n");
	ft_printf("\tY_offset = -256\tOr: Any integer.\033[39m\n");
	ft_printf("They can also be scrolled using the arrow keys and mouse\n");
	ft_printf("You can also use Z to reset zoom and offset\n\n");
	ft_printf("To change the window size, pass:\n");
	ft_printf("\t\033[36mWidth = 256\tOr: Any positive integer.\n");
	ft_printf("\tHeight = 256\tOr: Any positive integer.\033[39m\n\n");
	ft_printf("Files follow the same syntax as the command line.\n");
	ft_printf("Press Enter and input a filename on the console to\n");
	ft_printf("write the program's state to a file.\n");
	exit(0);
}
