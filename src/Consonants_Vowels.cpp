/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
void to_lower(char* str) {
	char *s = str;
	while (*s) {
		if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		s++;
	}
}

void count_vowels_and_consonants(char *str,int *consonants, int *vowels){
	*consonants = *vowels = 0;
	if (str == NULL || *str == '\0')
		return;
	else {
		to_lower(str);
		char *s = str;
		while (*s) {
			if (*s >= 'a' && *s <= 'z') 
				if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
					++(*vowels);
				else
					++(*consonants);			
			s++;
		}
	}
}
