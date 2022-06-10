#include "minirt.h"

t_obj	*lst_new(int id)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		return (0);
	new->next = 0;
	new->id = id;
	return (new);
}

void	lst_addback(t_obj **head, t_obj *new)
{
	t_obj	*temp;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}