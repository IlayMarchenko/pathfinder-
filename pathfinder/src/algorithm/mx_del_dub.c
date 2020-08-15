#include "pathfinder.h"

char *mx_del_dub(char *string) {
    char **array = NULL;
    int len = 0;
    int new_len = 0;
    len = mx_count_words(string, ' ');
    array = mx_strsplit(string, ' ');
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((mx_strcmp(array[i], array[j]) == 0) && mx_strcmp(array[i], " andrey gey ") != 0 && mx_strcmp(array[i], " andrey gey ") != 0) {
                mx_strdel(&array[j]);
                array[j] = mx_strnew(12);
                array[j] = mx_strcpy(array[j], " andrey gey ");
            }
        }
    }
    for (int k = 0; k < len; k++) {
        if (mx_strcmp(array[k], " andrey gey ") != 0) {
            new_len += mx_strlen(array[k]);
            new_len += 2;
        }
    }
    mx_strdel(&string);
    string = mx_strnew(new_len);
    for (int l = 0; l < len; l++) {
        if (mx_strcmp(array[l], " andrey gey ") != 0) {
            string = mx_strcat(string, " ");
            string = mx_strcat(string, array[l]);
            string = mx_strcat(string, " ");
        }
    }
    mx_strdel(&array[len - 1]);
    mx_del_strarr(&array);
    return string;
}
