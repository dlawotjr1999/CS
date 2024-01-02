#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char *tmpnam(char *s);
// 인자가 있으면 해당 인자가 가리키는 곳에 임시 파일명 저장
// 인자가 NULL이면 임시 파일명 리턴

// char *mktemp(char *template);
// 임시 파일의 템플릿을 인자로 받아 임시 파일명으로 변환하여 리턴
// 인자로 지정하는 템플릿은 대문자 X 6개로 마쳐야 함

// 보안 문제로 인해 컴파일 불

int main(void)
{
	char *fname;
	char fntmp[BUFSIZ];
	char template[32];

	fname = tmpnam(NULL); // 임시 파일의 이름 생성
	printf("1. TMP File Name(tmpnam) : %s\n", fname);

	tmpnam(fntmp);
	printf("2. TMP File Name(tmpnam) : %s\n", fntmp);

	strcpy(template, "/tmp/testXXXXXX");
	fname = mktemp(template);
	printf("3. TMP File Name(mktemp) : %s\n", fname);
}
