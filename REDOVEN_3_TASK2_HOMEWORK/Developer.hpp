#pragma once
#include <string>

class TeamLead;

class Developer {
public:
	Developer(const std::string& name);
	Developer() = default;
	//~Developer();
	Developer& operator=(const Developer& input);
	Developer(const Developer& input);

	std::string getName()const;
	double getSalary()const;
	TeamLead* getTeamLead()const;
	void setLeader(TeamLead* input);
	void setLeaderNull();
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void setSalary(const double input);
protected:
	std::string name;
	double salary;
	TeamLead* leader;
};
