/**
 * uppercase - Changes all lowercase letters of a string to uppercase.
 * @s: A pointer to the string to be converted.
 */
void uppercase(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= 'a' && s[i] <= 'z')
{
s[i] = s[i] - 32;
}
}
}
