#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int partition(vector<int>& nums, int lo, int hi){
    int v = nums[lo];
    int i = lo + 1, j = hi;
    while(i <= j){
        if(nums[i] > v){
            swap(nums[i], nums[j--]);
        }
        else
            i++;
    }
    swap(nums[j], nums[lo]); //重要，把v放到中间，使整体有序
    return j;
}

void quicksort(vector<int>& nums, int lo, int hi){
    if(lo >= hi)
        return;
    int j = partition(nums, lo, hi);
    quicksort(nums, lo, j - 1);
    quicksort(nums, j + 1, hi);
}

void quick3way(vector<int>& nums, int lo, int hi){
    if(lo >= hi)
        return;
    int v = nums[lo];
    int lt = lo, i = lo + 1, gt = hi;
    while(i <= gt){
        if(nums[i] > v)
            swap(nums[i], nums[gt--]);
        else if(nums[i] < v)
            swap(nums[lt++], nums[i++]);
        else
            i++;
    }
    quick3way(nums, lo, lt-1);
    quick3way(nums, gt + 1, hi);
}

void insertsort(vector<int>& nums){
    int N = nums.size();
    for (int i = 1; i < N; ++i){
        int tmp = nums[i];
        int j = i;
        while(j > 0 && nums[j-1] > tmp){
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = tmp;
    }
}

void sink(vector<int>& nums, int p, int N){
    while(2*p + 1 <= N){
        int j = 2 * p + 1;
        if(j < N && nums[j] < nums[j+1])
            j++;
        if(nums[p] >= nums[j])
            break;
        swap(nums[j], nums[p]);
        p = j;
    }
}

void heapsort(vector<int>& nums){
    int N = nums.size() - 1;
    for (int p = N / 2; p >= 0; --p){
        sink(nums, p, N);
    }
    while(N > 0){
        swap(nums[0], nums[N--]);
        sink(nums, 0, N);
    }
}


int main(){
    
    vector<int> nums = {5, 6, 5, 2, 9, 1, 0, -9};
    //quick3way(nums, 0, nums.size() - 1);
    //slv.Quick3way(nums, 0, nums.size()-1);
    //slv.selecesort(nums);
    heapsort(nums);
    for(int num : nums){
        cout << num << ',';
    }
    return 0;
}