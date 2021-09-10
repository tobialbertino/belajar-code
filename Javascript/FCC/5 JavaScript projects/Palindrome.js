function palindrome(str) {
  const newStr = str.replace(/_|\W/g, '').toLowerCase();
  console.log(newStr);
  let isPalindrome = false;
  for (let i = 0; i < newStr.length/2; i++) {
    if(newStr[i] === newStr[newStr.length-1-i]) {
      isPalindrome = true;
    } else {
      return false;
    }
  }
  if(isPalindrome) {
    return true;
  }
}

console.log(palindrome("A man, a plan, a canal. Panama"));