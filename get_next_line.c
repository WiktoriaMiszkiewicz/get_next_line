#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int	len1;
	int len2;
	int i,j;
	len1 = 0;
	len2 = 0;
	//Wyliczenie długości s1 i s2
	if (s1)
		while(s1[len1] != '\0')
		{
			len1++;
		}
	if (s2)
		while(s2[len2] != '\0')
		{
			len2++;
		}
	//Alokacja pamięci dla nowego ciągu znaków
	result = malloc(len1 +len2 + 1);
	if (!result)
		return(NULL);
	//Kopiowanie s1 do result
	i = 0;
	if (s1)
		while (s1[i])
		result[i] = s1[i];
		i++;
	j = 0;
	if (s2)
		while (s2[j])
		result[i] = s2[j];
		i++;
		j++;
}

char	*get_next_line(int fd)
{
	//char buffer[BUFFER_SIZE + 1];: Tworzymy małą "pudełko" (tablicę znaków) o
	//nazwie buffer, aby przechowywać tekst, który odczytamy z pliku. Ma rozmiar
	//BUFFER_SIZE plus jeden dodatkowy znak na zakończenie (znak null).
	char		buffer[BUFFER_SIZE +1];
	/*char *line = NULL;: Tworzymy wskaźnik o nazwie line, który na początku nic
	nie wskazuje (jest pusty). Będziemy w nim przechowywać odczytaną linię
	tekstu.*/
	char	*line = NULL;
	//int b;: Tworzymy zmienną b, która będzie przechowywać liczbę znaków, które
	//udało się odczytać z pliku.
	int b;
	//int i;: Tworzymy zmienną i, która będzie służyła do liczenia znaków
	//podczas sprawdzania linii tekstu
	int i;
}
if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);