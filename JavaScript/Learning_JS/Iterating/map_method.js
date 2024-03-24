//Creates new array from old array using some function
//Should use this one

const years = [1991, 1992, 1993, 1994, 1995, 1996]

const years_ago = years.map(year => 2022 - year) //Input to map module is each element from years array.
console.log(years_ago)