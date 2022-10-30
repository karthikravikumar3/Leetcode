class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(v.begin(),v.end(),key)==v.end())v.push_back(key);
        
    }
    
    void remove(int key) {
        
       auto itr = find(v.begin(),v.end(),key);
    //(itr);
        if(itr!=v.end())v.erase(itr);
        /*for(auto x:v){
            cout<<x<<"|";
        }
        cout<<endl;*/
        //cout<<key<<"2";
    }
    
    bool contains(int key) {
        //cout<<key<<"|";
        return (find(v.begin(),v.end(),key)!=v.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */