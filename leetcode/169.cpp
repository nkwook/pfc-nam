class Solution {
public:
    int majorityElement(vector<int>& nums) {
        	Int majE;
	Int cnt=0;
	
	for(auto i:nums){
	
	if(cnt==0){
			majE=i;
			cnt++;
}else{
	if(i==majE) cnt++;
	Else cnt –;
}
}
Return majE;
	
    }
};