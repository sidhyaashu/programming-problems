#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] <= target) {
            combination.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], combination, result, i);
            combination.pop_back();
        }
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<int> combination;
    vector<vector<int>> result;
    findCombinations(candidates, target, combination, result, 0);
    cout << "Unique combinations that sum up to " << target << " are:" << endl;
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb)
            cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
