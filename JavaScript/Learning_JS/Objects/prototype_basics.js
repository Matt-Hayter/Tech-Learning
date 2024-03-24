//- Prototypes are the method for which JS objects inherit features from one to another
//- Each object type has a member prototype object, shared between those objects
//- 1. When a property of an object can't be found in the object itself, it's prototype is searched for the property
//- 2. If the property is not founnd in the prototype object, it is searched for in the prototype's prototype, and so on until undefined is returned

function person(fname, sname) { //Member variable/function definitions appear to do effectively the same thing within constructor function as they do using object.prototype
    this.fname = fname
    this.sname = sname
}
const person1 = new person("Bruce", "Wayne")
const person2 = new person("Clark", "Klent")

person1.protoype.get_full_name = function () { //Add function object to all person instances (similar to static member data in C++)
    return this.first_name + " " + this.surname
}