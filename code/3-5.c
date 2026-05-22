#include <stdio.h>

int main(int argc, const char* argv[]){
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
        return 0;
    
    int sum = 0;
    int num;
    char invalid[64];

    while (!feof(fp)) {
        if (fscanf(fp, "%d", &num) == 1)
            sum += num;
        else if (fscanf(fp, "%s", invalid) == 1)
            fprintf(stderr, "invalid input %s\n", invalid);
    }

    printf("sum : %d\n", sum);
    fclose(fp);
    return 0;
}
