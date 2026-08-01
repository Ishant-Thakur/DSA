class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
        swap(nums1, nums2);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = nums1.size() + nums2.size();
        int low = 0;
        int high = n1;
        float median;
        while(low<=high){
            int mid = low + (high-low)/2;
            int s = (total+1)/2-mid;
            float l1 ;
            float r1 ;
            float l2 ;
            float r2 ;
            if(mid==0){
                l1 = INT_MIN;
            }
            else{
                l1 = nums1[mid-1];
            }
            if(s==0){
                l2 = INT_MIN;
            }
            else{
                l2= nums2[s-1];
            }
            if(mid==n1){
                r1 = INT_MAX;
            }
            else{
                r1= nums1[mid];
            }
            if(s==n2){
                r2 = INT_MAX;
            }
            else{
                r2= nums2[s];
            }
            if(l1>r2){
                high = mid-1;
            }
            else if(l2>r1){
                low = mid+1;
            }
            else{
                if(total%2==0){
                    median = (max(l1,l2)+min(r1,r2))/2;
                    break;
                }
                else{
                    median = max(l1,l2);
                    break;
                }
            }
        }
        return median;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna