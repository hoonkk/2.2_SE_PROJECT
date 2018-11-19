#ifndef __CONSOLE_H__

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void cursorType(CURSOR_TYPE c);
int getKey();
int keySetting();
void userKeySetting();
void gotoxy(int x, int y);
void textcolor(int color_number);
void initialShow();
void updateShow();
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
	char *_frontQuestion[1];
	char *_backQuestion[1];
	char *_blueOrWhite[2];

} stageStatus;

#define __CONSOLE_H__

#endif