#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "user.h"

class Book {
public:
	enum Genre {
		Fiction = 0, NonFiction, Mystery, Biography, Science, RomCom
	};
	std::string title;
	std::string author;
	Genre genre;
	int ID;
	bool IsBorrowed;

	static int total_books;


	Book(std::string x, std::string y, Genre z, int a) : title(x), author(y), genre(z), ID(a), IsBorrowed(false) {
		std::cout << "Book added with:\nTitle: " << x << "\nAuthor: " << y << "\nUniqueID: " << ID << std::endl;
		total_books++;
	}


	~Book() {
		std::cout << "Destructor called for Book: [Title: " << title << ", ID: " << ID << "]" << std::endl;
		total_books--;
	}

	//for testing in release replace this function with the libstat that only admin can access in the library section
	static void display() {
		std::cout << "Total Books: " << total_books << std::endl;
	}

};