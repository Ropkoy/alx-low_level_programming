unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; accept[j] != '\0'; j++) {
            if (s[i] == accept[j]) {
                count++;
                break;
            }
        }
        if (accept[j] == '\0') {
            break;
        }
    }
    return count;
}
