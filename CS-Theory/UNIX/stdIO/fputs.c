#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *rfp, *wfp;
	char buf[BUFSIZ];

	if((rfp = fopen("test.txt", "r")) == NULL) {
		perror("fopen");
		exit(1);
	}

	if((wfp = fopen("test.txt", "a")) == NULL) {
		perror("fopen");
		exit(1);
	}

	while(fgets(buf, BUFSIZ, rfp) != NULL) {
		fputs(buf, wfp);
	}

	fclose(rfp);
	fclose(wfp);
}
