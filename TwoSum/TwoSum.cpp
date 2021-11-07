/*
************** Problem Statement ******************

* Given an array of integers nums and an integer target, return indices of the two numbers
* such that they add up to target.
* You may assume that each input would have exactly one solution,
* and you may not use the same element twice.

* You can return the answer in any order.

*/


#include <algorithm> 
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


/*
* @brief a method which will find two numbers which make sum equal to target.
* @Param vector of int
* @Param int as a target
* @Return, vector with the indics.
*/
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> s_map;
    for(int i=0; i<nums.size(); i++)
    {
        if(s_map.find(target-nums[i]) != s_map.end()) {
            return {i, s_map[target-nums[i]]};
        }
        s_map[nums[i]] = i;
    }
    return {};
}

std::vector<std::string> convertStringToVector(std::string& strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedVector;
    while (std::getline(ss, item, delimeter))
    {
        splittedVector.push_back(item);
    }
    return splittedVector;
}

std::vector<int> parseStringToVector(std::string& input)
{
    input = input.substr(1, input.size() - 2);
    auto str_vector = convertStringToVector(input, ',');
    std::vector<int> out_vector;
    std::transform(str_vector.begin(), str_vector.end(), std::back_inserter(out_vector),
               [](const std::string& str) { return std::stoi(str); });
    return out_vector;

}

int main(int argc, char *argv[])
{
    if (argc != 3){
        std::cout << "Incorrect number of arguments" << std::endl;
        return 1;
    }
    std::string given_vec = argv[1];
    auto nums = parseStringToVector(given_vec);
    int target = std::stoi(argv[2]);

    auto res = TwoSum(nums, target);
    std::cout << "Results is: ";
    for(auto i : res) {
        std::cout << " " << i ;
    }
    std::cout << std::endl;
}