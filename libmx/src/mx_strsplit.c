 #include "libmx.h"

char **mx_strsplit(const char *s, char c) {
	char *word = "";
	s = s + c;

	int len = mx_strlen(s);
	char **str = malloc(len);

	for (int i = 0; i < len; i++)
	{
		if (s[i] != c) {
			word += s[i];
		}
		else {
			int l = mx_strlen(word);
			if (l != 0)
			{
				str[i] = word;
			}
			word = "";
		}
	}
	str[len - 1] = NULL;
	return str; 
}
