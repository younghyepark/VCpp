#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>  

using namespace std;

int main() {
    while (true) {
        bool upKeyPressed = false;
        bool downKeyPressed = false;
        bool leftKeyPressed = false;
        bool rightKeyPressed = false;
        int consecutiveRightKeyPresses = 0; // 연속으로 누른 오른쪽 화살표 키의 횟수를 기록.
        bool upRightSequenceDetected = false; // "위" 키를 누른 후 "오른쪽" 키를 누른 시퀀스를 감지.

        printf("방향키를 입력하세요>\n");

        auto startTime = chrono::high_resolution_clock::now();
        auto lastKeyPressedTime = startTime;

        while (true) {
            if (_kbhit()) {
                char key = _getch();

                if (key == 0xE0 || key == 0) {  // 특수 키 (0xE0 또는 0) 확인

                    key = _getch();
                    switch (key) {
                    case 72:
                        upKeyPressed = true;
                        if (rightKeyPressed) {
                            consecutiveRightKeyPresses = 0;
                            upRightSequenceDetected = true;
                        }
                        break;

                    case 80:
                        downKeyPressed = true;
                        break;

                    case 75:
                        leftKeyPressed = true;
                        break;

                    case 77:
                        if (rightKeyPressed) {
                            consecutiveRightKeyPresses++;
                            if (consecutiveRightKeyPresses == 2) {
                                printf("쉬고싶다\n");
                                consecutiveRightKeyPresses = 0;
                            }
                        }
                        else {
                            consecutiveRightKeyPresses = 1;
                        }
                        upRightSequenceDetected = false;
                        rightKeyPressed = true;
                        break;

                    default:

                        break;
                    }
                }
                else if (key == 27) {

                    printf("프로그램을 종료합니다.\n");
                    return 0;
                }
                else {

                    printf("방향키가 아닌 것을 인식함: %c\n", key);
                }

                lastKeyPressedTime = chrono::high_resolution_clock::now();

                if ((upKeyPressed && downKeyPressed) || (leftKeyPressed && rightKeyPressed)) {
                    if (upKeyPressed && downKeyPressed) {
                        printf("피곤해!\n");
                    }
                    else {
                        printf("졸려~ \n");
                    }
                    upKeyPressed = false;
                    downKeyPressed = false;
                    leftKeyPressed = false;
                    rightKeyPressed = false;
                }

                if (upRightSequenceDetected && key != 77) {
                    upRightSequenceDetected = false;
                }
            }

            auto currentTime = chrono::high_resolution_clock::now();
            if (chrono::duration_cast<chrono::seconds>(currentTime - startTime).count() >= 3) {
                printf("3초가 지나서 프로그램을 종료합니다\n");
                return 0;
            }

            this_thread::sleep_for(chrono::milliseconds(30));
        }
    }
}
