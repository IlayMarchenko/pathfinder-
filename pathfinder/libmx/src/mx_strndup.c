#include "libmx.h"

/**
 * @brief but copies at most n bytes.  If s is  longer  than  n,  only  n  bytes  are
          copied, and a terminating null byte ('\0') is added.
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 */
char *mx_strndup(const char *s1, size_t n) {
    char *new_str = mx_strnew(n);

    if (new_str == NULL || s1 == NULL) return NULL;

    mx_strncpy(new_str, s1, n);
    return new_str;
}
