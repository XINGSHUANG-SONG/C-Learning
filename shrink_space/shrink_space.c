#include <stdio.h>
#include <stdbool.h>

char *shrink_space(char *dest, const char *src, size_t n){
    size_t j = 0;
    bool in_space = false;
    for (size_t i = 0; j < n - 1; i++) {
        if (src[i] == '\0')
            break;
        if (src[i] == ' '
            || src[i] == '\n'
            || src[i] == '\t'
            || src[i] == '\r') {
                if (!in_space)
                    dest[j++] = ' ';
                in_space = true;
        } else {
            dest[j++] = src[i];
            in_space = false;
        }
    }
    if (n != 0)
        dest[j] = '\0';
    return dest;
}
int main(void){
    char src[] = 
        "This Content hoho       is ok\n"
        "        ok?\n"
        "\n"
        "        file system\n"
        "uttered words   ok ok      ?\n"
        "end.";
    char dest[sizeof(src)];
    printf("%s\n", shrink_space(dest, src, sizeof(src)));
    return 0;
}