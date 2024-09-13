class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int m = queries.length;

        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }
        
 
        int[] result = new int[m];
        for (int i = 0; i < m; i++) {
            int start = queries[i][0], end = queries[i][1];
            result[i] = start > 0 ? arr[end] ^ arr[start - 1] : arr[end];
        }
        
        return result;
    }
}
