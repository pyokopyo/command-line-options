#include <stdio.h>
#include <limits.h>
#include <string.h>

#define ARG_COUNT ((sizeof com)/(sizeof(struct comIn)))

struct comIn {
	char argvOptId[UCHAR_MAX];
	char argvOpt[UCHAR_MAX];
};

comIn com[] = {
		{"-a", "-aaaaa"},
		{"-b", "-bbbbb"},
		{"-c", "-ccccc"},
		{"-h", "-hhhhh"}
};

void DisplayHelp4Options() {

	//help表示
	printf("\n-------------------------\n");
	printf(" Help");
	printf("\n-------------------------\n");

	for (int i = 0; i < ARG_COUNT; ++i) {
		printf("%s=%s\n", com[i].argvOptId, com[i].argvOpt);
	}

}

int main(int argc, char* argv[])
{

	for (int i = 0; i < argc; ++i) {
		if (*argv[i] == '-') {
			switch (*(argv[i] + 1)) {
			case 'h':
				DisplayHelp4Options();
				return 0;
			}
		}
	}

	for (int i = 0; i < argc; ++i) {
		if (*argv[i] == '-') {
			switch (*(argv[i] + 1)) {
			case 'a':
				strcpy_s(com[0].argvOpt, UCHAR_MAX, argv[i + 1]);
				break;
			case 'b':
				strcpy_s(com[1].argvOpt, UCHAR_MAX, argv[i + 1]);
				break;
			case 'c':
				strcpy_s(com[2].argvOpt, UCHAR_MAX, argv[i + 1]);
				break;
			default:
				printf("OPTION ERROR argN=%d(%s)\n", i ,argv[i]);
			}
		}
	}

	//使用オプション表示
	printf("\n-------------------------\n");
	printf(" Option");
	printf("\n-------------------------\n");
	printf("argc=%d\n", argc);
	printf("argv=\n");

	for (int i = 0; i < ARG_COUNT; ++i) {
		if (*(com[i].argvOpt) != '-') {
			printf(" %s=%s\n", com[i].argvOptId, com[i].argvOpt);
		}
	}
}