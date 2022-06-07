#pragma once

#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
#define COMMON_LVB_LEADING_BYTE    0x0100 // Leading Byte of DBCS
#define COMMON_LVB_TRAILING_BYTE   0x0200 // Trailing Byte of DBCS
#define COMMON_LVB_GRID_HORIZONTAL 0x0400 // DBCS: Grid attribute: top horizontal.
#define COMMON_LVB_GRID_LVERTICAL  0x0800 // DBCS: Grid attribute: left vertical.
#define COMMON_LVB_GRID_RVERTICAL  0x1000 // DBCS: Grid attribute: right vertical.
#define COMMON_LVB_REVERSE_VIDEO   0x4000 // DBCS: Reverse fore/back ground attribute.
#define COMMON_LVB_UNDERSCORE      0x8000 // DBCS: Underscore.

#include <Windows.h>

class Text
{
public:
    enum Color
    {
        TEXT_COLOR_BLACK,
        TEXT_COLOR_BLUE = FOREGROUND_BLUE,
        TEXT_COLOR_RED = FOREGROUND_RED,
        TEXT_COLOR_GREEN = FOREGROUND_GREEN,
        TEXT_COLOR_CYAN = TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
        TEXT_COLOR_MAGENTA = TEXT_COLOR_RED | TEXT_COLOR_BLUE,
        TEXT_COLOR_YELLOW = TEXT_COLOR_RED | TEXT_COLOR_GREEN,
        TEXT_COLOR_WHITE = TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
        TEXT_COLOR_STRONG = FOREGROUND_INTENSITY
    };
    enum BackgroundColor
    {
        BACK_COLOR_BLACK,
        BACK_COLOR_BLUE = BACKGROUND_BLUE,
        BACK_COLOR_RED = BACKGROUND_RED,
        BACK_COLOR_GREEN = BACKGROUND_GREEN,
        BACK_COLOR_CYAN = BACK_COLOR_BLUE | BACK_COLOR_GREEN,
        BACK_COLOR_MAGENTA = BACK_COLOR_RED | BACK_COLOR_BLUE,
        BACK_COLOR_YELLOW = BACK_COLOR_RED | BACK_COLOR_GREEN,
        BACK_COLOR_WHITE = BACK_COLOR_RED | BACK_COLOR_BLUE | BACK_COLOR_GREEN,
        BACK_COLOR_STRONG = BACKGROUND_INTENSITY
    };
public:

    static void Copy(Text* dest, const WCHAR* src, WORD attributes)
    {
        while (*src)
        {
            dest->_info.Char.UnicodeChar = *src;
            dest->_info.Attributes = attributes;
            ++dest;
            ++src;
        }
        dest->_info.Char.UnicodeChar = L'\0';
        dest->_info.Attributes = 0;
    }

    static void Copy(Text* dest, const WCHAR* src)
    {
        Copy(dest, src, TEXT_COLOR_WHITE);
    }

    static int GetLength(const Text* text)
    {
        int result = 0;
        while (text->_info.Char.UnicodeChar)
        {
            ++result;
            ++text;
        }
        return result;
    }
private:
    CHAR_INFO   _info = { 0 };
};
//// 이전
//Text text[16];
//TextCopyWithWhite(text, L"Hello World");
//// 이후
//Text text[16];
//Text::Copy(text, L"Hello World");
