/**
 * Created by Linus Zhang on 2021/8/7.
 */
#include <stdio.h>
#include <string.h>

void remove_filename(char *url) {

    char *p = url;
    while (*url) {
        if (*url == '/')
            p = url;
        url++;
    }
    *p = '\0';
}