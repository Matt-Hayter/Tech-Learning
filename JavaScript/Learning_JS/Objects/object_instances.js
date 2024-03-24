function person(fname, sname) {
    this.fname = fname
    thid.sname = sname
}
const person1 = new person("Bruce", "Wayne")
const person2 = new person("Clark", "Klent")

person1.get_full_name = function () { //Just add function object to person 1 instance
    return this.first_name + " " + this.surname
}