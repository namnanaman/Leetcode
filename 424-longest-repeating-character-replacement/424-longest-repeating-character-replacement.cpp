class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(26);
        int mostFreqLetter = 0;
        int left = 0;
        int maxi = 0;
        
        for(int right = 0;right < s.length();right++){
            freq[s[right] - 'A']++;
            mostFreqLetter = max(mostFreqLetter,freq[s[right] - 'A']);
            
            int lettersToChange = (right - left + 1) - mostFreqLetter;
            if(lettersToChange > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxi = max(maxi,right - left + 1);
        }
        
        return maxi;
        
        
        
        
//         vector<int>  freq(26);
//         int mostFreqLetter = 0;
//         int left = 0;
//         int maxi = 0;
        
//         for(int right = 0; right < s.length(); right++){
//             freq[s[right] - 'A']++;
//             mostFreqLetter = max(mostFreqLetter, freq[s[right] - 'A']);
            
//             int lettersToChange = (right - left + 1) - mostFreqLetter;
//             if(lettersToChange > k){
//                 freq[s[left] - 'A']--;
//                 left++;
//             }
            
//             maxi = max(maxi, right - left + 1);
//         }
        
//         return maxi;
    }
};