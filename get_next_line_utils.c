/*Linijka po linijce: int ft_strlen(char *string): Deklaracja funkcji ft_strlen,
która przyjmuje jeden argument, wskaźnik char *string na łańcuch znaków, i
zwraca liczbę całkowitą (int). int count;: Deklaracja zmiennej count, która
będzie licznikiem znaków w łańcuchu. count = 0;: Inicjalizacja zmiennej count na
0. Oznacza to, że początkowo licznik jest ustawiony na 0. while (string[count]):
Pętla while, która iteruje przez łańcuch znaków, dopóki nie napotka znaku
null-terminującego (\0). Znak string[count] jest równoznaczny z *(string +
count), czyli odwołaniem się do kolejnego znaku w łańcuchu. count++;:
Zwiększenie licznika o 1 w każdej iteracji pętli. Oznacza to, że pętla przeszła
kolejny znak w łańcuchu. return (count);: Zwrócenie wartości zmiennej count,
która teraz zawiera liczbę znaków w łańcuchu (długość łańcucha).*/
#include "get_next_line.h"
int		ft_strlen(char *str)
{
	int counter;
	counter = 0;
	while(str[counter] != '\0')
		counter++;
	return(counter);
}
/*
char *ft_strdup(char *string): Deklaracja funkcji

ft_strdup, która przyjmuje jeden argument, wskaźnik char *string na łańcuch
znaków, i zwraca wskaźnik na nowo zaalokowany łańcuch znaków (char *). int i;:
Deklaracja zmiennej i, która będzie używana jako indeks w pętli do kopiowania
znaków. int size;: Deklaracja zmiennej size, która będzie przechowywać długość
łańcucha znaków. char *duplicate;: Deklaracja wskaźnika duplicate, który będzie
wskazywał na nowo zaalokowany łańcuch znaków. 

i = 0;: Inicjalizacja zmiennej i na 0. Będzie używana jako indeks w pętli. size
= ft_strlen(string);: Wywołanie funkcji ft_strlen, aby obliczyć długość łańcucha
znaków string, i przypisanie tej wartości do zmiennej size. 

duplicate = malloc(sizeof(char) * (size + 1));: Alokacja pamięci dla nowego
łańcucha znaków o długości size + 1 (dodatkowy jeden bajt na znak
null-terminujący \0). sizeof(char) zawsze wynosi 1, więc można to również
zapisać jako duplicate = malloc(size + 1);. 

if (!duplicate): Sprawdza, czy malloc zwrócił NULL, co oznacza niepowodzenie przydzielenia pamięci.
return (0): Zwraca 0 (NULL), jeśli przydzielenie pamięci się nie powiodło.

Pętla while, która kopiuje znaki z
oryginalnego łańcucha string do nowo zaalokowanego łańcucha duplicate, dopóki
nie napotka znaku null-terminującego (\0). duplicate[i] = string[i];: Kopiowanie
bieżącego znaku z string do duplicate. i++;: Zwiększenie indeksu i o 1 w każdej
iteracji pętli. duplicate[i] = '\0';: Po zakończeniu pętli dodanie znaku
null-terminującego (\0) na końcu nowego łańcucha duplicate. return (duplicate);:
Zwrócenie wskaźnika na nowo zaalokowany i skopiowany łańcuch znaków duplicate.*/

