//------Variables in construtor functions------:
//- Use Pascal notation (FirstWordIsCapital) for constructor function names


function PersonFunc(name) { //Constructor function is called when the "new" keyword in used
    //Empty function object created
    this.name = name
}
const p1 = new PersonFunc("Erika") //"new" keyword calls constructor function, named PersonFunc
const p2 = new PersonFunc("Andrew")