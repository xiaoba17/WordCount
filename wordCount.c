#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int charnum = 0, wordnum = 0;
    if (argc == 3) {
        if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0) {
            printf("parameter error!\n");
            exit(0);
        }
        if ((fp = fopen(argv[2], "r")) == NULL) {
            printf("file error!\n");
            exit(0);
        }
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == ' ' || ch == ',') {
                wordnum ++;
                charnum ++;
            } else {
                charnum ++;
            }
        }
        if (wordnum != 0)
            wordnum ++;
        fclose(fp);
        if (strcmp(argv[1], "-c") == 0)
            printf("charnum: %d\n", charnum);
        else
            printf("wordnum: %d\n", wordnum);
    } else {
        printf("parameter error!\n");
        exit(0);
    }
    return 0;
}