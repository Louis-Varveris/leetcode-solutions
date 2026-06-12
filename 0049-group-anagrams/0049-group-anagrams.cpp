class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // Key = sorted version of word
        // Value = list of anagrams
        unordered_map<string, vector<string>> mp;
        for (string word : strs)
        {
            string key = word;
            sort(key.begin(), key.end());
            // Group words with the same sorted key
            mp[key].push_back(word);
        }
        vector<vector<string>> result;
        // Extract all groups from the hashmap
        for (auto& pair : mp) 
        {
            result.push_back(pair.second);
        }
        return result;
    }
};