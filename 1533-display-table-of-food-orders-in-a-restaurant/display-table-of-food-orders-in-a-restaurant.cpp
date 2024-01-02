class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        //we just want to create a data structure which stores the
        //food items in a specified order of the restaurant wish
        //framing this ds is the unique part here .
        int n = orders.size();
        vector<vector<string>> ans;
        set<string> foodsList;
        //nested map to store diff tables and theirs food and count
        map<int, map<string, int>> customerTableFoodCount;
        for(int i = 0; i < n; i++) {
            foodsList.insert(orders[i][2]);
            customerTableFoodCount[stoi(orders[i][1])][orders[i][2]]++;
        }

        //pushing the table and food content 
        vector<string> vec;
        vec.push_back("Table");
        for(auto food: foodsList)
            vec.push_back(food);
        ans.push_back(vec);

        //push the table and its count relative to the foods
        for(auto customerDetail: customerTableFoodCount) {
            vector<string> temp;
            temp.push_back(to_string(customerDetail.first));//gives table number

            for(auto food: foodsList) {
                if(customerDetail.second.find(food) != customerDetail.second.end())
                    temp.push_back(to_string(customerDetail.second[food]));
                else
                    temp.push_back("0");
            }
            ans.push_back(temp);
        }

        return ans;
    }
};