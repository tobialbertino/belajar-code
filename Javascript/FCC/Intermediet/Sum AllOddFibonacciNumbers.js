function sumFibs(num) {
  let sum1 = 0;
  let sum2 = 1;
  let result = 0;
  for(; sum2<=num;) {
    if (sum2 % 2 !== 0) {
      result += sum2;
    }
    sum2 += sum1;
    sum1 = sum2 - sum1;
  }
  console.log(result);
  // return result;
}

sumFibs(1000);