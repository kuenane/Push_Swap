
#include "pushswap.h"

void	ft_op_ra(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("ra\n");
	i = 0;
	store = list->stack[0];
	while (i < list->llen - 1)
	{
		list->stack[i] = list->stack[i + 1];
		i++;
	}
	if (list->llen > 1)
		list->stack[list->llen - 1] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rb(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("rb\n");
	i = 0;
	store = list->bstack[0];
	while (i < list->rlen - 1)
	{
		list->bstack[i] = list->bstack[i + 1];
		i++;
	}
	if (list->rlen > 1)
		list->bstack[list->rlen - 1] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rr(t_push_list *list)
{
	ft_push_printf("rr\n");
	ft_op_ra(list, 1);
	ft_op_rb(list, 1);
	ft_push_print(list);
	list->steps--;
}
