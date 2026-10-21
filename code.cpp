#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int c) {
        cap = c;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        auto it = mp[key];
        int value = it->second;
        cache.splice(cache.begin(), cache, it);
        return value;
    }
    void put(int key, int value) {
        if (cap <= 0) {
            return;
        }
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        if (cache.size() >= cap) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    LRUCache obj(2);
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl;  
    obj.put(3, 30);
    cout << obj.get(2) << endl;  
    cout << obj.get(3) << endl;  
    obj.put(1, 100);
    cout << obj.get(1) << endl;  
    return 0;
}