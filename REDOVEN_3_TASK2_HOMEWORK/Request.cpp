#include "Request.hpp"
int Request::counter = 0;
Request::Request(const std::string& message, const std::string& sender)
{
	this->message = message;
	this->sender = sender;
	this->counter++;
	this->ID = this->counter;
}

std::string Request::getMessage()const
{
	return this->message;
}
std::string Request::getSender() const
{
	return this->sender;
}
int Request::getCount() const
{
	return this->counter;
}
int Request::getID() const
{
	return this->ID;
}
void Request::decreaseCounter()   //my func
{
	this->counter--;
}