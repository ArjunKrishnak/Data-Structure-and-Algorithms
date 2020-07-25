#include <list>
class LRUCache {
private:
    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int capacity;
public:
    LRUCache(int capacity):capacity(capacity){
        dll.clear();
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            list<pair<int,int>>::iterator itr = mp[key];
            int val = itr->second;
            dll.erase(itr);
            dll.push_front(make_pair(key,val));
            mp[key] = dll.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            list<pair<int,int>>::iterator itr = mp[key];
            dll.erase(itr);
        }
        else{
            if(dll.size() == capacity){
                // do eviction
                list<pair<int,int>>::reverse_iterator r_itr = dll.rbegin();
                int key = r_itr->first;
                dll.erase(mp[key]);
                mp.erase(key);
            }
        }
        dll.push_front(make_pair(key,value));
        mp[key] = dll.begin();
    }
};
