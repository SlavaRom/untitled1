//
// Created by slava on 12.02.2021.
//

#ifndef UNTITLED1_ADDRESS_BOOK_H
#define UNTITLED1_ADDRESS_BOOK_H

#include <iostream>
#include <vector>
#include "contact.h"

using namespace std;

class address_book {
public:
    address_book(const address_book&) = delete;
    void operator=(const address_book&) = delete;
    static address_book& instance();
    void add(const contact&);
    const int size() const;
    const vector<contact> get() const;
    void qsort(const string& field, const string& sort_order);
    void print();

private:
    vector<contact> _contacts;
    address_book() {}
    ~address_book() {}
};

#endif //UNTITLED1_ADDRESS_BOOK_H
