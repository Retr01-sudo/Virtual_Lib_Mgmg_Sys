#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Books.h"
#include "Library.h"

int Book::total_books = 0;
std::vector<Book*> Library::Book_vec;
std::vector<Member*> Library::Member_vec;
int main() {
	Library::Add_Book("DSA in C++", "Harsh", Book::Genre::Science, 1001);
	Library::Add_Book("EVS", "Rishi", Book::Genre::Science, 1002);
	Library::Add_Book("WEB_DEV", "Naveen Chutiya", Book::Genre::Science, 1003);
	Library::Add_Member("Vishesh", 1);
	Library::Add_Member("Mohit", 2);
	Library::Add_Member("Rohit", 3);
	Library::DisplayLibStats();
	Library::Borrow_book(10, 1001);
	Library::Borrow_book(1, 1001);
	Library::Borrow_book(2, 1001);
	Library::Borrow_book(3, 1002);
	Library::Return_Book(2, 1001);
	Library::DisplayLibStats();
	Library::Return_Book(1, 1001);
	Library::Return_Book(3, 1002);
	Library::Remove_Member(1);
	Library::Remove_Book(1003);
	Library::DisplayLibStats;

	//Book::display();
}