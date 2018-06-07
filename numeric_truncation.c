#include <limits.h>
#include <string.h>

/**
 * https://cwe.mitre.org/data/definitions/197.html
 */
int main() {
    unsigned int first_len = UINT_MAX - 256;
    unsigned int second_len = 256;
    unsigned int buf_len = 256;

    char first[first_len], second[second_len], buf[buf_len];
    int new_len = (first_len+second_len); // <- IDB (negative)

    if(new_len <= 256) {
        memcpy(buf, first, first_len);
        memcpy(buf + first_len, second, second_len);
    }
}