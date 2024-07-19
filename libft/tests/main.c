#include "../includes/ft_lst_utils.h"
#include "../includes/ft_mem_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main()
{
	t_list	*a;

	a = 0;
	int	*ptr1 = malloc(sizeof(int));
	int	*ptr2 = malloc(sizeof(int));
	int	*ptr3 = malloc(sizeof(int));

	*ptr1 = 3;
	*ptr2 = 4;
	*ptr3 = 5;
	ft_lstadd_back(&a, ft_lstnew(ptr1));
	ft_lstadd_back(&a, ft_lstnew(ptr2));
	ft_lstadd_back(&a, ft_lstnew(ptr3));
	ft_lstprint(a, ',');
	ft_lstclear(&a, ft_memclear);
	return (0);
}

