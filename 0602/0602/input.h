#pragma once
#include <string.h>
#include <Windows.h>
typedef unsigned char      uint8_t;
typedef uint8_t			uint8;
#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))

class input
{
public:

	input() = delete;
	~input() = delete;
	input(const input&) = delete;
	input& operator=(const input&) = delete;

	static void Input_Update(void)
	{
		memcpy(s_isKeyDownOnPrevFrame, s_isKeyDownOnCurrentFrame, sizeof(s_isKeyDownOnCurrentFrame));

		for (int vkey = 0; vkey < 256; ++vkey)
		{
			if (IS_KEY_DOWN(vkey))
			{
				s_isKeyDownOnCurrentFrame[vkey] = true;
			}
			else
			{
				s_isKeyDownOnCurrentFrame[vkey] = false;
			}
		}
	}

	static bool Input_GetKeyDown(uint8 vkey)
	{
		if (false == s_isKeyDownOnPrevFrame[vkey] && true == s_isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Input_GetKeyUp(uint8 vkey)
	{
		if (true == s_isKeyDownOnPrevFrame[vkey] && false == s_isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool Input_GetKey(uint8 vkey)
	{
		if (true == s_isKeyDownOnPrevFrame[vkey] && true == s_isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	static bool s_isKeyDownOnPrevFrame[256];
	static bool s_isKeyDownOnCurrentFrame[256];
};