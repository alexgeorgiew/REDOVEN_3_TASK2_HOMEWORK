#pragma once


#include <string>

class Request {
	
public:
	Request(const std::string& message, const std::string& sender);
	std::string getMessage()const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;

	void decreaseCounter(); //my func
protected:
	std::string message,sender;
	int ID;
	static int counter;
};

