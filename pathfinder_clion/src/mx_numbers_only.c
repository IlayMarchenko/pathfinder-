#include "pathfinder.h"

void mx_numbers_only(char *string) {
    int count = 0;
    while (*string != '\0') {
        if (!mx_is_number(*string)) {
            *string = ' ';
        }
        string++;
        count++;
    }
    string -= count;
}
