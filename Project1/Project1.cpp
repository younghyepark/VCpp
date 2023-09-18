#include <stdio.h>
#include <conio.h>
#define ESC 27 

int main()
{
	//프로그램 시작 스플래시 이미지 출력
	printf("\"이은석의 행복한 VC++\"\n");

	char command;
	int exit = 0;
	char input;

	while (!exit) {
		//커맨드 입력 UI 출력
		printf("command> ");

		input = _getche();//키 입력
		_getche();

		switch (input) {
		case 'q':
			printf("\nqwar 화이팅\n");
			break;

		case 'w':
			printf("\n과제 너무 좋다\n");
			break;

		case 'e':
			printf("\n다음주부턴 과제량 3배다\n");
			break;

		case 'r':
			printf("\n행복합니다\n");
			break;

		case 27:
			exit = 1;
			break;

		default:
			printf("\n오류: 다른 글자를 입력하셨습니다.\n");
			break;
		}
	}
	return 0;
}