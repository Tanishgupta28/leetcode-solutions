class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        sort(hand.begin(), hand.end());
        unordered_map<int,vector<int>>mp;
        for(int i = 0 ; i<n ; i++){
            if(mp.find(hand[i]-1)!=mp.end()){
                int temp = mp[hand[i]-1].back();
                mp[hand[i]-1].pop_back();
                if(mp[hand[i]-1].size()==0) mp.erase(hand[i]-1);
                temp++;
                if(temp!=groupSize) mp[hand[i]].push_back(temp);
            }
            else{
                if(groupSize>1)mp[hand[i]].push_back(1);
            }
        }
        if(mp.size()==0) return true;
        return false;
    }
};