#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include "TeamLead.hpp"
#include <iostream>
Developer::Developer(const std::string& name)
{
	this->name = name;
	this->salary = 0;
	this->leader = nullptr;
}
/*Developer::~Developer()
{
	this->leader = nullptr;
	delete this->leader;
}*/
Developer& Developer::operator=(const Developer& input)
{
	if (this != &input)
	{
		delete this->leader;
		this->name = input.name;
		this->salary = input.salary;
		this->leader = new TeamLead();
	}
	return *this;
}
Developer::Developer(const Developer& input)
{
	this->name = input.name;
	this->salary = input.salary;
	*this->leader = *input.getTeamLead();
}
std::string Developer::getName()const
{
	return this->name;
}
double Developer::getSalary()const
{
	return this->salary;
}
TeamLead* Developer::getTeamLead()const
{
	return this->leader;
}
void Developer::setLeader(TeamLead* input)
{
	this->leader = input;
}
void Developer::setLeaderNull()
{
	this->leader = nullptr;
}
void Developer::setInitialSalary(double amount)
{
	if (this->salary == 0)
	{
		this->salary = amount;
	}
}
void Developer::sendLeavingRequest()
{
	LeavingRequest curr(this->name);
	if (this->leader != nullptr)
	{
		this->leader->addLeavingRequest(curr);
		curr.decreaseCounter();
	}
	
}
void Developer::sendPromotionRequest(double amount)
{
	PromotionRequest curr(this->name, amount);
	if (this->leader != nullptr)
	{
		this->leader->addPromotionRequest(curr);
		curr.decreaseCounter();
	}
}
void Developer::setSalary(const double input)
{
	this->salary = input;
}