#ifndef MYSTRING_H
#define MYSTRING_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

char *my_strcat(char *dest, char *src);

char *my_strchr(const char *str, int c);

int my_strcmp(const char *str1, const char *str2);

char *my_strcpy(char *destination, const char *source);

int my_strncmp(const char *str1, const char *str2, unsigned int n);

char *my_strncat(char *dest, const char *src, unsigned int n);

unsigned int my_strlen(const char *str);

unsigned int my_strcspn(const char *str1, const char *str2);

char *my_strpbrk(const char *str1, const char *str2);

unsigned int my_strspn(const char *str1, const char *str2);

unsigned int my_strxfrm(char *dest, const char *src, unsigned int n);

char *my_strstr(const char *haystack, const char *needle);

void *my_memchr(const void *str, int c, unsigned int size);

unsigned char my_memset(unsigned char *ptr, unsigned char fill, int len);

unsigned char my_memcpy(unsigned char *dest, unsigned char *src, int len);

int my_memcmp(const void *str1, const void *str2, unsigned int len);

unsigned char my_memmove(unsigned char *dest, unsigned char *src, int len);

char *my_strtok(char *str, const char *delim);

#endif //MYSTRING_H
