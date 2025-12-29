#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
  std::unordered_map<std::string, std::vector<char>> mp;
  std::unordered_map<std::string, bool> dp;

  bool isValid(int i, std::string newLayer, std::string currLayer) {
    int n = size(currLayer);

    if(n == 1) return true;

    if (i == n - 1) {
      if (dp.find(newLayer) != dp.end())
        return dp[newLayer];
      return dp[newLayer] = isValid(0, "", newLayer);
    }

    std::string temp = currLayer.substr(i, 2);

    if (mp.find(temp) == mp.end())
      return false;

    for (char &ch : mp[temp]) {
      if (isValid(i + 1, newLayer + ch, currLayer))
        return true;
    }

    return false;
  }

public:
  bool pyramidTransition(std::string bottom,
                         std::vector<std::string> &allowed) {

    for (std::string &s : allowed) {
      std::string b = s.substr(0, 2);
      mp[b].push_back(s[2]);
    }

    return isValid(0, "", bottom);
  }
};
