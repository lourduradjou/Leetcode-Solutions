class Food {
    public:
        int foodRating;
        string foodName;

        Food(int foodRating, string foodName) {
            this->foodRating = foodRating;
            this->foodName = foodName;
        }

        bool operator < (const Food &other) const {
            return foodRating == other.foodRating ? foodName > other.foodName : foodRating < other.foodRating;
            //food is lexo smaller it should stay at the top means no change so if the 
            //condition is implied like this foodName < food2.foodName the condition will 
            //be true and the smaller will be changed and larger will be at the top so
            //to avoid this > is used in a inverted manner
        }
};

class FoodRatings {
public:
    //we need three data structures to implement this 
    //one is to maintain the foodratings and foodcuisine and the order of food
    //particular to the cuisine
    //first one is maintaining the food ratings in this sense it will be in up to date
    //so when there is mutated or duplicate objects in queue this will be used to remove
    //that things. second ds is used to get the cuisine based on this food name will
    //be useful on mapping the food and rating on the third ds where we need the cuisine
    //name . third one maintain the top food and its ratings with the proper cuisine name
    unordered_map<string , int> foodRatings;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, priority_queue<Food>> cuisineFoodRated;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            foodRatings[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineFoodRated[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatings[food] = newRating;
        string cuisineName = foodCuisine[food];
        cuisineFoodRated[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        auto highestRatedFood = cuisineFoodRated[cuisine].top();
        while(foodRatings[highestRatedFood.foodName] != highestRatedFood.foodRating)
        {
            cuisineFoodRated[cuisine].pop();
            highestRatedFood = cuisineFoodRated[cuisine].top();
        }

        return highestRatedFood.foodName;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */