function checkCashRegister(price, cash, cid) {
  //all money values are multiplied by 100 to deal with precision errors involved with decimals 
  const denomination = [10000, 2000, 1000, 500, 100, 25, 10, 5, 1,];

  function transaction(price, cash, cid) {
    let changeNeeded = (cash - price) * 100;
    //money will be pushed to the second value in each array
    let moneyProvided = [
    ["ONE HUNDRED", 0], 
    ["TWENTY", 0], 
    ["TEN", 0], 
    ["FIVE", 0], 
    ["ONE", 0], 
    ["QUARTER", 0], 
    ["DIME", 0], 
    ["NICKEL", 0], 
    ["PENNY", 0],
  ];
  //take the cid, reverse it (like in Roman Numerals exercise), multiply values by 100
  let availableCash = [...cid].reverse().map(el => [el[0], el[1] * 100]);
  //get the total sum of all cash and divide by 100
  let sumOfCash = availableCash.reduce((a, b) => (a + b[1]),0) / 100;
  //if sumOfCash is exact change needed return
  if (sumOfCash === changeNeeded / 100) {
    return {status: "CLOSED", change: [...cid]};
  }
  //else, run this function
  else for (let i = 0; i < availableCash.length; i++) {
    //if denomination values are less than changeNeeded and availableCash values are greater than 0, run the while loop
      while (denomination[i] <= changeNeeded && availableCash[i][1] > 0) {
        //1. moneyProvided array is increased by denomination value
        moneyProvided[i][1] += denomination[i];
        //2. changeNeeded is decreased by same denomination value
        changeNeeded -= denomination[i];
        //3. availableCash is also decreased by same denomination value
        availableCash[i][1] -= denomination[i];
      }
    };
    
   //clean up the moneyProvided array by
    let change = moneyProvided
    //1. resetting the money values by dividing by 100
    .map(el => [el[0], el[1] / 100])
    //2. filtering out all non-empty dollar and value arrays
    .filter(el => el[1] !== 0);
    //calculate the total of the change array
    let changeTotal = change.reduce((a, b) => (a + b[1]),0);
    //if the total change is less than the change needed
    if (changeTotal < changeNeeded) {
        return {status: "INSUFFICIENT_FUNDS", change: []};
    }
    return {status: "OPEN", change};
  }

  //this is where the transaction function is called
  let answer = transaction(price, cash, cid);
  //here the final answer is provided if the 2 if statements don't catch it first
  return answer;
};