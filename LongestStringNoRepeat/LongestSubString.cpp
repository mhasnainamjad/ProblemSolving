/*
************** Problem Statement ******************

* Given a string s, find the length of the longest substring without repeating characters.

*/

#include <iostream>
#include <unordered_map>
#include <vector>


/*
* @brief a method which will find longest string without repeating.
* @Param String
* @Return, len of longest string without repeat.
*/

int lengthOfLongestSubstring(std::string s) 
{
    if(s.empty()){
        return 0;
    }
    int lastSeenIndex[256] = { 0 }; //array to store the last occurences of all the characters
    int whereToStart = 0;
    int longest = 0;
    for (int i = 0; i < s.length(); i++) {
        whereToStart = std::max(whereToStart, lastSeenIndex[s[i]]);
        longest = std::max(longest, i - whereToStart + 1);
        lastSeenIndex[s[i]] = i + 1;
    }
    return longest;
}

int main(int argc , char *argv[])
{
    if (argc != 2){
        std::cout << "Incorrect number of arguments" << std::endl;
        return 1;
    }
    std::string given_str = argv[1];
    std::cout << given_str << std::endl;
    auto len = lengthOfLongestSubstring(given_str);
    std::cout << "max len of substring: " << len << std::endl;
}
