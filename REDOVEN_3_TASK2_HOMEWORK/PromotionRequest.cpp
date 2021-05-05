#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const std::string& sender, double amount):Request("I want a raise!",sender)
{
	this->amount = amount;
}

double PromotionRequest::getAmount()const
{
	return this->amount;
}