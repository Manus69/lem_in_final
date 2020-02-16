/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:20:50 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 18:08:25 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

struct		s_token
{
	char	*token;

	char	*flag_string;
	char	*width_string;
	char	*precision_string;
	char	*length_string;

	int		width;
	int		precision;
	char	type;

	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		space;

	int		h;
	int		hh;
	int		l;
	int		ll;
	int		big_l;
};

struct		s_output
{
	char	*output;
	char	*result;
	char	*prefix;

	int		default_length;
	int		adjusted_length;
	int		output_length;

	char	padding_char;
	int		insertion_index;
	int		prefix_index;
	int		prefix_size;
};

union		u_data
{
	int					integer;
	long int			long_int;
	long long			long_long_int;
	unsigned int		u_integer;
	unsigned long int	u_long_int;
	unsigned long long	u_long_long_int;
	double				just_double;
	long double			long_double;
	char				*string;
	void				*pointer;
};

struct		s_jcount_tuple
{
	int	j;
	int	count;
};

struct		s_useless
{
	int			sign;
	int			last_digit;
	int			extra_junk;
	long long	integer;
};

typedef struct s_token			t_token;

typedef struct s_output			t_output;

typedef struct s_input			t_input;

typedef struct s_jcount_tuple	t_jcount_tuple;

#endif
