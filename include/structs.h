#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

#endif
