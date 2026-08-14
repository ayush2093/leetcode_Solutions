class Solution {
public:
    int maxArea(vector<int>& height) {
      int left=0,right=height.size()-1;
      int maxwater=INT_MIN;
      while(left<right){
        int w=right-left;
        int h=min(height[left],height[right]);
        int area=w*h;
        maxwater=max(area,maxwater);
        if(height[left]<height[right])left++;
        else right--;
      } 
      return maxwater; 
    }
};