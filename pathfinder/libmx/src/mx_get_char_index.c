#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	if (!str) {
		return -2;
	}

	int len = mx_strlen(str);

	for (int i = 0; i < len; ++i) {
		if (str[i] == c) {
			return i;
		}
	}

	return -1;
}

// int main() {
// 	char *str = "hello";
// 	printf("%d\n", mx_get_char_index(str, 'l'));
// 	return 0;
// }
