char *_memset(char *s, char b, unsigned int n)
{
    char *p = s;
    while (n-- > 0) {
        *p++ = b;
    }
    return s;
}
