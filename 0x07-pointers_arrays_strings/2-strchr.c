char *_strchr(char *s, char c)
{
    while (*s != '\0' && *s != c) {
        s++;
    }

    if (*s == c) {
        return s;
    } else {
        return NULL;
    }
}
