#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct book {
    string id;
    string title;
    string author;
    string keywords;
    string publisher;
    string publishyear;
};

bool idcmp(book &a, book &b) { return a.id < b.id; }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    book *books = new book[n];
    cin.ignore(16, '\n');
    for (int i = 0; i < n; i++) {
        getline(cin, books[i].id);
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        getline(cin, books[i].keywords);
        getline(cin, books[i].publisher);
        getline(cin, books[i].publishyear);
    }
    sort(books, books + n, idcmp);

    int m;
    cin >> m;
    int tmpint;
    string tmpstr;
    while (m--) {
        scanf("%d: ", &tmpint);
        getline(cin, tmpstr);
        cout << tmpint << ": " << tmpstr << endl;
        bool isfind = false;
        for (int i = 0; i < n; i++) {
            if (tmpint == 1 && tmpstr == books[i].title) {
                cout << books[i].id << endl;
                isfind = true;
            } else if (tmpint == 2 && tmpstr == books[i].author) {
                cout << books[i].id << endl;
                isfind = true;
            } else if (tmpint == 3 &&
                       books[i].keywords.find(tmpstr) != std::string::npos) {
                cout << books[i].id << endl;
                isfind = true;
            } else if (tmpint == 4 && tmpstr == books[i].publisher) {
                cout << books[i].id << endl;
                isfind = true;
            } else if (tmpint == 5 && tmpstr == books[i].publishyear) {
                cout << books[i].id << endl;
                isfind = true;
            }
        }
        if (!isfind)
            cout << "Not Found" << endl;
    }
    return 0;
}
