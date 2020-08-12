#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {

	char *a = b;

    while(len--) {
        *a++ = c;
    }

    return a;
}

// int main() {
// 	char *str = mx_strnew(5);
// 	for (int i = 0; i < 5; ++i) {
// 		str[i] = 'r';
// 	}
// 	printf("%s\n", str);
// 	mx_memset(str, '%', 4);
// 	printf("%s\n", str);
// 	return 0;
// }
