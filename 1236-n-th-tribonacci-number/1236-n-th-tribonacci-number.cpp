class Solution {
public:
    int tribonacci(int n) {
     if(n<3)return (n!=0);
        int first=0;
        int second=1;
        int third=1;
        int fourth=0;

        for(int i=3; i<=n; i++)
        {
            fourth=first+second+third;
            first=second;
            second=third;
            third=fourth;
        }
        return third;
           
    }
};