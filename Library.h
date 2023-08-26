#pragma once

#include <iostream>
#include <vector>

class Library {
public:
    class Book {
    public:
        bool operator==(const Book&);
        Book(const std::string&, const std::string&, int);
        void displayBook() const;
    private:
        std::string m_title;
        std::string m_author;
        int m_ISBN;
        static std::string m_arrayGenres[];
    };
public:
    Library(int);

    static int getTotalBooks();

    void displayLibraryInfo() const;
    void addBook(const Book&);

private:
    static int m_totalBooks;
    std::vector<Book> m_books = {};
    static int m_ID;
    const int m_LibraryID;
    int m_administratorID;
};

