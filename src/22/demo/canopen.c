/**
 * Created by Linus Zhang on 2021/8/24.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *file_name;
    if (argc != 2) {
        printf("usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }
    file_name = argv[1];
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("%s can't be opened\n", file_name);
        exit(EXIT_FAILURE);
    }

    printf("%s can be opened\n", file_name);
    fclose(fp);

    return 0;
}