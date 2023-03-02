/**
 * _strncat - Concatenates two strings up to n bytes.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 * @n: The maximum number of bytes to copy from src.
 *
 * Return: A pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *start = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0' && n > 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';

    return start;
}
