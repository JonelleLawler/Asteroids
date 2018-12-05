#pragma once
#include<iostream>
#include <SFML\Graphics.hpp>
// @author: Jonelle Lawler, David Whiteford

class Currency
{
public:
	
	Currency();
	~Currency();

	int startingCurrency{};


	// 
	void alienShot();

	int getCurrency();

	void setCurrency(int newCurrency);

	



	

private:
};