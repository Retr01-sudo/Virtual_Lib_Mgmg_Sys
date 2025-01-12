#pragma once
#include <iostream>
#include <string>
#include <vector>
class user {
public:
	std::string userName;
	int userID;
	virtual ~user() {};
	virtual void displayUserDetail() = 0;
};

class Member : public user {
public:
	std::vector<int> Borrowed_Books;
	void displayUserDetail() {
		std::cout << "Name: " << userName << "\nUser ID: " << userID << std::endl;
	}
	Member(std::string name, int ID) {
		userName = name;
		userID = ID;
	}

	~Member() {
		//std::cout << "Member class for " << userName << "Destroyed !!" << std::endl;
	}
};

class Admin : public user {
};