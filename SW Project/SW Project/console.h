#ifndef __CONSOLE_H__
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void cursorType(CURSOR_TYPE c);
int getKey();
int keySetting();
#define __CONSOLE_H__

#endif

