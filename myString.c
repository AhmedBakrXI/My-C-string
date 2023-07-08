#include "myString.h"

char *my_strcat(char *dest, char *src) {
    char *str = dest;
    while (*str != '\0') {
        str++;
    }

    while (*src != '\0') {
        *str = *src;
        str++;
        src++;
    }

    *str = '\0';
    return dest;
}


char *my_strchr(const char *str, int c) {
    while (*str != c) {
        str++;
    }
    return str;
}


int my_strcmp(const char *str1, const char *str2) {
    for (int i = 0; *str1 != '\0'; i++) {
        if (*str1 == *str2) {
            continue;
        } else if (*str1 > *str2) {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}

char *my_strcpy(char *destination, const char *source) {
    int i;
    for (i = 0; *source != '\0'; i++) {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';

    for (int j = i; j >= 0; j--) {
        destination--;
    }
    return destination;
}

int my_strncmp(const char *str1, const char *str2, unsigned int n) {
    register unsigned char u1, u2;

    while (n > 0)
    {
        u1 = (unsigned char) *str1++;
        u2 = (unsigned char) *str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
        n--;
    }
    return 0;
}

char *my_strncat(char *dest, const char *src, unsigned int n) {
    char *temp = dest;
    while (*temp != NULL) {
        temp++;
    }

    for (int i = 0; i < n; i++) {
        *temp = *src;
        temp++;
        src++;
    }

    return dest;
}


unsigned int my_strlen(const char *str) {
    int i;
    for (i = 0; *str != '\0'; i++) {
        str++;
    }
    return i;
}

unsigned int my_strcspn(const char *str1, const char *str2) {
    int retIndex = 0;

    for (int str2Index = 0; str2Index < my_strlen(str2); str2Index++) {
        for (int str1Index = 0; str1Index < my_strlen(str1); str1Index++) {
            if (str2[str2Index] == str1[str1Index]) {
                return retIndex;
            }
            retIndex++;
        }
    }

    return retIndex;
}

unsigned int my_strxfrm(char *dest, const char *src, unsigned int n) {
    my_memcpy(dest, src, n);
    return my_strlen(src);
}


void *my_memchr(const void *str, int c, unsigned int size) {
    char *p = str;
    for (int i = 0; i < size; i++) {
        if (*p == c) {
            return p;
        }
        p++;
    }
    return NULL;
}

char *my_strpbrk(const char *str1, const char *str2) {
    char *p = NULL;

    for (int i = 0; i < my_strlen(str1); i++) {
        for (int j = 0; j < my_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                p = &str1[i];
                return p;
            }
        }
    }

    return p;
}

unsigned int my_strspn(const char *str1, const char *str2) {
    unsigned int count = 0;

    for (int i = 0; i < my_strlen(str1); i++) {
        for (int j = 0; j < my_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                for (int k = 0; k < my_strlen(str1); k++) {

                    if (str1[i + k] != str2[j + k]) {
                        return (count);
                    }
                    count++;
                }
            }
        }
    }
    return count;
}

char *my_strstr(const char *haystack, const char *needle) {
    unsigned int needle_len = my_strlen(needle);

    while (*haystack) {
        if (my_strncmp(haystack, needle, needle_len) == 0) {
            return (char *) haystack;
        }
        haystack++;
    }

    return NULL;
}


unsigned char my_memset(unsigned char *ptr, unsigned char fill, int len) {
    unsigned char RetVal = 0;

    if (NULL == ptr || len < 0) {
        RetVal = 1;
    } else {
        unsigned int index = 0;
        for (index = 0; index < len; index++) {
            *ptr = fill;
            ptr++;
        }
    }

    return RetVal;
}

unsigned char my_memcpy(unsigned char *dest, unsigned char *src, int len) {
    unsigned char RetVal = 0;

    if (NULL == dest || len < 0 || len > my_strlen(dest)) {
        RetVal = 1;
    } else {
        unsigned int index = 0;
        for (index = 0; index < len; index++) {
            *dest = *src;
            src++;
            dest++;
        }
    }

    return RetVal;
}

unsigned char my_memmove(unsigned char *dest, unsigned char *src, int len) {
    unsigned char RetVal = 0;

    if (NULL == dest || len < 0 || len > my_strlen(dest)) {
        RetVal = 1;
    } else {
        unsigned int index = 0;
        for (index = 0; index < len; index++) {
            *dest = *src;
            src++;
            dest++;
        }
    }

    return RetVal;
}

int my_memcmp(const void *str1, const void *str2, unsigned int len) {
    unsigned char *s1 = str1;
    unsigned char *s2 = str2;
    int retstate = 0;

    if (str1 == NULL || str2 == NULL) {
        retstate = 404; // error
    } else {
        while (len--) {
            if (*s1 != *s2) {
                retstate = *s1 < *s2 ? -1 : 1;
                break;
            } else {
                s1++;
                s2++;
            }
        }
    }
    return retstate;
}


char *my_strtok(char *str, const char *delim) {
    static char *nextToken = NULL;
    char *result;

    if (str != NULL) {
        nextToken = str;
    }

    if (nextToken == NULL || *nextToken == '\0') {
        return NULL;
    }
    result = nextToken;
    nextToken = my_strpbrk(nextToken, delim);

    if (nextToken != NULL) {
        *nextToken = '\0';
        nextToken++;
    }

    return result;
}
