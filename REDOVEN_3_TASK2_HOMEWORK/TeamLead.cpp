#include "TeamLead.hpp"
#include <iostream>
TeamLead::TeamLead(const std::string& name, double salary):Developer(name)
{
	this->salary = salary;
	this->leader = this;
}


/*TeamLead::~TeamLead()
{
	for (int i=0;i<this->team.size();i++)
	{
		delete this->team[i];
	}
	this->team.clear();
	
}*/
TeamLead::TeamLead(const TeamLead& input)
{
	this->promotion_requests = input.promotion_requests;
	this->leaving_requests = input.leaving_requests;
	for (int i = 0; i < input.team.size(); i++)
	{
		Developer* local=new Developer(*input.team[i]);
		this->team.push_back(local);
		delete local;
	}
}

TeamLead& TeamLead::operator=(const TeamLead& input)
{
	if (this != &input)
	{
		this->leaving_requests = input.leaving_requests;
		this->promotion_requests = input.promotion_requests;
		for (int i=0;i<this->team.size();i++)
		{
			delete this->team[i];
		}
		this->team.clear();
		for (int i = 0; i < input.team.size(); i++)
		{
			Developer* local = new Developer(*input.team[i]);
			this->team.push_back(local);
			delete local;
		}
	}
	return *this;
}

std::vector<Developer*> TeamLead::getTeam()const
{
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	developer->setSalary(salary);
	developer->setLeader(this);
	this->team.push_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	for (int i = this->team.size()-1; i > -1; --i)
	{
		if (this->team[i]->getName() == name)
		{
			this->team[i]->setLeaderNull();             //// ?????????????????????????
			this->team.erase(this->team.begin() + i);
			 
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < this->team.size(); i++)
	{
		this->team[i]->setSalary(amount + this->team[i]->getSalary());
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	TeamLead::increaseTeamSalariesBy(-amount);
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->leaving_requests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->promotion_requests.push_back(promotionRequest);
}
void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < this->leaving_requests.size(); i++)
	{
		TeamLead::removeDeveloperFromTeam(this->leaving_requests[i].getSender());
	}
	this->leaving_requests.clear();
}
void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < this->promotion_requests.size(); i++)
	{
		TeamLead::increaseTeamSalariesBy(this->promotion_requests[i].getAmount());
	}
	this->promotion_requests.clear();
}

void TeamLead::infoLeavingRequest()         //my func --------------------------------
{
	for (int i = 0; i < this->leaving_requests.size(); i++)
	{
		std::cout << this->leaving_requests[i].getID() << '|' << this->leaving_requests[i].getMessage() << '|' << this->leaving_requests[i].getSender() << '\n';
	}
	
}
void TeamLead::infoTeam()
{
	for (int i = 0; i < this->team.size(); i++)
	{
		std::cout << this->team[i]->getName() << '|' << this->team[i]->getSalary() << '|' << this->team[i]->getTeamLead()->getName() << '\n';
	}
}