#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum);

int main()
{
    vector<vector<int>> result =  threeNumberSum({ 12, 3, 1, 2, -6, 5, -8, 6 }, 0);

    for (int i = 0; i < result.size(); i++)
    {

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << " -*- ";
    }
    return 0;
}


vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    // Write your code here.

    vector<vector<int>> matchTarget;

    if (array.size() <= 2)return {};

    sort(array.begin(), array.end());


    for (int i = 0; i < array.size(); i++)
    {
        int leftidx = i + 1;
        int rightidx = array.size() - 1;

        while (leftidx < rightidx)
        {
            int sums = array[i] + array[leftidx] + array[rightidx];

            if (sums == targetSum)
            {
                matchTarget.push_back({ array[i], array[leftidx], array[rightidx] });
                leftidx++;
                rightidx--;
            }

            else if (sums < targetSum)leftidx++;

            else if (sums > targetSum)rightidx--;
        }

    }

    return  matchTarget;
}
