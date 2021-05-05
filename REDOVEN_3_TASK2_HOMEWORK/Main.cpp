#include "Developer.hpp"
#include "TeamLead.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <iostream>
int main()
{
	Request rec1("speed100", "golfer");
	LeavingRequest leave1("seater");
	std::cout << rec1.getCount();
	return 1; 
}