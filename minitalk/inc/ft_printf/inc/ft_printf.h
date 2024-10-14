/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravargas <ravargas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:10:04 by ravargas          #+#    #+#             */
/*   Updated: 2024/05/17 11:28:02 by ravargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORMATS	"cspdiuxX"
# define HEXUPPER	"0123456789ABCDEF"
# define HEXLOWER	"0123456789abcdef"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../libft/inc/libft.h"

typedef struct t_print
{
	va_list	vars;
	int		tlen;
	int		fmw;
	int		dash;
	int		is_zero;
	int		point;
	int		space;
	int		hashtag;
	int		plus;
	int		perc;
}			t_print;

int			ft_printf(char const *s, ...);
int			ft_iter_s(char const *s, t_print *p);
t_print		*ft_init_struct(t_print *tab);
int			isflag(char const s);
int			ft_set_pinfo(char const *s, t_print *p, int i);

void		ft_pchar(t_print *p);
void		ft_number(t_print *p);
int			ft_str(t_print *p);
int			ft_unsigned(t_print *p);
int			ft_hex(t_print *p);
int			ft_hexupp(t_print *p);
int			ft_pointr(t_print *p);
void		ft_wrt_percent(t_print *p);

#endif
