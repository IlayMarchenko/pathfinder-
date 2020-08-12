#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int words_count = mx_count_words(s, c);
    char **arr = malloc(sizeof(char *) * words_count);

    int substr_len = 0;
    int words = 0;

    for (int i = 0; words != words_count; substr_len = 0) {
        // Delete first part
        while (s[i] == c)
            s++;
        // Stop on last
        while (s[i++] != c)
            substr_len++;
        arr[words] = mx_strnew(substr_len - 1);
        mx_strncpy(arr[words], s, substr_len);
        s += substr_len; // Move pointer to correct position
        words++;
        i = 0;
    }
    return arr;
}

