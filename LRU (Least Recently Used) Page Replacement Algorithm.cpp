#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main() {
    int frames = 4;
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    list<int> l;
    unordered_map<int, list<int>::iterator> m;

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        if (m.find(pages[i]) == m.end()) {
            if (l.size() >= frames) {
                int last = l.back();
                l.pop_back();
                m.erase(last);
            }
            l.push_front(pages[i]);
            m[pages[i]] = l.begin();
            pageFaults++;
        } else {
            l.erase(m[pages[i]]);
            l.push_front(pages[i]);
            m[pages[i]] = l.begin();
        }
    }

    cout << "LRU Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;

    return 0;
}
