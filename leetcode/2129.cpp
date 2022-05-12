class Solution {
public:
    string capitalizeTitle(string title) {
        bool isCapital=true;
        int first=0;
        int second=0;
        while(second<title.size()){
            if(title[second]==' '){
                if(second-first>2 && title[first]>='a' && title[first] <='z'){
                    title[first]-=32;
                }
                first=second+1;
            }else if(title[second]>='A' && title[second]<='Z'){
                title[second]+=32;
            }
            second++;  
        }
        
        if(second-first>2 &&( title[first]>='a' || title[first] <='z') ) title[first]-=32;
        
        
        return title;
    }
};