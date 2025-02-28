/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:39:31 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/21 15:37:09 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		new_node = ft_lstnew(ptr);
		if (!new_node)
		{
			del(ptr);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	*square(void *content)
// {
// 	int *newcontent = malloc(sizeof(int));
// 	if (!newcontent)
// 		return (NULL);
// 	*newcontent = (*(int *)content) * (*(int *)content);
// 	return (newcontent);
// }

// void	del(void *node)
// {
// 	if (node)
// 		free(node);
// }

// void	print_content(void *content)
// {
// 	printf("%d\n", *(int *)content);
// }

// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *new_lst;

// 	int *num1 = malloc(sizeof(int));
// 	int *num2 = malloc(sizeof(int));
// 	int *num3 = malloc(sizeof(int));
// 	int *num4 = malloc(sizeof(int));
// 	int *num5 = malloc(sizeof(int));
// 	int *num6 = malloc(sizeof(int));

// 	*num1 = 1;
// 	*num2 = 4;
// 	*num3 = 9;
// 	*num4 = 16;
// 	*num5 = 25;
// 	*num6 = 36;

// 	ft_lstadd_back(&lst, ft_lstnew(num1));
// 	ft_lstadd_back(&lst, ft_lstnew(num2));
// 	ft_lstadd_back(&lst, ft_lstnew(num3));
// 	ft_lstadd_back(&lst, ft_lstnew(num4));
// 	ft_lstadd_back(&lst, ft_lstnew(num5));
// 	ft_lstadd_back(&lst, ft_lstnew(num6));

// 	new_lst = ft_lstmap(lst, square, del);

// 	ft_lstiter(new_lst, print_content);

// 	ft_lstclear(&lst, del);
// 	ft_lstclear(&new_lst, del);

// 	return 0;
// }
