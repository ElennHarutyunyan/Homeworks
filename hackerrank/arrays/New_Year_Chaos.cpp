#include <iostream>
#include <vector>
using namespace std;

void minimumBribes(const vector<int>& q) {
    int s = 0;
    for (size_t i = 0; i < q.size(); i++) {
        if (q[i] - static_cast<int>(i + 1) > 2) {
            cout << "Too chaotic\n";
            return;
        }

        for (size_t j = max(static_cast<int>(0), q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) s++;
        }
    }
    cout << s << '\n';
}

int main() {
    vector<int> q = {2, 1, 5, 3, 4};
    minimumBribes(q); // Output: 3
}
