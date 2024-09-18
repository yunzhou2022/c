a = [1, 1, 2, 3, 4, 5];
b = [1, 2, 4, 5];

function merge(a, b) {
  let c = [];

  let i = 0,
    j = 0,
    lenA = a.length,
    lenB = b.length;

  while (i < lenA && j < lenB) {
    if (a[i] < b[j]) {
      c[i + j] = a[i];
      i++;
    } else {
      c[i + j] = b[j];
      j++;
    }
  }
  if (i == lenA) {
    c = c.concat(b.slice(j));
  }
  if (j == lenB) {
    c = c.concat(a.slice(i));
  }
  return c;
}
const c = merge(a, b);
console.log(c);
