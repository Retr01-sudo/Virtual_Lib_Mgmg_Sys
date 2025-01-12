#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Books.h"
#include "User.h"

class Library {
private:
	static std::vector<Book*> Book_vec;
	static std::vector<Member*> Member_vec;
public:
	static void Add_Book(std::string x, std::string y, Book::Genre z, int a) {
		Book* new_book = new Book(x, y, z, a);
		Book_vec.push_back(new_book);
		//delete new_book; //make sure to remove this during release and add this line to appropriate place.
	}

	static void Remove_Book(int UniqueID) {
		int flag = 0;
		for (int i = 0; i < Book_vec.size(); i++) {
			if (Book_vec[i]->ID == UniqueID) {
				Book_vec.erase(Book_vec.begin() + i);
				delete Book_vec[i];
				Book::total_books--;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			std::cout << "No such book with UniqueID: " << UniqueID << " exist!" << std::endl;
		}
	}

	static void Add_Member(std::string name, int UserID) {
		int flag = 0;
		for (int i = 0; i < Member_vec.size(); i++) {
			if (Member_vec[i]->userID == UserID) {
				flag = 1;
				std::cout << "Member with this user ID already exists, try using another UserID" << std::endl;
				break;
			}
		}
		if (flag == 0) {
			Member* new_member = new Member(name, UserID);
			Member_vec.push_back(new_member);
		}
	}

	static void Remove_Member(int ID) {
		int flag = 0;
		for (int i = 0; i < Member_vec.size(); i++) {
			if (Member_vec[i]->userID == ID) {
				delete (Member_vec[i]);
				Member_vec.erase(Member_vec.begin() + i);
				std::cout << "Member with ID: " << ID << " Removed" << std::endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			std::cout << "Member with UserID: " << ID << " does not exist" << std::endl;
		}
	}

	static bool isAvailable(int UniqueID) {
		int flag = 0;
		for (int i = 0; i < Book_vec.size(); i++) {
			if (Book_vec[i]->ID == UniqueID && Book_vec[i]->IsBorrowed == false) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			return true;
		else
			return false;
	}

	static void Borrow_book(int UserID, int UniqueID) {
		int flag1 = 0;
		int flag2 = 0;
		for (int i = 0; i < Member_vec.size(); i++) {
			if (Member_vec[i]->userID == UserID) {
				flag1 = 1;
				//Member_vec[i]->Borrowed_Books.push_back(UniqueID);
				for (int j = 0; j < Book_vec.size(); j++) {
					if (Book_vec[j]->ID == UniqueID && Book_vec[j]->IsBorrowed == false) {
						flag2 = 1;
						Member_vec[i]->Borrowed_Books.push_back(UniqueID);
						Book_vec[j]->IsBorrowed = true;
						Book::total_books--;
						std::cout << "Member with UserID: " << UserID << " borrowed book with UniqueID: " << UniqueID << std::endl;
					}
				}
				if (flag2 == 0) {
					std::cout << "Book with ID: " << UniqueID << " is not availabe" << std::endl;
				}
			}
		}
		if (flag1 == 0) {
			std::cout << "Member with ID:" << UserID << " not registered in the system" << std::endl;
		}
	}

	static void Return_Book(int UserID, int UniqueID) {
		int flag1 = 0;
		for (int i = 0; i < Member_vec.size(); i++) {
			int flag2 = 0;
			if (Member_vec[i]->userID == UserID) {
				flag1 = 1;
				for (int j = 0; j < Member_vec[i]->Borrowed_Books.size(); j++) {
					if (Member_vec[i]->Borrowed_Books[j] == UniqueID) {
						flag2 = 1;
						Member_vec[i]->Borrowed_Books.erase(Member_vec[i]->Borrowed_Books.begin() + j);
						for (int k = 0; k < Book_vec.size(); k++) {
							if (Book_vec[k]->ID == UniqueID) {
								Book_vec[k]->IsBorrowed = false;
								Book::total_books++;
								std::cout << "Book with UniqueID: " << UniqueID << " Successfully returned by member with UserID: " << UserID << std::endl;
								break;
							}
						}
					}
				}
				if (flag2 == 0) {
					std::cout << "Book with ID: " << UniqueID << " is not Borrowed by User: " << UserID << std::endl;
				}
			}
		}
		if (flag1 == 0) {
			std::cout << "Member with ID:" << UserID << " not registered in the system" << std::endl;
		}
	}

	static void DisplayLibStats() {
		std::cout << "Total Books:" << Book::total_books << std::endl;
		std::cout << "Total Members: ";
		for (int i = 0; i < Member_vec.size(); i++) {
			std::cout << Member_vec[i]->userName << " ";
		}
		std::cout << "" << std::endl;
		std::cout << "Total Books: ";
		for (int i = 0; i < Book_vec.size(); i++) {
			if(Book_vec[i]->IsBorrowed==false)
			std::cout << Book_vec[i]->title << ", ";
		}
		std::cout << "" << std::endl;
	}
};