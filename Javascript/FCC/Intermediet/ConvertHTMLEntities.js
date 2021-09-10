function convertHTML(str) {
  // HTML entities:
  const htmlEntities = {
    '&': '&amp;',
    '<': '&lt;',
    '>': '&gt;',
    '"': '&quot;',
    "'": '&apos;'
  };
  //use map function to return a filtered str with all entites
  const newStr = str
  .split('')
  .map(item => htmlEntities[item] || item)
  .join('');
  // console.log(newStr);
  return(newStr);
}

convertHTML("Dolce & Gabbana");