/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <and nephilister>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:14:07 by uterese           #+#    #+#             */
/*   Updated: 2021/09/28 01:31:45 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	deal_curly(t_lexer **lex, int *i)
{
	if ((*lex)->s[*i + 1] == '{')
	{
		(*lex)->cb = 1;
		(*i)++;
	}
}

static char	*deal_dollar(t_token **tok, int *ret)
{
	char	*tmp;

	tmp = (*tok)->data;
	(*tok)->data = ft_strjoin(tmp, "$");
	(*tok)->tkn = 1;
	free(tmp);
	(*ret)++;
	return (0);
}

int	expand_env(t_lexer **lex, int i, t_token **tok)
{
	char	*tmp;
	char	*new;
	char	*beg;
	int		ret[2];

	beg = ft_substr((*lex)->s, 0, i);
	deal_curly(lex, &i);
	ret[0] = get_len((*lex)->s, i + 1);
	ret[1] = ft_strlen(beg) - 1;
	if (!(*lex)->s[i + 1])
		new = deal_dollar(tok, &ret[1]);
	else
		new = get_val((*lex)->s, i, ret[0]);
	if (!new)
		return (ret[1]);
	tmp = ft_strjoin(beg, new);
	free(beg);
	beg = ft_substr((*lex)->s, (++ret[0] + i), ft_strlen((*lex)->s));
	free((*lex)->s);
	(*lex)->s = ft_strjoin(tmp, beg);
	free(beg);
	free(tmp);
	return (ret[1]);
}
