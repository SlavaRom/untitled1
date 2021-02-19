//
// Created by slava on 12.02.2021.
//

#ifndef UNTITLED1_CONTACT_H
#define UNTITLED1_CONTACT_H

#include <iostream>
#include <string>

using namespace std;

class contact {
public:
    contact(const string& = "", const int = 0,const string& = "");
    const string name() const;
    const int age() const;
    const string phone() const;
    friend ostream& operator<<(ostream&, const contact&);

private:
    string _name;
    int _age;
    string _phone;
};

#endif //UNTITLED1_CONTACT_H
