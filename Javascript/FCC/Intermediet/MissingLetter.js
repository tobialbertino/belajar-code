function fearNotLetter(str) {
  let newArr = [];
  const compare = str.split('')
  const arr = compare.map(item => 
    item.charCodeAt(item)
  );

  let counter = arr[0];

  for(let i = 0; i < arr.length; i++) {
    if (arr[i] !== counter) {
      newArr.push(counter);
      counter++;
    } 
    
    counter++;
  }
  // console.log(newArr);
  // console.log(arr);
  if( !newArr.length ) {
    return undefined
  }
  return String.fromCharCode(newArr[0]);
}

fearNotLetter("abcf");