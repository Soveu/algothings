class Solution {
public:
    struct Pair {
        int number;
        int counter;
    };

    int repeatedNTimes(const vector<int>& A) {
        bool was[10000];
        memset(was, 0, sizeof(was));
        
        for(const int& x : A) {
            if(was[x]) {
                return x;
            }
            
            was[x] = true;
        }

        return 0;
    }
};

