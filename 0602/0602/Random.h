#pragma once

#include<stdlib.h>
#include<time.h>

class Random
{
public:

	static void Init();
	static int GetNumberFromRange(int minInclusive, int maxExclusive);
	static float GetFNumberFromRange(float minInclusive, float maxInclusive);

private:

};