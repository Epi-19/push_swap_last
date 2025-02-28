#include "push_swap.h"

size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

size_t	ft_word_start(const char *s, char c, size_t i)
{
	size_t	k;
	size_t	l;

	k = 0;
	l = 0;
	while (s[k] && i > l)
	{
		while (s[k] == c && s[k])
			k++;
		if (s[k])
			l++;
		while (s[k] != c && s[k])
			k++;
	}
	while (s[k] == c && s[k])
		k++;
	return (k);
}

void	*ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	tab = (char **)ft_calloc(sizeof(char *), (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_count_word(s, c))
	{
		k = ft_word_start(s, c, i);
		j = 0;
		while (s[k + j] && s[k + j] != c)
			j++;
		tab[i] = (char *)ft_calloc(sizeof(char), (j + 1));
		if (!tab[i])
			return (ft_free(tab));
		j = 0;
		while (s[k] && s[k] != c)
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}
void ft_free_split(char **strs)
{
    int i;
	
	i = 0;
    while (strs[i])
	{
        free(strs[i]);
		i++;
	}
    free(strs);
}