/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to look for
 *
 * Return: a pointer to the beginning of the substring in the haystack,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
    int i, j;

    for (i = 0; haystack[i]; i++)
    {
        for (j = 0; needle[j] && haystack[i + j] == needle[j]; j++)
            ;

        if (needle[j] == '\0')
            return (haystack + i);
    }

    return (NULL);
}
