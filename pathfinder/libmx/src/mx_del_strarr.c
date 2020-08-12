#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **del_arr = NULL;

    if (!arr || !(*arr))
        return;

    del_arr = *arr;

    while (*del_arr) {
        mx_strdel(del_arr);
        del_arr++;
    }
    free(*arr);
    *arr = NULL;
}


//int main() {
//
// 	char **arr = (char **)malloc(sizeof(char *) * 4);
// 	for(int i = 0; i < 3; i++) {
//     	arr[i] = mx_strnew(5);
// 	}
// 	arr[0] = mx_strcpy(arr[0], "hello");
// 	arr[1] = mx_strcpy(arr[1], "rello");;
// 	arr[2] = mx_strcpy(arr[2], "mello");
// 	arr[3] = NULL;
// 	mx_del_strarr(&arr);
// 	system("leaks -q untitled");
//
// 	return 0;
// }
