#include<iostream>
#include<string>
#include<vector>
#include<map>

class Solution
{
public:
    // returns length of the longest substring of s with not more than k distinct characters
    int longestSubstringLength(std::string s, int k)
    {
        if(s.empty() || k == 0)
            return 0;

        int maxLength = 0;

        std::map<char, int> letters;

        int first = 0;
        int last = 0;
        const int Size = s.size();

        for(; last < Size; ++last)
        {
            letters[s[last]]++;
            if(int(letters.size()) > k)
            {
                for(; first <= last; ++first)
                {
                    const int count = --letters[s[first]];
                    if(count == 0)
                    {
                        letters.erase(s[first]);
                        ++first;
                        break;
                    }
                }
            }
            else if(last-first+1 > maxLength)
            {
                maxLength = last-first+1;
            }
        }
        return maxLength;
    }
};

struct TestCase
{
    std::string s;
    int k;
    int answer;
};

int main()
{
    std::vector<TestCase> cases = {
        {"", 1, 0},
        {"", 2, 0},
        {"aaa", 0, 0},
        {"aaaabbbbb", 1, 5},
        {"aaaabb", 1, 4},
        {"aabbbcccc", 1, 4},
        {"ccccaaabb", 1, 4},
        {"eceba", 2, 3},
        {"abababacccc", 2, 7},
        {"abababcbcbcbc", 2, 8},
        {"abcdeffff", 3, 6},
    }; 

    Solution solution;
    bool success = true;
    for(const auto& test: cases)
    {
        const int res = solution.longestSubstringLength(test.s, test.k);
        if(res != test.answer)
        {
            std::cout << "string: " << test.s << ", k: " << test.k << "\n";
            std::cout << "answer: " << res << ", expected: " << test.answer << "\n";
            success = false;
        }
        else
        {
            std::cout << "passed\n";
        }
    }

    std::cout << "Summary: " << (success ? "SUCCESS" : "FAIL") << "\n";
    return 0;
}