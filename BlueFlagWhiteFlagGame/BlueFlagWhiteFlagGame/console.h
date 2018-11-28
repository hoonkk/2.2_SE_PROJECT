#ifndef __CONSOLE_H__
#include <stdbool.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void cursorType(CURSOR_TYPE c);
int getKey();
int keySetting();
void userKeySetting();
void gotoxy(int x, int y);
void textcolor(int color_number);
void initialShow();
void updateShow();
void printMenu();
void printCharactor(int emotion);
void printDot(int number);
void printBlank(int num);
void moveFlag(int flagSwitch);
void clearFlag();
void pause();
void settingWarning();
void printKeyboard();
bool keyUseable(int inputKey);
struct _inputKey {
	int blueUp;
	int blueDown;
	int whiteUp;
	int whiteDown;
} inputKey;

struct _stageStatus {
	int stage;
	int score;
	int life;
	double time;
	char *_frontQuestion[1];
	char *_backQuestion[1];
	char *_blueOrWhite[2];
} stageStatus;

#define DEFAULT 0
#define HAPPY 1
#define SAD 2
#define TRUE 1
#define FALSE 0

#define __CONSOLE_H__

#endif