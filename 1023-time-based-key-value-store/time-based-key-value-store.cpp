class TimeMap {
public:
    typedef pair<int, string> p;
    unordered_map<string, vector<p>>mp;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    string get(string key, int timestamp) {
       vector<pair<int, string>>&temp = mp[key];
       int n = temp.size();
       int lo = 0 ;
       int hi = n-1;
       string ans = "";
       while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(temp[mid].first == timestamp){
            ans = temp[mid].second;
            break;
        }
        else if(temp[mid].first<timestamp){
            ans = temp[mid].second;
            lo = mid+1;
        }else hi = mid-1;
       }
       return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */