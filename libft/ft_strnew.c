/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:12:49 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/17 13:43:13 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(dest, size);
	dest[size] = '\0';
	return (dest);
}
