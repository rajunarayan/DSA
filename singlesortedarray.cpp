int singleNonDuplicated(vector<int>& A) {
    int n = A.size();

    // Edge case: only one element
    if (n == 1)
        return A[0];

    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Boundary checks
        if (mid == 0 && A[0] != A[1])
            return A[0];

        if (mid == n - 1 && A[n - 1] != A[n - 2])
            return A[n - 1];

        // If mid itself is the single element
        if (A[mid] != A[mid - 1] && A[mid] != A[mid + 1])
            return A[mid];

        // Decide which side to search
        if (mid % 2 == 0) {
            // even index
            if (A[mid] == A[mid + 1])
                st = mid + 2;
            else
                end = mid - 1;
        } else {
            // odd index
            if (A[mid] == A[mid - 1])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
