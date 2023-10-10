#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    Book(string title, string author, int year, string isbn, bool available) :
        title_(title), author_(author), year_(year), isbn_(isbn), available_(available) {}

    string GetTitle() const { return title_; }
    string GetAuthor() const { return author_; }
    int GetYear() const { return year_; }
    string GetIsbn() const { return isbn_; }
    bool IsAvailable() const { return available_; }

private:
    string title_;
    string author_;
    int year_;
    string isbn_;
    bool available_;
};

class Library {
public:
    void AddBook(const Book& book) {
        books_.push_back(book);
    }

    void RemoveBook(const string& isbn) {
        auto it = books_.begin();
        while (it != books_.end()) {
            if (it->GetIsbn() == isbn) {
                it = books_.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void SearchByAuthor(const string& author) {
        for (const auto& book : books_) {
            if (book.GetAuthor() == author) {
                cout << book.GetTitle() << " by " << book.GetAuthor() << " (" << book.GetYear() << ")" << endl;
            }
        }
    }

    void SearchByTitle(const string& title) {
        for (const auto& book : books_) {
            if (book.GetTitle() == title) {
                cout << book.GetTitle() << " by " << book.GetAuthor() << " (" << book.GetYear() << ")" << endl;
            }
        }
    }

    void ListAvailableBooks() {
        for (const auto& book : books_) {
            if (book.IsAvailable()) {
                cout << book.GetTitle() << " by " << book.GetAuthor() << " (" << book.GetYear() << ")" << endl;
            }
        }
    }

private:
    vector<Book> books_;
};

int main()
{
    Library library;

    library.AddBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-0743273565", true));
    library.AddBook(Book("To Kill a Mockingbird", "Harper Lee", 1960, "978-0446310789", true));
    library.AddBook(Book("1984", "George Orwell", 1949, "978-0451524935", false));
    library.AddBook(Book("Pride and Prejudice", "Jane Austen", 1813, "978-0141439518", true));
    library.AddBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951, "978-0316769488", true));
    library.AddBook(Book("The Hobbit", "J.R.R. Tolkien", 1937, "978-0261102217", true));
    library.AddBook(Book("Brave New World", "Aldous Huxley", 1932, "978-0060850524", true));
    library.AddBook(Book("The Lord of the Rings", "J.R.R. Tolkien", 1954, "978-0618640157", true));
    library.AddBook(Book("The Odyssey", "Homer", -800, "978-0143039952", true));
    library.AddBook(Book("War and Peace", "Leo Tolstoy", 1869, "978-1400079988", true));

    library.SearchByAuthor("Harper Lee");

    library.SearchByTitle("1984");

    library.ListAvailableBooks();

    return 0;
}
