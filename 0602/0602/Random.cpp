#include "Random.h"


void Random::Init(void)
{
	srand(time(NULL));
}

int Random::GetNumberFromRange(int minInclusive, int maxExclusive)
{
	float normalizedRandom = rand() / (float)(RAND_MAX - 1);
	int range = maxExclusive - minInclusive;
	int result = minInclusive + normalizedRandom * range;

	return result;
}

float Random::GetFNumberFromRange(float minInclusive, float maxInclusive)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = maxInclusive - minInclusive;
	float result = minInclusive + normalizedRandom * range;

	return result;
}