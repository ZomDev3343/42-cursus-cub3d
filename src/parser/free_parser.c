#include "../../include/cub3d.h"

/*
 * free_tab for free all char ** malloc
 *
 * return void
 * */
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
