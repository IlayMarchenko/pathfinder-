#include "libmx.h"

/**
 *  functionmx_memrchr, which is similar to the functionmx_memchr,
 *  except thatit searches in the opposite direction from
 *  the end of the bytesn  points tos  insteadof directly from the beginning
 */
void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *string = (unsigned char *)s;

    while (n)
        if (string[--n] == (unsigned char)c)
            return string + n;

    return NULL;
}
