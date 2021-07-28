/*
* 使用getchar + putchar 
* 
*/
#include <stdio.h>

int main(void)
{
	int ch;
	while((ch = getchar()) != EOF) { //在命令行首按ctrl+z也代表EOF
		putchar(ch);
	}
	return 0;
}
 
