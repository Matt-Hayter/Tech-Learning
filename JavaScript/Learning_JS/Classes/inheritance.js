class person
{
    constructor(fname, sname) {
        this.firstname = fname
        this.surname = sname
    }
    say_my_name() { //Member data and functions are inherited by child classes
        return this.firstname + " " + this.surname
    }
}

class superhero extends person //Child class of person (is_a)
{
    constructor(fname, sname) { //Superhero constructor
        super(fname, sname) //Calls person constructor, passing it the required variables
    }
    fightcrime() {
        console.log("Fighting Crime")
    }
}

const class_p1 = new superhero("Bruce", "Wayne")
console.log(class_p1.say_my_name())