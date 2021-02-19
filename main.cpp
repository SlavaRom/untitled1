#include <iostream>
#include <string>
#include <algorithm>
#include "address_book.h"

using namespace std;

vector<string> GOOD_ORDER {"asc", "desc"};
vector<string> GOOD_FIELD {"name", "age", "phone"};

contact create_new_contact() {
    string name, phone;
    int age;
    cout << "Write name" << endl;
    cin >> name;
    cout << "Write age" << endl;
    cin >> age;
    if (age < 1){
        cin.clear();
        cin.ignore(255, '\n');
        throw invalid_argument("Invalid age");
    }
    cout << "Write phone" << endl; cin >> phone;
    return contact(name, age, phone);
}

bool good_params(const string& cur, const vector<string>& good){
    return find(good.begin(), good.end(), cur) != good.end();
}

bool preprocess(){
    string field, order;
    cout << "Select field for sorting [name, age, phone]" << endl; cin >> field;
    cout << "Select sort order [asc, desc]" << endl; cin >> order;
    if (good_params(field, GOOD_FIELD) && good_params(order, GOOD_ORDER)) {
        address_book::instance().qsort(field, order);
        return true;
    } else{
        cerr << "Incorrect params" << endl;
        return false;
    }

}

void print_all(const vector<contact>& v){
    cout << endl;
    int cnt = 1;
    for (const auto& i : v) {
        cout << cnt << ". " << i;
        cnt++;
    }
    cout << endl << "Total: " << v.size() << endl;
}

int main() {
    char _choice;
    while (true){
        cout << "Add contact? [y,n] ";
        cin >> _choice;
        if (_choice == 'y') {
            while (true) {
                try {
                    contact c = create_new_contact();
                    address_book::instance().add(c);
                    break;
                } catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                    cout << "Let's try again" << endl;
                    continue;
                }
            }
        } else if (_choice == 'n'){
            if (address_book::instance().get().empty()) {
                cout << "Empty address_book" << endl;
                cout << endl << "Total: " << address_book::instance().size() << endl;
                break;
            }
            while (!preprocess()){}
            address_book::instance().print();
            cout << endl << "Total: " << address_book::instance().size() << endl;
            break;
        } else{
            cerr << "Incorrect input" << endl;
            break;
        }
    }
    return 0;
}
