class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        unordered_map<int,int> delayed;

        int leftSize=0, rightSize=0;

        // Remove elements marked for deletion from left
        auto pruneLeft = [&](){
            while(!left.empty() && delayed.count(left.top())){
                int x=left.top();
                left.pop();
                if(--delayed[x]==0) delayed.erase(x);
            }
        };

        // Remove elements marked for deletion from right
        auto pruneRight = [&](){
            while(!right.empty() && delayed.count(right.top())){
                int x=right.top();
                right.pop();
                if(--delayed[x]==0) delayed.erase(x);
            }
        };

        // Maintain left size = right size or left size = right size + 1
        auto rebalance = [&](){
            if(leftSize > rightSize+1){
                pruneLeft();
                right.push(left.top());
                left.pop();
                leftSize--,rightSize++;
                pruneLeft();
            }
            else if(leftSize < rightSize){
                pruneRight();
                left.push(right.top());
                right.pop();
                rightSize--,leftSize++;
                pruneRight();
            }
        };

        // Insert incoming element
        auto insert = [&](int x){
            pruneLeft();

            if(left.empty() || x<=left.top()){
                left.push(x);
                leftSize++;
            }
            else{
                right.push(x);
                rightSize++;
            }

            rebalance();
        };

        // Erase outgoing element (lazy deletion)
        auto erase = [&](int x){
            pruneLeft();
            pruneRight();

            delayed[x]++;

            if(x<=left.top()){
                leftSize--;
                if(x==left.top()) pruneLeft();
            }
            else{
                rightSize--;
                if(!right.empty() && x==right.top()) pruneRight();
            }

            rebalance();
        };

        // Get median
        auto getMedian = [&]()->double{
            pruneLeft();
            pruneRight();

            if(k%2) return left.top();

            return (static_cast<double>(left.top())+
                    static_cast<double>(right.top()))/2.0;
        };

        vector<double> res;
        res.reserve(nums.size()-k+1);

        // Insert first window
        for(int i=0;i<k;i++) insert(nums[i]);

        res.push_back(getMedian());

        // Slide window
        for(int i=k;i<nums.size();i++){
            insert(nums[i]);
            erase(nums[i-k]);
            res.push_back(getMedian());
        }

        return res;
    }
};