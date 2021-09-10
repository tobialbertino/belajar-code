function rot13(str) {
  const rot = {
    'A': 'N',
    'B': 'O',
    'C': 'P',
    'D': 'Q',
    'E': 'R',
    'F': 'S',
    'G': 'T',
    'H': 'U',
    'I': 'V',
    'J': 'W',
    'K': 'X',
    'L': 'Y',
    'M': 'Z',
    'N': 'A',
    'O': 'B',
    'P': 'C',
    'Q': 'D',
    'R': 'E',
    'S': 'F',
    'T': 'G',
    'U': 'H',
    'V': 'I',
    'W': 'J',
    'X': 'K',
    'Y': 'L',
    'Z': 'M'
  }
  // console.log(rot['A'])
  let newStr =  
  str.split('')
  .map(item => {
    if (item in rot){
      return rot[item];
    } else {
      return item;
    }
  })
  .join('');
  // console.log(newStr);
  return newStr;
}

rot13("SERR PBQR PNZC");