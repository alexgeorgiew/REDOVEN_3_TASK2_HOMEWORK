#pragma once
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <vector>
#include "Developer.hpp"

class Developer;


class TeamLead : public Developer {
public:
	TeamLead(const std::string& name, double salary);
	TeamLead() = default;
	//~TeamLead();
	TeamLead(const TeamLead& input);
	TeamLead& operator=(const TeamLead& input);
	std::vector<Developer*> getTeam()const;
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();

	void infoLeavingRequest();      //my functions
	void infoTeam();
private:
	std::vector<Developer*> team;
	std::vector<LeavingRequest> leaving_requests;
	std::vector<PromotionRequest> promotion_requests;
};