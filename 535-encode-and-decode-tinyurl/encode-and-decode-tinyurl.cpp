class Solution {
private:
    unordered_map<string, string> encodeMap;
    unordered_map<string, string> decodeMap;
    string stdString;
public:
    Solution() {
        stdString = "http://tinyurl.com/";
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        //if url not in the map put 
        if (encodeMap.find(longUrl) == encodeMap.end()) {
            string shortUrl = stdString + to_string(longUrl.length());
            encodeMap[longUrl] = shortUrl;
            decodeMap[shortUrl] = longUrl;
            return encodeMap[longUrl];
        }
        return encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //just return the decoded one
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));