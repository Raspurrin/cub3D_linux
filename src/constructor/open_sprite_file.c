#include "constructor.h"

/* 
	Checks for file format in a file name 
*/
static int	validate_file_name(char *name)
{
	if (ft_strlen(name) < 4)
	{
		ft_putstr_fd("Invalid .cub file name\n", 1);
		return (0);
	}
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".cub", 4))
	{
		ft_putstr_fd("Invalid .cub file name\n", 1);
		return (0);
	}
	return (1);
}

/* 
	Opens .cub file 
	Sets in data->map the t_map struct data
*/
void	open_cub_file(char *file_name, t_data *data)
{
	t_map_c tmp;

	if (!validate_file_name(file_name))
		destructor(data);
	if (!file_to_heap(file_name, &tmp.file))
	{
		ft_putstr_fd("File access error\n", 1);
		destructor(data);
	}
	
	if (!validate_cub_file(tmp.file, &tmp))
		destructor(data);
	data->map = assign_map(data, tmp);
}

void	open_sprite_file(t_data *data)
{
	t_list	**tmp;

	file_to_heap("./map_files/sprite_info.ini", &tmp);
	
}