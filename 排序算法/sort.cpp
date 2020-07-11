#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//排序算法的稳定性：两个元素的key相等，如果排序前后这两个元素的相对位置不会发生改变，
//则是稳定的，否则是不稳定的；
//内部排序；外部排序
class Solution{
    public:
    //快排 最好NlgN，最坏N^2（退化成冒泡排序），空间最好LgN，最差N，不稳定
    void Quicksort(vector<int>& nums, int low, int high){
        if(low >= high)
            return;
        int j = paritition(nums, low, high);
        Quicksort(nums, low, j - 1);
        Quicksort(nums, j + 1, high);
    }

    int paritition(vector<int>& nums, int low, int high){
        int v = nums[low];
        int i = low + 1, j = high;
        while(i <= j){
            if(nums[i] < v)
                i++;
            else
                swap(nums[i], nums[j--]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    //三路快排
    void Quick3way(vector<int>& nums, int low, int high){
        if(low >= high)
            return;
        int v = nums[low];
        int i = low + 1, lt = low, gt = high;
        while(i<=gt){
            if(nums[i] > v)
                swap(nums[i], nums[gt--]);
            else if(nums[i] < v)
                swap(nums[i++], nums[lt++]);
            else
                i++;
        }
        Quick3way(nums, low, lt - 1);
        Quick3way(nums, gt + 1, high);
    }

    //插入排序 最好 N， 最差O(N^2)， 平均N^2, 空间 1， 稳定
    void Insertsort(vector<int>& nums){
        int n = nums.size();
        for (int i = 1; i < n; ++i){
            int tmp = nums[i];
            int j = i;
            while(j>0 && nums[j-1] > tmp){
                nums[j] = nums[j-1];
                j--;
            }
            nums[j] = tmp;
        }
    }

    //希尔排序
    void Shellsort(vector<int>& nums){
        int n = nums.size();
        int h = 1;
        while(h < n/3)
            h = 3 * h + 1;
        while(h>=1){
            for (int i = h; i < n; ++i){
                int tmp = nums[i];
                int j = i;
                while(j>=h && nums[j-h] > tmp){
                    nums[j] = nums[j - h];
                    j -= h;
                }
                nums[j] = tmp;
            }
            h /= 3;
        }
    }
    
/*********************************************************************/

    void sink(vector<int>&nums, int p, int N){ 
	//对一个节点p进行下沉，使其满足堆的有序性
        while(2 * p + 1 <= N){
            int j = 2 * p + 1;
            if(j < N && nums[j] < nums[j+1])  //找到最大的子节点
                j++;
            if(nums[p] >= nums[j])
                break;
            swap(nums[p], nums[j]);
            p = j;    
            }
    }
    //堆排序 时间都是NlgN， 空间1， 不稳定
    void heapsort(vector<int>&nums){
        int N = nums.size()-1;
        for(int p = N/2; p>=0; p--){ //为什么从N/2开始？因为N/2后面都是叶子节点
            sink(nums, p, N); 
        }
        //此时堆已经搭建完毕，最大元素在0处
         
        while(N > 0){
            swap(nums[0],nums[N--]); //把最大的元素换到最后面去
            sink(nums, 0, N); //重新构建堆
        }
    }

/*************************************************************************/
//归并排序 时间NLgN，空间N，稳定

    void mergesort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }
    
    void merge(vector<int>& nums, int lo, int mid, int hi){
        int i = lo, j = mid+1;
        //创建辅助数组
        int aux[nums.size()];

        for (int k = lo; k <= hi; ++k)
            aux[k] = nums[k];

        for (int k = lo; k <= hi; ++k){
            if(i > mid)
                nums[k] = aux[j++];
            else if(j > hi)
                nums[k] = aux[i++];
            else if(aux[i] > aux[j])
                nums[k] = aux[j++];
            else
                nums[k] = aux[i++];
        }
    }

/***************************************************************/
//冒泡排序 N^2 每次把最大的元素排定
    void bubblesort(vector<int>& nums){
        int N = nums.size();
        for (int i = 0; i < N; ++i){
            bool flag = true;   //如果一趟下来没有发生交换，说明已经排好了
            for (int j = 0; j < N - i - 1; ++j){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j + 1]);
                    flag = false;
                }
            }
            if(flag)
                break;
        }
    }

/**************************************************************/
//选择排序 每次把最小的在前面排定 不稳定
    void selecesort(vector<int>& nums){
        const int N = nums.size();
        for (int i = 0; i < N; ++i){
            int min = i;
            for (int j = i + 1; j < N; ++j){
                if(nums[min] > nums[j])
                    min = j;
            }
            if(min != i)
                swap(nums[i], nums[min]);
        }
    }


};

int main(){
    Solution slv;
    vector<int> nums = {5, 6, 5, 2, 9, 1, 0, -9};
    //slv.Quicksort(nums, 0, nums.size() - 1);
    //slv.Quick3way(nums, 0, nums.size()-1);
    slv.selecesort(nums);

    for(int num : nums){
        cout << num << ',';
    }
    return 0;
}