#include <iostream>
using namespace std;
#include <vector>

class Book {
public:
    string title;
    string author;
    int year;

    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }
};

class Library {
public:
    vector<Book> books;

public:
    void borrowBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                cout << "Buku '" << title << "' berhasil dipinjam!" << endl;
                books.erase(books.begin() + i);
                return;
            }
        }

        cout << "Maaf, buku '" << title << "' tidak ditemukan!" << endl;
    }

    void donateBook(Book book) {
        books.push_back(book);
        cout << "Buku '" << book.title << "' berhasil disumbangkan!" << endl;
    }

    void listBooks() {
        cout << "Daftar buku : " << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << "- " << books[i].title << " (" << books[i].author << ", "
                 << books[i].year << ")" << endl;
        }
    }

    void searchBook(string keyword) {
        cout << "Hasil pencarian buku dengan kata kunci '"
             << "':" << endl;
        bool found = false;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title.find(keyword) != string::npos ||
                books[i].author.find(keyword) != string::npos) {
                cout << "- " << books[i].title << " (" << books[i].author << ", "
                     << books[i].year << ")" << endl;
                found = true;
            }
        }
    }
};

int main() {
    bool runProgram = true;
    char response;
    Library library;

    while (runProgram) {
        cout << "Selamat datang di aplikasi layanan perpustakaan" << endl;
        cout << "Silahkan pilih layanan yang ingin anda gunakan" << endl;
        cout << "1. Daftar Buku" << endl;
        cout << "2. Meminjam Buku" << endl;
        cout << "3. Menyumbang Buku" << endl;
        cout << "4. Mencari Buku" << endl;

        int selectServiceNumber;
        cout << "\nSilahkan masukkan nomer layanan yang ingin anda gunakan : ";
        cin >> selectServiceNumber;

        if (selectServiceNumber == 1) {
            library.listBooks();
        } else if (selectServiceNumber == 2) {
            string title;

            cout << "Silahkan masukkan judul buku yang ingin anda pinjam : ";
            cin >> title;

            library.borrowBook(title);
        } else if (selectServiceNumber == 3) {
            string title;
            string author;
            int year;

            cout << "Masukkan judul buku : ";
            cin >> title;

            cout << "Masukkan nama pengarang buku : ";
            cin >> author;

            cout << "Masukkan tahun buku diterbitkan : ";
            cin >> year;

            library.donateBook(Book(title, author, year));
        } else if (selectServiceNumber == 4) {
            string keyword;

            cout << "Silahkan masukkan keyword untuk mencari buku : ";
            cin >> keyword;
            library.searchBook(keyword);
        }

        cout << "Apakah anda ingin melanjutkan menggunakan program? Y/N : ";
        cin >> response;

        if (response == 'N' || response == 'n') {
            runProgram = false;
        }
    }
}