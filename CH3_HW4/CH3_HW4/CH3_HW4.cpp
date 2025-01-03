#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Book {
private:
	string title;
	string author;

public:
	Book(string title, string author) : title(title), author(author) {}

	string getTitle() {
		return title;
	}

	string getAuthor() {
		return author;
	}
};

class BorrowManager {
private:
	unordered_map<string, int> stock;

public:
	void initializeStock(string book, int quantity = 3) {
		stock[book] = quantity;
	}

	void borrowBook(string title) {
		for (auto& pair : stock) {
			if (pair.first == title) {
				if (pair.second > 0) {
					pair.second--;
					cout << "Borrowed: " << title << endl;
				}
				else {
					cout << "No stock available for: " << title << endl;
				}
				return;
			}
		}
		cout << "Book not found: " << title << endl;
	}

	void returnBook(string title) {
		for (auto& pair : stock) {
			if (pair.first == title) {
				pair.second++;
				cout << "Returned: " << title << endl;
				return;
			}
		}
		cout << "Book not found: " << title << endl;
	}

	void displayStock() {

	}
};

class BookManager {
private:
	vector<Book> books;


	Book* findBookByTitle(string title) {
		auto it = find_if(books.begin(), books.end(), [title](Book& book) {
			return book.getTitle() == title;
			});

		if (it != books.end()) {
			return &(*it);
		}
		else {
			return nullptr;
		}
	}

	Book* findBookByAuthor(string author) {
		auto it = find_if(books.begin(), books.end(), [author](Book& book) {
			return book.getTitle() == author;
			});

		if (it != books.end()) {
			return &(*it);
		}
		else {
			return nullptr;
		}
	}

public:
	void addBook(string title, string author) {
		books.push_back(Book(title, author));
	}

	void displayAllBooks() {
		for (Book book : books) {
			cout << "title :" << book.getTitle() << " author :" << book.getAuthor() << endl;
		}
	}

	Book* getBookByTitle(string title) {
		return findBookByTitle(title);
	}

	Book* getBookByAuthor(string author) {
		return findBookByAuthor(author);
	}
};

int main() {
	BookManager bookManager;
	BorrowManager borrowManager;

	// 책 추가
	bookManager.addBook("1984", "George Orwell");
	bookManager.addBook("To Kill a Mockingbird", "Harper Lee");
	bookManager.addBook("The Great Gatsby", "F. Scott Fitzgerald");

	bookManager.displayAllBooks();

	// 재고 초기화
	borrowManager.initializeStock("1984", 5);
	borrowManager.initializeStock("To Kill a Mockingbird", 2);

	borrowManager.displayStock();

	// 책 대여
	borrowManager.borrowBook("1984");
	borrowManager.borrowBook("The Great Gatsby");

	borrowManager.displayStock();

	// 책 반납
	borrowManager.returnBook("1984");
	borrowManager.returnBook("The Great Gatsby");

	borrowManager.displayStock();

	return 0;
}