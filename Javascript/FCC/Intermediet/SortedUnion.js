function uniteUnique(...arr) {
  const flatArr = [...new Set(arr.flat())];
  // console.log(flatArr);
  return flatArr;
}

uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]);