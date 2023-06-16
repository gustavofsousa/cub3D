#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;
	
	(void)argv;
	setup_data(&data);
	setup_game(&data.img);
	render_game(&data);
	return (1);
}