/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management_02.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:50:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/21 16:44:29 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

t_sprite
	*ft_new_sprite(double sx, double sy)
{
	t_sprite *element;

	if (!(element = malloc(sizeof(t_sprite))))
		return (NULL);
	element->x = sx - fmod(sx, 1) + 0.5;
	element->y = sy - fmod(sy, 1) + 0.5;
	element->next = NULL;
	return (element);
}

int
	ft_add_sprite_back(t_sprite **spr, double sx, double sy)
{
	t_sprite *tmp;

	tmp = *spr;
	if (!(*spr))
	{
		if (!(*spr = ft_new_sprite(sx, sy)))
			return (0);
	}
	else
	{
		while ((*spr)->next != NULL)
			*spr = (*spr)->next;
		if (!((*spr)->next = ft_new_sprite(sx, sy)))
			return (0);
		*spr = tmp;
	}
	return (1);
}

void
	ft_sprclear(t_sprite **spr)
{
	t_sprite *svg;

	svg = NULL;
	while (*spr)
	{
		svg = (*spr)->next;
		free(*spr);
		*spr = svg;
	}
}

void
	ft_swap_sprites(t_sprite *curr, t_sprite *next)
{
	t_sprite *tmp;

	if (!(tmp = malloc(sizeof(t_sprite))))
		return ;
	tmp->x = curr->x;
	tmp->y = curr->y;
	tmp->distance = curr->distance;
	curr->x = next->x;
	curr->y = next->y;
	curr->distance = next->distance;
	next->x = tmp->x;
	next->y = tmp->y;
	next->distance = tmp->distance;
	free(tmp);
}

void
	ft_sort_sprites(t_sprite **spr)
{
	t_sprite *curr;
	t_sprite *next;

	curr = *spr;
	if (!curr || !curr->next)
		return ;
	while (curr->next)
	{
		next = curr->next;
		if (curr->distance < next->distance)
		{
			ft_swap_sprites(curr, next);
			curr = *spr;
		}
		else
			curr = curr->next;
	}
}
