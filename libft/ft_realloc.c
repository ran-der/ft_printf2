#include "ft_libft.h"

void		*ft_realloc(void *ptr, size_t src_size, size_t dst_size)
{
	int		i;
	void	*new;

	if ((new = malloc(dst_size)) == NULL)
		return (NULL);
	new = ft_memcpy(new, ptr, src_size);
	ft_memdel(&ptr);
	return (new);
}
