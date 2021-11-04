#include "random/randomizer.h"

ygl::random::randomizer::randomizer()
{
	this->_randomer.seed((unsigned long long int)time(NULL));
	srand((unsigned long long int) time(NULL));
}

ygl::random::randomizer::~randomizer()
{
}

void ygl::random::randomizer::seed()
{
	this->_randomer.seed((unsigned long long int)time(NULL));
}

