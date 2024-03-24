function person(fname, sname) {
    this.fname = fname
    this.sname = sname
}
//"this" keyword in person now used as "this" keyword in superhero -> superhero inherits properties from person
function superhero(fname, sname) {
    person.call(this,fname,sname) //Call superconstructor is used to delegate "this" keyword to another object
}