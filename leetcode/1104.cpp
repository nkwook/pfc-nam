class Solution {
public: // lgN 
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        
        int level=0;  
        int i=label;
        while(i){
            i/=2;
            level++;
        }
        
        int pos=label;
        if(level%2==0){
            pos=(1<<level) + (1<<(level-1)) - label -1;
        }
        
        while(pos){
            cout << pos << ' ' << level << '\n';
            int num=pos;
            if(level%2==0){
                num=(1<<level) + (1<<(level-1)) - pos -1;
            }                
            result.push_back(num);

            level--;
            pos/=2;
        }
        reverse(result.begin(), result.end());
        return result;
        
        
        
    }
};


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int > ztree(1, 0);
            int cnt=1;
            int level=1;
            int labelIndex=-1;
            bool toRight=true;
            while(true){
                int num=cnt;
                if(!toRight){
                   num=(1<<level)-(cnt+1 - (1<<(level-1)));
                }
                  
                ztree.push_back(num);
             
                 if(num==label){
                    labelIndex=cnt;
                    break;
                }


                cnt++;
                
                if(cnt >= (1<<level)){
                    toRight=!toRight;
                    level++;
                }
            }
            
            vector<int> result;
            int i=labelIndex;
            while(i){
                result.push_back(ztree[i]);
                i/=2;
            }
            reverse(result.begin(), result.end());
            return result;
            
        }
    
};