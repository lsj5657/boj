class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        int n=numbers.length;
        
        for (int i=0; i<(1<<n); i++){
            int sum=0;
            for (int j=0; j<n; j++){
                if((i&(1<<j))>0) sum+=numbers[j];
                else sum-=numbers[j];
            }
            
            if(sum==target) answer++;
        }
        
        
        return answer;
    }
}