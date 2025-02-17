시간복잡도 : O(logN)

Basic Binary Search 코드
'''
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid + 1; // target은 오른쪽에 있음
        } else {
            right = mid - 1; // target은 왼쪽에 있음
        }
    }
    return left; // 삽입 위치 반환
}
'''
