#include <iostream>
#include <vector>
#include <algorithm>

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

class BookManager {
private:
	vector<Book> books;

public:
	void addBook(string title, string author) {
		books.push_back(Book(title, author));
	}

	void displayAllBooks() {
		for (Book book : books) {
			cout << "title :" << book.getTitle() << " author :" << book.getAuthor() << endl;
		}
	}

	string searchByTitle(string title) {
		auto it = find_if(books.begin(), books.end(), [title](Book& book) {
			return book.getTitle() == title;
			});

		if (it != books.end()) {
			return "Found: " + it->getTitle() + " by " + it->getAuthor();
		}
		else {
			return "Book not found.";
		}
	}

	string searchByAuthor(string author) {
		auto it = find_if(books.begin(), books.end(), [author](Book& book) {
			return book.getAuthor() == author;
			});

		if (it != books.end()) {
			return "Found: " + it->getTitle() + " by " + it->getAuthor();
		}
		else {
			return "Book not found.";
		}
	}
};

int main() {
	BookManager manager;

	manager.addBook("1984", "George Orwell");
	manager.addBook("To Kill a Mockingbird", "Harper Lee");
	manager.addBook("The Great Gatsby", "F. Scott Fitzgerald");

	manager.displayAllBooks();

	cout << manager.searchByTitle("1984") << endl;
	cout << manager.searchByTitle("Brave New World") << endl;
	return 0;
}