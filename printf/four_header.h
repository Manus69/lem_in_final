/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:22:28 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/11 13:39:30 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOUR_HEADER_H
# define FOUR_HEADER_H

# include "libft.h"
# include "structures.h"
# include "constants.h"
# include <stdarg.h>

int				ft_printf(const char *format, ...);

t_jcount_tuple	*get_tuple_and_check(const char *format);
int				count_and_destroy(t_jcount_tuple **tuple);
union u_data	*get_data(t_token *token, va_list *argument_list);
int				create_confusion(int *j, int *count, const char *format);

int				index_of_any(char *str, char *set, int start);
void			str_capitalize(char *str);
int				why_get_last_index(char *str, char c);
char			*get_str_of_something(int length, char c);
void			fill_string(char *string, char *sub_string, int j);
void			swap(char *str, int j, int k);
void			pad_string(char *string, char c, int index, int size);
char			*reverse_string(char *str);
void			*mallokill(size_t size);

t_token			*string_to_token(char *str);
void			refine_token(t_token *token);
void			destroy_token(t_token **token);

char			*become_dumb(char *string);
long double		absolute_value(long double x);
long long		integer_part(long double x);
char			*why_integer_to_ascii(long long number, int base);
char			*unsigned_integer_to_ascii(unsigned long long number, int base);
int				round_propagate(char *decimal, int index);
char			*real_to_ascii_mk3(long double x, int precision);
char			*decimal_part_mk4(long double x, int number_of_digits,
				int *last_digit_flag, int *extra_junk_flag);
void			waste_time(struct s_useless *why, char *decimal_string,
				int precision);

int				get_default_input_length(t_token *token, void *input);
int				get_insertion_index(t_output *output, t_token *token);
int				get_prefix_index(t_output *output, t_token *token);
int				get_adjusted_string_length(t_output *output, t_token *token);
int				get_output_string_length(t_output *output, t_token *token);
int				print_token_input(t_token *token, void *input);

void			refine_token(t_token *token);
void			settle_token(t_token *token);
void			get_token_fields(struct s_token *token, char *str);
void			process_flags(struct s_token *new_token, char *str, int *j);
void			process_width(struct s_token *new_token, char *str, int *j);
void			get_token_flags(t_token *token);

void			*get_pointer(union u_data *data, t_token *token);
union u_data	*get_csp_data(t_token *token, va_list *argument_list);
union u_data	*get_di_data(t_token *token, va_list *argument_list);
union u_data	*get_usigned_data(t_token *token, va_list *argument_list);
union u_data	*get_f_data(t_token *token, va_list *argument_list);

t_output		*get_output_item(t_token *token, void *input);
void			destroy_output(t_output **output);
char			*get_prefix(t_output *output, t_token *token);
void			process_token(struct s_token *new_token, char *str, int *j);
char			*get_percent_token_representation(t_token *token);
char			*get_di_token_representation(t_token *token, void *input);
char			*get_f_token_representation(t_token *token, void *input);
char			*get_s_token_representation(t_token *token, void *input);
char			*process_token_types(t_token *token, void *input);
char			*get_unsigned_number_representation(t_token *token,
				void *input, int base);
char			*get_default_token_representaion(t_output *output,
				t_token *token, void *input);

#endif
