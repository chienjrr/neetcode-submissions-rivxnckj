class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char t : tasks) freq[t - 'A']++;
        int max_freq = 0;
        for(int i = 0; i < 26; i++){
            max_freq = max(max_freq, freq[i]);
        }
        int count_max_freq = 0;
        for(int i = 0; i < 26; i++){
            if( freq[i] == max_freq) count_max_freq++;
        }
        int partC= max_freq - 1;
        int partL = n + 1;
        int result = partC*partL + count_max_freq;
        if(tasks.size() >= result) result = tasks.size();
        return result;

    }
};
