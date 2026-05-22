#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config{
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr){
   FILE* fp = fopen("config.txt", "r");
    char k[64], v[64];
    while (fscanf(fp, "%[^=]=%s\n", k, v) == 2) {
        if (!strcmp(k, "InputFileName")) strcpy(config_ptr->InputFileName, v);
        else if (!strcmp(k, "Options")) config_ptr->Options = atoi(v);
        else if (!strcmp(k, "SectionName")) strcpy(config_ptr->SectionName, v);
        else if (!strcmp(k, "Address")) config_ptr->Address = strtoull(v, NULL, 16);
    }
    fclose(fp);
}

int main(int argc, const char* argv[]){
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n",
        config.InputFileName,
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}
