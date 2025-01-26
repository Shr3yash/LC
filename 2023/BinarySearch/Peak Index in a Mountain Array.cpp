//n
int i=0;
while(arr[i]<arr[i+1])i++;
return i;
//logn
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=(s+e)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1])
            {
                s=mid+1;
            }
            else
                e=mid;
            mid=(s+e)/2;
        }
        return s;

    }
};
