class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        //the basic intuition is when a frog croaks ..it makes the 'c' and 
        //when i stops the letter 'k' comes, in between if any thing comes like
        //ex crooks , here double o comes and if that o doesn't belong to any other 
        //frogs then return -1 , this step is found by with the help of hashing

        //why --cnt[n-1] < 0 , why n-1 ?
        //because: if a letter comes other than c and k that is start and end in this case
        //we have to check the letter, whether it is coming sequentially by 
        //checking the previous letter of it exits or comes before
        //ex: croakcrook here at index 1 it will check cnt[1-1] = cnt[0] that is whether 'c' exits else return -1;
        int cnt[5] = {}, frogs = 0, maxFrogs = 0;

        for (auto ch: croakOfFrogs) {
            int n = string("croak").find(ch);
            cnt[n]++;

            if (n == 0) //a frogs start singing
                maxFrogs = max(maxFrogs, ++frogs);
            else if (cnt[n - 1]-- == 0)
                return -1;
            else if (n == 4)
                frogs--; //a frogs finishes singing
            
        }

        return (frogs == 0) ? maxFrogs : -1;

    }
};