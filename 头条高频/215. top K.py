class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0 or len(arr) == 0:
            return []
        # 要找下标为 k-1 的数
        return self.quickSearch(arr, 0, len(arr)-1, k-1)

    def quickSearch(self, arr, lo, hi, k):
        #每快排切分1次，找到排序后下标为j的元素，如果j恰好等于k就返回j以及j左边所有的数；
        j = self.partition(arr, lo, hi)
        if j == k:
            return arr[:j+1]
        elif j > k:
            return self.quickSearch(arr, lo, j-1, k)
        else:
            return self.quickSearch(arr, j+1, hi, k)
        
    def partition(self, arr, lo, hi):
        v = arr[lo]
        i, j = lo, hi
        while i <= j:
            if arr[i] <= v:
                i += 1
            elif arr[i] > v:
                t = arr[j]
                arr[j] = arr[i]
                arr[i] = t
                j -= 1
        # 最后要把这个位置的数排定
        arr[lo] = arr[j]
        arr[j] = v
            
        return j