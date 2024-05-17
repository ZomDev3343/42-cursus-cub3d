/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:02:43 by truello           #+#    #+#             */
/*   Updated: 2024/05/17 14:29:50 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

void	*ft_calloc(size_t count, size_t size);
int		ft_free(void *ptr);

char	**ft_split(char const *str, char c);
char	**free_parts(char **parts);
void	print_parts(char **parts);
int		get_parts_size(char **parts);

int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_isalpha(char c);
int		ft_isalphanum(char *str);
int		ft_isalphanum_c(char c);

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strncpy(char *to_copy, size_t n);
char	*ft_strcpy(char *to_copy);
char	*ft_strcpy_wsp(char *line, int *index);
char	*ft_strcpy_until_quote(char *str, char quote);
char	*ft_strcpy_until_quotes(char *str);
void	ft_strrepl(char *str, char bef, char aft);
int		ft_strchr_i(char *str, char c);
int		ft_nstrchr_i(char *str, char c);
int		ft_strchr_i_nquotes(char *str, char c);
int		ft_strchr_nalphanum(char *str);
int		ft_strchr_quotes(char *str);

char	*ft_strdup(char *str);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_strlen(const char *str);
char	*ft_itoa(int n);

void	ft_error(const char *str);

void	ft_swap_int(int *a, int *b);

int		has_int_parts(char *line, char delimiter);
int		is_int_parts(char **parts);

int		get_file_size(char *file_path);
char	*get_file_content(char *file_path);

int		ft_max(int x, int y);
double	ft_dmax(double x, double y);
int		ft_min(int x, int y);
double	ft_dmin(double x, double y);

#endif
