class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }

        int l = 0;
        int r = data[key].size() - 1;

        while (l <= r) {
            int i = l + (r - l) / 2;
            if (data[key][i].first < timestamp) {
                l = i + 1;
            }
            else if (data[key][i].first > timestamp) {
                r = i - 1;
            }
            else {
                return data[key][i].second;
            }
        }

        if (r >= 0) {
            return data[key][r].second;
        }
        return "";
            
    }

    unordered_map<string, vector<pair<int, string>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */