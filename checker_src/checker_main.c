/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnkanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:10:57 by nnkanyan          #+#    #+#             */
/*   Updated: 2017/12/06 16:58:27 by lkuenane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_checker_argc(t_checker_list *list, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc && list->error != 1)
	{
		if (i == 1 && ft_checker_strcmp(argv[1], "-v") == 0)
		{
			list->error = argc == 2 ? 1 : 0;
			list->debug = 1;
		}
		else
			ft_checker_read_input(list, argv[i]);
	}
	i = list->debug;
	list->stack = (int *)malloc(sizeof(int) * list->size);
	list->bstack = (int *)malloc(sizeof(int) * list->size);
	while (++i < argc && list->error != 1)
		ft_checker_store_input(list, argv[i]);
	ft_checker_find_flag(list);
}

int		main(int argc, char **argv)
{
	t_checker_list	*list;

	list = (t_checker_list *)malloc(sizeof(t_checker_list));
	ft_checker_initialize(&list);
	if (argc == 1)
		return (0);
	handle_checker_argc(list, argc, argv);
	ft_checker_check_duplicates(list);
	if (list->error == 0)
		ft_read_line(list);
	if (list->error == 1)
		ft_checker_printf("Error\n");
	else
		ft_checker(list);
	free(list->stack);
	free(list->bstack);
	free(list);
	return (0);
}
