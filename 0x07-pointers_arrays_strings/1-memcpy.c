char *_memcpy(char *dest, char *src, unsigned int n)
{
    char *pdest = dest;
    char *psrc = src;

    while (n-- > 0) {
        *pdest++ = *psrc++;
    }

    return dest;
}
