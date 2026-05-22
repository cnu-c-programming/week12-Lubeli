#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]){
    const char **p = envp;

    while(*p != NULL){
        printf("%s\n",*p);
        p++;
    }

    return 0;
}
