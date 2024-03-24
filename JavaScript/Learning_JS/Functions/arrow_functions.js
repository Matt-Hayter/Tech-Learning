//Introduced in 2015 ES6. Compact alternatives to function expressions (not function declarations!) (similar to lambda functions)
//Best to use this over standard functions? -> apparently

//- Don't have bindings to .this, .arguments, .super methods or be used as constructor functions
//- Don't have to return a values
//- Can't use yield or be created as generator functions


//Function expression before arrow function:
const func_1 = function(param) {return param * 2}
console.log(func_1(2))

//Using arrow function:
const times_two_v2 = (params) => params * 2
console.log(times_two_v2(3))