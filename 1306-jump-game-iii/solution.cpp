#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Target found
            if (arr[curr] == 0) {
                return true;
            }

            // Attempt forward and backward jumps
            int next_forward = curr + arr[curr];
            int next_backward = curr - arr[curr];

            if (next_forward < n && !visited[next_forward]) {
                visited[next_forward] = true;
                q.push(next_forward);
            }

            if (next_backward >= 0 && !visited[next_backward]) {
                visited[next_backward] = true;
                q.push(next_backward);
            }
        }

        return false;
    }
};
