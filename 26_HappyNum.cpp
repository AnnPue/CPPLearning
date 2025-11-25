class Solution {
public:
    bool happynum(int n) {
        if (n == 1) return true;
        else if(n < 10)return false;
        int i = 0;
        int sum = 0;
        while(n != 0){
            i = n % 10;
            sum += i * i;
            n /= 10;
        }
        return happynum(sum);
    }
};