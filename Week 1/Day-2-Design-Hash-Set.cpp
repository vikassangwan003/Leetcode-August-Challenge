Problem Link :  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.

//Solution:

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int>vec; 
    MyHashSet() {
       
    }
    
    void add(int key) {
          if(find(vec.begin(),vec.end(),key)==vec.end())
            vec.push_back(key);
    }
    
    void remove(int key) {
        vector<int>::iterator it;
        it=find(vec.begin(),vec.end(),key);
        if(it!=vec.end())
            vec.erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(find(vec.begin(),vec.end(),key)!=vec.end())
            return true;
        else 
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */