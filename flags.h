#ifndef FLAGS_H

# define FLAGS_H

#include <unistd.h>
#include "libft/libft.h"

typedef	struct	s_width
{
	int is_left;
	int width;
}		t_width;

typedef struct	s_precision
{
	int length;
}		t_precision;

typedef struct	s_specifer
{
	char specifer;
}		t_specifer;

typedef struct	s_flag
{
	t_width		width;
	t_precision	precision;
	t_specifer	specifer;
}		t_flag;
#endif
