#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int frames = 4;
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    vector<int> v;
    unordered_map<int, int> m;

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        if (m.find(pages[i]) == m.end()) {
            if (v.size() >= frames) {
                int idx = -1, farthest = INT_MIN;
                for (int j = 0; j < v.size(); j++) {
                    if (find(pages + i + 1, pages + n, v[j]) == pages + n) {
                        idx = j;
                        break;
                    }
                    int temp = find(pages + i + 1, pages + n, v[j]) - pages;
                    if (temp > farthest) {
                        farthest = temp;
                        idx = j;
                    }
                }
                m.erase(v[idx]);
                v[idx] = pages[i];
                m[pages[i]] = i;
            } else {
                v.push_back(pages[i]);
                m[pages[i]] = i;
            }
            pageFaults++;
        }
    }

    cout << "Optimal Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;

    return 0;
}
