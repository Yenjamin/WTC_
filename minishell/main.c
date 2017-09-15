/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:10:27 by yechen            #+#    #+#             */
/*   Updated: 2017/09/15 16:39:41 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_paths(void)
{
	char	*t;
	char	**paths;

	t = envval("PATH");
	paths = NULL;
	if (t != NULL)
		paths = ft_strsplit(t, ':');
	return (paths);
}

int		forking(char **args)
{
	char	**paths;
	char	*t;
	char	*pass;
	int		i;

	i = 0;
	paths = get_paths();
	while(paths[i])
	{
		t = ft_strjoin(paths[i], "/");
		pass = ft_strjoin(t, args[0]);
		i++;
	}
	pid_t  pid;

	if (pass)
	{	
		pid = fork();
		if (pid == 0)
		{
			execve(pass, args, g_nvar);
			return (0);
		}
		else if (pid < 0)
			ft_putstr("error");
		else
			wait(&pid);
	}
	return (1);
}

char	*envval(char *var)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (var[l] != '=' && var[l] != '\0')
		l++;
	while (g_nvar[i])
	{
		if (ft_strncmp(g_nvar[i], var, l) == 0)
			return (ft_strchr(g_nvar[i], '=') + 1);
		i++;
	}
	return (NULL);
}

int		bt_env(void)
{
	int			i;

	i = 0;
	while (g_nvar[i])
	{
		ft_putendl(g_nvar[i]);
		i++;
	}
	return (1);
}

char	**envinitial(void)
{
	extern char **environ;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	g_nvar = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		g_nvar[i] = ft_strdup(environ[i]);
		i++;
	}
	g_nvar[i] = NULL;
	return (g_nvar);
}

int		fexecute(char **args)
{
	if (args[0] == NULL || !args)
		return (1);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "env") == 0)
		return (bt_env());
	else
		return (forking(args));
}

void	floop(void)
{
	int		r;
	char	**args;
	char	*line;

	r = 1;
	while (r)
	{
		ft_putstr("->");
		if (get_next_line(0, &line) < 0)
			ft_putstr("Error");
		args = ft_strsplit(line, ' ');
		r = fexecute(args);
	}
}

int		main(void)
{
	envinitial();
	floop();
	return (0);
}
