### 13.3θ

#### 1

(b) printf("%c", '\n'); or printf("%s", "\n");

(c) εδΈ

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