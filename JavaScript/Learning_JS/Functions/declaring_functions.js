//Difference between function declarations and function expressions

//---------------Function declaration (a.k.a function statement)--------------:

//- These are stand alone constructs and cannot be nested inside a functional block
//- Declarations must have a function name
//- These are executed before any other code -> *Function can be used in any code before or after declaration*
function geeksforGeeks1(paramA, paramB) {console.log(paramA + paramB)}

//---------------Function expression --------------:

//- Don't require a functional name
//- Can be stored in a variable 
//- Load and execute only when interpreter reaches the code -> *Function can only be used in code that follows expression*
let geeksforGeeks2 = function(paramA, paramB) {console.log(paramA + paramB)}
let gforg = (p_1, p_2) => {console.log(p_1 + p_2)}
const arrFunc = (p1, p2) => console.log(p1 + p2)

geeksforGeeks1('a', "b")
geeksforGeeks2(1, 2)
gforg(2, 3)
arrFunc(3, 4)