/*Funkcja ft_strdup (skrót od "string duplicate") jest używana do tworzenia
duplikatu łańcucha znaków. Oznacza to, że tworzy nowy łańcuch znaków, który jest
kopią oryginalnego łańcucha, ale znajduje się w innej lokalizacji w pamięci.
Poniżej znajdują się szczegółowe wyjaśnienia, dlaczego i kiedy używa się funkcji
ft_strdup.*/
char	*ft_strdup(char *str)
{
	int i;
	int str_length;
	char *str_duplicate;

	i = 0;
	str_length = ft_strlen(str);
	str_duplicate = malloc(sizeof(char) * (str_length +   1));
	if (!str_duplicate)
		return (0);
	while (str[i])
	{
		str_duplicate[i] = str[i];
		i++;
	}
	str_duplicate[i] = '\0';
	return (str_duplicate);
}
/*W instrukcji `duplicate = malloc(sizeof(char) * (size + 1))` używamy funkcji
`malloc` (z ang. memory allocation) z biblioteki standardowej języka C, aby
dynamicznie przydzielić pamięć. Rozbijmy to krok po kroku:

### Składnia `malloc`
`malloc` to funkcja, która przydziela określoną ilość pamięci i zwraca wskaźnik
do początku tego bloku pamięci. Jej deklaracja wygląda tak:
```c
void* malloc(size_t size);
```
- `size_t size`: ilość pamięci (w bajtach), którą chcemy przydzielić.

### Jak to działa w naszym przypadku:
1. **`sizeof(char)`**: Funkcja `sizeof` zwraca rozmiar typu `char` w bajtach. W
   większości systemów `sizeof(char)` wynosi 1 bajt.

2. **`size + 1`**: Zmienna `size` jest prawdopodobnie wcześniej zdefiniowaną
   zmienną typu całkowitego, która określa liczbę znaków w ciągu znaków, który
   chcemy skopiować lub utworzyć. Dodajemy 1, aby zarezerwować miejsce na
   końcowy znak null (`'\0'`), który jest używany do oznaczenia końca ciągu
   znaków w języku C.

3. **`sizeof(char) * (size + 1)`**: Wyliczamy całkowitą ilość pamięci, którą
   chcemy przydzielić. Jest to `size + 1` bajtów, ponieważ każdy znak zajmuje 1
   bajt, a dodatkowy bajt jest na końcowy znak null.

4. **`malloc(sizeof(char) * (size + 1))`**: `malloc` przydziela dokładnie tyle
   pamięci, ile wyliczyliśmy, i zwraca wskaźnik do tej pamięci. Ponieważ
   `malloc` zwraca wskaźnik typu `void*`, zazwyczaj rzutujemy go na odpowiedni
   typ wskaźnika.

5. **`duplicate`**: To jest zmienna wskaźnikowa (prawdopodobnie zadeklarowana
   wcześniej jako `char* duplicate`), która będzie wskazywała na pierwszy bajt
   nowo przydzielonego bloku pamięci.

### Cała instrukcja w kontekście:
```c
char* duplicate = malloc(sizeof(char) * (size + 1));
```
- Przydziela pamięć dla `size + 1` znaków typu `char`.
- Przechowuje wskaźnik do przydzielonej pamięci w zmiennej `duplicate`.

### Przykład użycia
Załóżmy, że chcemy skopiować jakiś ciąg znaków:
```c
#include <stdlib.h>
#include <string.h>

char* create_duplicate(const char* source) {
    size_t size = strlen(source);  // Znajdź długość źródłowego ciągu znaków
    char* duplicate = malloc(sizeof(char) * (size + 1));  // Przydziel pamięć
    if (duplicate != NULL) {
        strcpy(duplicate, source);  // Skopiuj ciąg znaków do nowo przydzielonej pamięci
    }
    return duplicate;
}
```
W tym przykładzie:
- Funkcja `create_duplicate` przyjmuje wskaźnik do źródłowego ciągu znaków
  `source`.
- Oblicza długość `source` bez znaku null.
- Przydziela wystarczająco dużo pamięci na skopiowanie `source` wraz z końcowym
  znakiem null.
- Kopiuje zawartość `source` do nowo przydzielonej pamięci.
- Zwraca wskaźnik do nowo przydzielonego i skopiowanego ciągu znaków.

### Podsumowanie
Instrukcja `duplicate = malloc(sizeof(char) * (size + 1))` przydziela
dynamicznie pamięć dla ciągu znaków o długości `size` wraz z dodatkowym bajtem
na znak null i zapisuje wskaźnik do tej pamięci w zmiennej `duplicate`.*/