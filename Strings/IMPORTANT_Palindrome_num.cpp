
// https://practice.geeksforgeeks.org/problems/sum-of-digit-is-pallindrome-or-not2751/1/

class Solution
{
public:
    //  Sum of the digits of a Number
    int digiSum(int num)
    {
        int rem = 0, sum = 0;
        while (num != 0)
        {
            rem = num % 10;
            sum = sum + rem;
            num = num / 10;
        }

        return sum;
    }

    //  Find the Palindrome of a Number by Reversing it
    int isPal(int num)
    {
        int rem = 0, rev = 0, N = num;

        while (num != 0)
        {
            rem = num % 10;
            rev = (rev * 10) + rem;
            num = num / 10;
        }

        if (rev == N)
            return true;
        else
            return false;
    }

    //  Main Function
    int isDigitSumPalindrome(int N)
    {
        int sum = digiSum(N);
        return isPal(sum);
    }
};