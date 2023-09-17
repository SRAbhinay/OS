#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int frames = 4;
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    queue<int> q;
    unordered_set<int> s;

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        if (s.size() < frames) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                q.push(pages[i]);
                pageFaults++;
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int front = q.front();
                q.pop();
                s.erase(front);
                s.insert(pages[i]);
                q.push(pages[i]);
                pageFaults++;
            }
        }
    }

    cout << "FIFO Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;

    return 0;
}
