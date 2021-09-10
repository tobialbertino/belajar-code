function sumPrimes(num) {
  // check prime number 
  const isPrime = (num) => {
    for(let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0)
        return false;
    }
    return true
  }

  // check all members for prime numbers 
  let sum = 0;
  for (let i = 2; i <= num; i++) {
    if (isPrime(i))
      sum += i;
  }

  // console.log(sum);
  return sum;
}

sumPrimes(10);