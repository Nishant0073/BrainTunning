public class Solution {
    public bool IsPalindrome(int x) {
        int num1 = x;
        int num2 = 0;
        while(x>0){
            int cdig = x%10;
            x = x/10;
            num2 = num2*10 + cdig;
        }
        return num1 == num2;
    }
}

/*
base condi
1. less than 0 -> false;
2. equal to 0 -> true;

we can't compaire both numbers as we can not find first digit so,
we will create number from itselt and check if it's match
like

123
123%10 -> 3
12%10  -> 2
1%10   -> 1

will add all digits into one number
321 != 123 -> false;


*/