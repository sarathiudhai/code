#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool canAttend(vector<pair<int, int>> events) {
    if (events.empty()) {
        return true;
    }
    sort(events.begin(), events.end());
    for (int i = 1; i < events.size(); i++) {
        if (events[i].first < events[i - 1].second) {
            return false;
        }
    }
    return true;
}

int minRooms(vector<pair<int, int>> events) {
    if (events.empty()) {
        return 0;
    }
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxRooms = 0;
    for (auto event : events) {
        int start = event.first;
        int end = event.second;
        while (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        pq.push(end);
        maxRooms = max(maxRooms, (int)pq.size());
    }
    return maxRooms;
}

int main() {
    vector<pair<int, int>> events1 = {
        {9, 10}, {10, 11}, {11, 12}
    };
    vector<pair<int, int>> events2 = {
        {9, 11}, {10, 12}, {11, 13}
    };
    vector<pair<int, int>> events3 = {
        {9, 12}, {10, 11}, {10, 13}
    };
    cout << boolalpha;
    cout << canAttend(events1) << endl;  
    cout << minRooms(events1) << endl;   
    cout << canAttend(events2) << endl;  
    cout << minRooms(events2) << endl;   
    cout << canAttend(events3) << endl; 
    cout << minRooms(events3) << endl;   
    return 0;
}