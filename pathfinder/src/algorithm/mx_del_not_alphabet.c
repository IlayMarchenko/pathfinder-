#include "pathfinder.h"

void mx_del_not_alphabet(char *string) {
    int count = 0;
    while (*string != '\0') {
        if (!mx_in_alphabet(*string)) {
            *string = ' ';
        }
        string++;
        count++;
    }
    string -= count;
}
