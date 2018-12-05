#pragma once 
#include "Currency.h"
// @author: Jonelle Lawler, David Whiteford
Currency::Currency()
{
	int startingCurrency = 100;

}

Currency::~Currency()
{
}


// Adds to starting currency - shoot an alien, gain money
void Currency::alienShot()
{
	startingCurrency += 200;
}
void Currency::setCurrency(int newCurrency)
{
	startingCurrency = newCurrency;
}
int Currency::getCurrency()
{
	return startingCurrency;
}
