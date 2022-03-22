//TLE
//TC=nlogn
class Solution {
public:
    void fnl(vector<int>& ans, vector<int> nums, int target, int start, int end){
        int mid = start + (end-start)/2;
        while(start<=end){
            if(target==nums[mid]){
                ans.push_back(mid);
                if(nums[mid]==nums[mid+1])
                    ans.push_back(mid+1);
                ans.push_back(mid-1);
            }
            if(target<nums[mid]){
                fnl(ans, nums, target, start, mid-1);
            }
            if(target>nums[mid]){
                fnl(ans, nums, target, mid+1, end);
            }
           
        }
        ans.assign(2,-1);
        return;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int x=nums.size()-1;
        fnl(ans, nums, target, 0, x);
        return ans; 
    }
};

//TC=logn
class Solution {
public:
 int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

public:
    vector<int> searchRange(vector<int>& arr, int key) {
        vector<int> ans;
        int n=arr.size();
        ans.push_back(firstOcc(arr, n, key));
        ans.push_back(lastOcc(arr, n, key));
        return ans; 
    }
};
