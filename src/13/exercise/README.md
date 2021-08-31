### 13.3节

#### 1

(b) printf("%c", '\n'); or printf("%s", "\n");

(c) 同上

(e) putchar('\n');

(h) putchar('\n');

(i) puts("\n");


#### 18

```c
void remove_filename(char *url) {
    char *p = url;
    while (*url) {
        if (*url == '/')
            p = url;
            url++;
    }
    *p = '\0';
}
```