function findPalindrome(s: string, index: number, isEven: boolean) {
    let palindrome = "";
    let left = index;
    let right = index;
    if (isEven) {
        right++;
    }
    while (left >= 0 && right < s.length) {
        if (s[left] === s[right]) {
            if (left === right) palindrome = s[left]
            else {
                palindrome = s[left] + palindrome;
                palindrome = palindrome + s[right];
            }
            left--;
            right++;
        }
        else return palindrome;
    }

    return palindrome;
}

function longestPalindrome(s: string): string {
    let result = "";
    for (let i = 0; i < s.length; i++) {
        const res1 = findPalindrome(s, i, false);
        const res2 = findPalindrome(s, i, true);
        const currRes = res1.length > res2.length ? res1 : res2;
        result = currRes.length > result.length ? currRes : result;
    }
    return result;
};