/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/
#include <stdlib.h>
int string_len3(char* str) {
	char* s = str;
	while (*++s);
	return s - str;
}
char * get_sub_string3(char *str, int i, int j){
	if (str == NULL || *str == '\0')
		return NULL;
	else {
		int len = string_len3(str);
		if (j >= len || i < 0 || i > j)
			return NULL;
		char* substr = (char*)calloc(j - i + 2, sizeof(char));
		char *s = substr;
		while (i <= j) *s++ = *(str + i++);
		*s = '\0';
		return substr;
	}
}
int cmpstrs(char* s1, char* s2) {
	if (s1 == NULL)
		return *s2;
	else if (s2 == NULL)
		return *s1;
	else {
		while (*s1 != '\0' && *s2 != '\0' && *s1 - *s2 == 0) {
			s1++; s2++;
		}
		return *s1 - *s2;
	}
}
int count_word_in_str_way_1(char *str, char *word){
	char *s = str, *_s = word;
	unsigned int count = 0;
	while (*s) {
		if (*s == *_s && cmpstrs(_s, get_sub_string3(str, s - str, s - str + string_len3(word) - 1)) == 0)
			++count;
		s++;
	}
	return count;
}
int count_word_int_str_way_2_recursion(char *str, char *word, unsigned int count) {
	char *s = str, *_s = word;
	if (*s == '\0')
		return count;
	if (*s == *_s && cmpstrs(_s, get_sub_string3(str, s - str, s - str + string_len3(word) - 1)) == 0)
			++count;
	s++;
	return count_word_int_str_way_2_recursion(s, word, count);
}

