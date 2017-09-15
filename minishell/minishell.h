/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:18:51 by yechen            #+#    #+#             */
/*   Updated: 2017/09/15 16:15:07 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"

char	**g_nvar;

char	**get_paths(void);
int		forking(char **args);
char	*envval(char *var);
int		bt_env(void);
char	**envinitial(void);
int		fexecute(char **args);
void	floop(void);

#endif
