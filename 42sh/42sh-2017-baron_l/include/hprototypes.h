/*
** hprototypes.h for 42sh in /home/garner_p/Workplace/Systeme_Unix/42sh-2017-baron_l/tree
**
** Made by Garnero Philip
** Login   <garner_p@epitech.net>
**
** Started on  Wed May 22 16:57:27 2013 Garnero Philip
** Last update Sun May 26 21:59:28 2013 louis-philippe baron
*/

#ifndef		HPROTOTYPES_H_
# define	HPROTOTYPES_H_

#include	<sys/types.h>
#include	<dirent.h>

/*
** check_command_tab.c
*/
int		check_command_tab(char **tab);

/*
** dev_urandom.c
*/
int		dev_urandom(char *str);

/*
** basics2.c
*/
int		my_cmp(char *env, char *term);

/*
** access.c
*/

char	*see_access(char *bin, t_list *tmp);
int	is_builtins(char **dtab);

/*
** basics.c
*/

int	my_strcmp(char *str, char *find);
char	*my_strdup(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strccat(char *dest, char *src, int c);
void	del_case(char *str);

/*
** bool_condition.c
*/

void	bool_condition(char *bool, char stri);

/*
** builtins.c
*/

int	set_env(char **dtab, t_list **envi);
int	unset_env(char **dtab, t_list **envi);
int	cd(char **dtab, t_list **envi);

/*
** char_siders.c
*/

void	my_putchar(char c);
void	my_putstr(char *str);
void	putstr_fd(int fd, char *str);
int     my_strlen(char *str);
char    *my_strcpy(char *dest, char *src);

/*
** check_quotes.c
*/

int	check_quotes(char *str);

/*
** check_command.c
*/

char	**check_command(char *token, t_glob *glob);
int	tree_check_pipes(t_tree *tree, t_glob *glob);

/*
** check_conflict_redir.c
*/
int	check_conflict_redir(char **tab);

/*
** cross_tree.c
*/

int	cross_tree(t_tree *tree, t_glob *glob);

/*
** cut_redir.c
*/

int	count_redir(char **tab);
int	count_redir_line(char *str);
char	**cut_redir_tab(char **tab, t_glob *glob);

/*
** cut_redir_line.c
*/

char	**cut_redir_line(char *str, t_glob *glob);

/*
** double_right_redir.c
*/
int	is_double_right(t_tree *tree, int files[], int *pfd, t_glob *glob);
void	double_right_redir(t_tree *tree, int pfd[], int pid);

/*
** echo.c
*/
int	my_echo(int ac, char **av);

/*
** epur_str.c
*/

char	*epur_str(char *str, char *param, char bool);

/*
** error.c
*/

int	error_int(char *mess);
int	error_int_set_glob(t_glob *glob, char *mess);
int	error_v_int(char *mess, int ret);
void	*error_ptr(char *mess);
void	*error_ptr_set_glob(t_glob *glob, char *mess);

/*
** exec.c
*/

int	choose_prog(char **dtab, char **envi, t_glob *glob);

/*
** finder.c
*/

int	get_env(char **env, t_list **envi);
t_list	*finder(char *to_find, t_list *envi);
char	**transform_list(t_list *envi);

/*
** get_next_line.c
*/

char	*get_next_line(int fd);

/*
** globbing.c
*/

char	*glob_return(char *pattern);

/*
** glob_it.c
*/
int	find_start(char *str, int i, char *param);
char	*glob_it(char *str, char *param);

/*
** glob_it_cuts.c
*/
int	do_multi_cuts(char *str, int *cpt, char *param, char **res);

/*
** glob_it_loop.c
*/
int	glob_loop(char **tmp, char *param);

/*
** glob_it_clean.c
*/
char	**clean_it(char **tab);

/*
** glob_it_cat.c
*/
char	*glob_cat_all(char **tab);

/*
** history.c
*/

int	init_histo(t_glob *glob);
void	write_hist(t_glob *glob);
int	add_command(t_glob *glob, char *line);
char	*hist_line(int id, t_glob *glob);
int	my_put_in_hist(t_hist **list, char *cmd, int red);

/*
** int_siders.c
*/

int	my_getnbr(char *str);
void    my_put_nbr(int nb);

/*
** list_siders.c
*/

int	free_loop(t_list *first);
int	my_put_in_list(t_list **list, char *str);
void	my_show_list(t_list *list);
void	my_rev_list(t_list **begin);
int     delete_mail(t_list **envi, t_list *tmp);

/*
** my_command_to_wordtab.c
*/

char	**my_command_to_wordtab(char *str, char *params);

/*
** mysh.c
*/
int	mysh(t_glob *glob);
int	free_wordtab(char **tab);

/*
** my_str_to_wordtab.c
*/

int	is_in(char c, char *params, char bool);
char	**my_str_to_wordtab(char *str, char *params);

/*
** old_pwd.c
*/

void	verif(t_list *tmp, char *to_set, t_list **envi);
int 	set_old(t_list **envi);
int	set_pwd(t_list **envi);

/*
** path.c
*/

char	**get_path(char *to_cut);

/*
** pwd.c
*/

char	*build_path(int i);
char	*return_good_str(DIR *dir, ino_t ino);
char	*return_pwd(t_list **pwd);
char	*pwd_tab(t_list **pwd);

/*
** stick_back_arg.c
*/

char	**stick_back_arg(char **tab, int len);

/*
** tab.c
*/
void	free_tab(char **tab);
int	tab_len(char **tab);

/*
** tree.c
*/

int	tree_call(char **tab, t_glob *glob);

/*
** tree_exec.c
*/

int	tree_exec_command(char *token, t_glob *glob);
int	tree_exec_builtins(char **command, t_glob *glob);

/*
** tree_files.c
*/

int	tree_files(t_tree *tree);

/*
** tree_make_branch.c
*/

int	child_tree(t_tree **tree, char **tab, int side, char **sep);

/*
** tree_make.c
*/

int	my_put_in_tree(t_tree **list, char *token, int type, int side);
int	make_tree(t_tree **tree, char **tab, int side, char **sep);

/*
** tree_pipes.c
*/

int	tree_pipe_exec(t_tree *tree, t_glob *glob, int files[]);
int	tree_pipes(t_tree *tree, int infd, t_glob *glob, int files[]);
int	pipe_branch(t_tree *tree, t_glob *glob);

/*
** tree_redir.c
*/

int	tree_redir_and_exec(t_tree *tree, t_glob *glob, int fd, int fd2);
int	tree_redir(t_tree *tree, t_glob *glob);

/*
** tree_redir_files.c
*/

int	tree_redir_files(char *sep, char *name);

#endif		/* H_PROTOTYPES_H_ */
