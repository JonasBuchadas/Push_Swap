/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:33 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:45:31 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Allocates (with malloc(3)) and returns a new element.
The variable ’content’ is initialized with the value of the parameter ’content’. 
The variables ’next’ and ’prev’ are initialized to itself.
*/

#include "libft.h"
#include <stdlib.h>

dt_list	*ft_cdlstnew(void *content)
{
	dt_list	*new;

	new = (dt_list *)malloc(sizeof(dt_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}
