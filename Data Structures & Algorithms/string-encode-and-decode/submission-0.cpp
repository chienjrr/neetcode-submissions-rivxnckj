class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string s : strs){
            int n = s.size();
            encoded_string += to_string(n);
            encoded_string += "#";
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = s.find("#", i);
            int len = stoi(s.substr(i, j - i));
            i = j+1;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
        
    }
};
