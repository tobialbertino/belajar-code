function steamrollArray(arr) {
  const flat = [].concat(...arr);
  const test =  flat.some(Array.isArray) ? steamrollArray(flat) : flat;
  // console.log(test);
  return test;
}

steamrollArray([1, [2], [3, [[4]]]]);