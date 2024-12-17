class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, k,a=0, b=0,t;

        for ( i= 0; i < s.size(); i++ ){
            b=1;

            for ( j= i+1; j < s.size(); j++ ){
                for (k=i; k<j; k++)
                if (s.substr(k,1)==s.substr(j,1))
                    t = 0;
                if (t==0){
                    t=1;
                    break;
                }
                b+=1;

            }
            a = std:: max(a,b);


        }

        return a;
    }
};
