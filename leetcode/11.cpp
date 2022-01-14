// also good to only doing 
// start++, end--;
// only the lowest height determines size
// also width is constantly decreasing
// so I tried to consider case only height increases



class Solution {
public:
    int maxArea(vector<int>& height) {
      int start=0;
      int end=height.size()-1;
      
      int maxSize=0;

      int size=0;
      int h=0;

      while(start!=end){
        
    
        if(height[start]>height[end]) h=height[end];
        else h=height[start];
        size=(end-start)*h;

        if(maxSize<size) maxSize=size;

        if(height[start]>height[end]){
        }else{
          int newStart=start;
          while(height[start]>=height[newStart] && newStart!=end){
            newStart++;
          }
          start=newStart;
        }

      }
      return maxSize;
    }



};