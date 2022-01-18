/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// wecan use stack! just think how nestedint goes in.
// just put in elems at once then we dont need idx

class NestedIterator {
public:
    int nextNum;
    stack < NestedInteger > S;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        // int cnt=0;

        for(int i=0;i<nestedList.size();i++){
            S.push(nestedList[nestedList.size()-i-1]);
        }
        
    }
    
    int next() {
        
        return nextNum;
    }
    
    bool hasNext() {        
        while(!S.empty()){
            NestedInteger ni=S.top();
            S.pop();

            if(ni.isInteger()){
                nextNum=ni.getInteger();
                return true;
            }
            else{
                vector<NestedInteger> v=ni.getList();
                int vsize=v.size();
                for(int i=0;i<vsize;i++){
                    S.push(v[vsize-i-1]);
                }
            }
        }
        return false;
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */