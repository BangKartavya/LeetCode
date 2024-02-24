bool cmp(const vector<int> a,const vector<int> b) {
    return a[2]<b[2];
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int> knownSet = {0,firstPerson};

        vector<vector<pair<int,int>>> sortedMeetings;
        sort(meetings.begin(),meetings.end(),cmp);

        set<int> seenTime;

        for(auto i: meetings) {
            if(seenTime.find(i[2])==seenTime.end()) {
                seenTime.insert(i[2]);
                sortedMeetings.push_back({});
            }
            sortedMeetings.back().push_back({i[0],i[1]});
        }
        for(auto i: sortedMeetings) {
            set<int> peopleKnowSecret;
            unordered_map<int,vector<int>> graph;

            for(auto pair:i) {
                graph[pair.first].push_back(pair.second);
                graph[pair.second].push_back(pair.first);

                if(knownSet.find(pair.first)!=knownSet.end()) peopleKnowSecret.insert(pair.first);
                if(knownSet.find(pair.second)!=knownSet.end()) peopleKnowSecret.insert(pair.second);
            }
            queue<int> queue;
            for(int person: peopleKnowSecret) queue.push(person);

            while(!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                knownSet.insert(curr);
                for(int n:graph[curr]) {
                    if(knownSet.find(n)==knownSet.end()) {
                        knownSet.insert(n);
                        queue.push(n);
                    }
                }
            }
        }
        return vector<int>(knownSet.begin(),knownSet.end());
    }
};