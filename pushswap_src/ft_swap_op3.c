
#include "pushswap.h"

void	ft_op_rra(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("rra\n");
	i = list->llen - 1;
	store = list->llen > 1 ? list->stack[list->llen - 1] : list->stack[0];
	while (i > 0)
	{
		list->stack[i] = list->stack[i - 1];
		i--;
	}
	list->stack[0] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rrb(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("rrb\n");
	i = list->rlen - 1;
	store = list->rlen > 1 ? list->bstack[list->rlen - 1] : list->bstack[0];
	while (i > 0)
	{
		list->bstack[i] = list->bstack[i - 1];
		i--;
	}
	list->bstack[0] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rrr(t_push_list *list)
{
	ft_push_printf("rrr\n");
	ft_op_rra(list, 1);
	ft_op_rrb(list, 1);
	ft_push_print(list);
	list->steps--;
}
