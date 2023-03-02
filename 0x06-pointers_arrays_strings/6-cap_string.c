/**
 * cap_string - Capitalizes all words of a string.
 * @s: A pointer to the string to be converted.
 *
 * Return: A pointer to the resulting string.
 */
char *cap_string(char *s)
{
int i, j;
int capitalize = 1; /* Capitalize the next character */

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
s[i] == ',' || s[i] == ';' || s[i] == '.' ||
s[i] == '!' || s[i] == '?' || s[i] == '"' ||
s[i] == '(' || s[i] == ')' || s[i] == '{' ||
s[i] == '}')
{
capitalize = 1;
}
else if (capitalize)
{
if (s[i] >= 'a' && s[i] <= 'z')
{
s[i] = s[i] - 32;
}
capitalize = 0;
}
}
return s;
}
