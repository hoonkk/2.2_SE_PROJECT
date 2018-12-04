#ifndef __CONSOLE_H__
#include <stdbool.h>


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;


int getKey();

int keySetting();

void playSound(int soundIndex);

void userKeySetting();

void gotoxy(int x, int y);
void cursorType(CURSOR_TYPE c);
void textcolor(int color_number);

void initialShow();
void updateShow();
void printCharactor(int emotion);

void printDot(int number);
void printDot_(int number);
void printBlank(int num);

void moveFlag(int flagSwitch);
void clearFlag();
void settingWarning();
void printKeyboard();

void printTheme();
void gameIntro();
void printMenu();
int choiceMenu();
void menuSlide();
void initialScreen();

void pause();


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

#define ENTER 13
#define SPACEBAR 32

#define MISS 1
#define GAMEOVER 5
#define GOOD 6
#define CLEAR 8

#define FONT_BLUE 1
#define FONT_GREEN 2
#define FONT_CYAN 3
#define FONT_RED 4
#define FONT_PURPLE 5
#define FONT_YELLOW 6
#define FONT_WHITE 7
#define FONT_GRAY 8

#define __CONSOLE_H__

#endif