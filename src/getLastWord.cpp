/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
int string_len2(char* str) {
	if (*str == '\0')
		return 0;
	char* s = str;
	while (*++s);
	return s - str;
}
void trim(char* str) {
	if (*str == '\0')
		return;
	while (*str == ' ') str++;
	char* s = str + string_len2(str) - 1;
	while (*s == ' ') s--;
	*++s = '\0';
}
char * get_sub_string2(char *str, int i, int j){
	if (str == NULL || *str == '\0')
		return NULL;
	else {
		int len = string_len2(str);
		if (j >= len || i < 0 || i > j)
			return NULL;
		char* substr = (char*)calloc(j - i + 2, sizeof(char));
		char *s = substr;
		while (i <= j) *s++ = *(str + i++);
		*s = '\0';
		return substr;
	}
}
char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	else {
		int i = 0;
		char* dup_str = (char*)calloc(string_len2(str) + 1, sizeof(char)), *s = dup_str, *_s = str;
		while (*_s) *s++ = *_s++;
		*s = '\0';
		trim(dup_str);
		if (string_len2(dup_str) == 0)
			return "";		
		s = dup_str + string_len2(dup_str), _s = --s;
		while (*s != ' ' && s >= dup_str) s--;
		return get_sub_string2(dup_str, ++s - dup_str, _s - dup_str);
	}
}