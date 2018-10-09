#ifndef __CONSOLE_H__
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void cursorType(CURSOR_TYPE c);
int getKey();
int keySetting();
void userKeySetting();
struct _inputKey {
	int blueUp;
	int blueDown;
	int whiteUp;
	int whiteDown;
} inputKey;
#define __CONSOLE_H__

#endif

