function person(fname, sname) {
    this.fname = fname
    this.sname = sname
}
function superhero(fname, sname) { //Superhero constructor function
    person.call(this, fname, sname) //Inherit person, change "this" to person
    this.is_superhero = true
}
person.prototype.get_full_name = function() { //Add member function (method) to person prototype
    return this.fname + " " + this.sname
}
superhero.prototype.fight_crime = function() { //Add member function (method) to superhero prototype
    console.log("fighting crime")
}
//Adds person.prototype methods to superhero prototype chain
superhero.prototype = Object.create(person.prototype) //Check order, for methods: superhero, superhero prototype, person prototype

const batman = new superhero("Bruce", "Wayne")
console.log(batman.get_full_name()) //Batman inherits person prototype
