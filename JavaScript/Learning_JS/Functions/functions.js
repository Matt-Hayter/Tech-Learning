//Functions are also objects in JS, and can have member data and methods (member functions)

//Global function declaration (can be used anywhere, even before it's introduced in code)
//This is a "Factory function" (see objects folder), as it returns a new object
function outer_func_1() {
    //Counter is included in scope of both outer and inner functions
    let counter = 0
    //Standard function declaration, within scope of outer_func_1
    function inner_func_1() {
        counter++
        console.log(counter) //Output stream to console
    }
    return inner_func_1 //Returns inner_func_1 object
}
const func_1 = outer_func_1() //Envokes outer_func_1 and gives return value (inner_func_1 object)
const func_2 = outer_func_1() //Generate another object
func_1() //Envokes func_1 (inner_func_1 object, with a void return value). Counter's prev value is remembered as it's included within the scope of inner_func_1()
func_1() //Same as above (member data updated)
func_2() //Do the same for other object, can see that it is unique

console.log("\n")
//------------------------------------------------------------------

function outer_func_2() {
    //function object still created, but as this is not a constructor function (no new keyword) and
    //not a factory function (doesn't return object), this function object has no impact outside of scope
    let counter = 0
    this.count = 9
    function inner_func_2() {
        counter++
        console.log(counter) //Output stream to console
    }
    return inner_func_2() //Returns function result
}
const var_1 = outer_func_2() //Envokes outer_func_2(), which envokes inner_func_2(). var_1 is undefined, as nothing is returned.
