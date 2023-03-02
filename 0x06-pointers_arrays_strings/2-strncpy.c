/**
 * _strncpy - Copies a string up to n bytes.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *start = dest;

    while (*src != '\0' && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    while (n > 0)
    {
        *dest = '\0';
        dest++;
        n--;
    }

    return start;
}
