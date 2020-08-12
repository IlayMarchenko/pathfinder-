#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {

	if (arr == NULL || delim == NULL) {
		return;
	}

	for (int i = 0; arr[i] != NULL ; i++) {
		mx_printstr(arr[i]);
		if (arr[i + 1] != NULL) {
			mx_printstr(delim);
		}
	}
	write(1, "\n", 1);
}

// int main() {
// 	char *arr1[] = {NULL};
// 	mx_print_strarr(arr1, "");
// 	return 0;
// }
