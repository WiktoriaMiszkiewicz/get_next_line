#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*Te linijki dołączają standardowe pliki nagłówkowe potrzebne do działania
funkcji w get_next_line. stdlib.h zawiera deklaracje dla funkcji zarządzających
pamięcią (np. malloc, free), a unistd.h zawiera deklaracje dla funkcji
systemowych (np. read, close).*/
# include <stdlib.h>
# include <unistd.h>


//get_next_line_utils.c
int	ft_strlen(char *str);
char	*ft_strdup(char *str);

//get_next_line.c
char	*get_next_line(int fd)

#endif