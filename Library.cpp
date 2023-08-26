#include "Library.h"

#include <endian.h>
#include <iostream>
#include <stdexcept>
#include <type_traits>

int const COUNT_GENRES = 3;

int Library::m_ID = 0;
int Library::m_totalBooks = 0;
std::string Library::Book::m_arrayGenres[COUNT_GENRES] = {"Romance","Historical","Fantasy"};

//Book

Library::Book::Book(const std::string& title, const std::string& author, int ISBN) 
    : m_title{ title }, m_author{ author }
{
    if (ISBN >= COUNT_GENRES || ISBN < 0) {
        throw std::runtime_error("Error: none valid genres type");
    }
    m_ISBN = ISBN;
}

bool Library::Book::operator==(const Library::Book& book) {
    return (
            m_title == book.m_title &&
            m_author == book.m_author &&
            m_ISBN == book.m_ISBN
            );
}

void Library::Book::displayBook() const {
    std::cout << "(title: " << m_title << " , ";
    std::cout << "auther: " << m_author << " , ";
    std::cout << "ISBN: " << m_ISBN << ")";
}

//Library

Library::Library(int administratorID) 
    : m_LibraryID{ m_ID }, m_administratorID{ administratorID }
{
    ++m_ID;
}

int Library::getTotalBooks() {
    return Library::m_totalBooks;
}

void Library::displayLibraryInfo() const{
    std::cout << "ID: " << m_LibraryID << ", administrator ID: " << m_administratorID << std::endl;
    for (const auto& item: m_books) {
        item.displayBook();
    }
}

void Library::addBook(const Book& book) {
    for (int i = 0; i < m_books.size(); ++i) {
        if (m_books[i] == book) {
            throw std::runtime_error("such a book exists in this library");
        }
    }
    ++m_totalBooks;
    m_books.push_back(book);
}

