//
// Created by ne555 on 12.02.2021.
//

#include <algorithm>
#include <vector>
#include "address_book.h"

using namespace std;

address_book& address_book::instance() {
    static address_book inst;
    return inst;
}

const int address_book::size() const {
    return _contacts.size();
}

void address_book::add(const contact& cont) {
    _contacts.push_back(cont);
}

const vector<contact> address_book::get() const {
    return _contacts;
}

void address_book::qsort(const string& field, const string& sort_order) {
    if (field == "age"){
        if (sort_order == "asc")
            sort(_contacts.begin(), _contacts.end(),
                 [](const contact& f, const contact& s){return f.age() < s.age();});
        else
            sort(_contacts.rbegin(), _contacts.rend(),
                 [](const contact& f, const contact& s){return f.age() < s.age();});
    } else if (field == "name"){
        if (sort_order == "asc")
            sort(_contacts.begin(), _contacts.end(),
                 [](const contact &f, const contact &s) { return f.name() < s.name(); });
        else
            sort(_contacts.rbegin(), _contacts.rend(),
                 [](const contact &f, const contact &s) { return f.name() < s.name(); });
    } else{
        if (sort_order == "asc")
            sort(_contacts.begin(), _contacts.end(),
             [](const contact& f, const contact& s){return f.phone() < s.phone();});
        else
            sort(_contacts.rbegin(), _contacts.rend(),
                 [](const contact& f, const contact& s){return f.phone() < s.phone();});
    }
}

void address_book::print() {
    for_each(_contacts.begin(), _contacts.end(),
             [](const contact& i) {
        int cnt = 1;
        cout << cnt << ". " << i;
        cnt++;});
}

