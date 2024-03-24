//Named export
/*
- .js custom modules can be run using html or Vue
- Exporting several values for one module (file)
- Have to use the same name when importing (if not using alias?)
- Uses curly braces to get values out during import
*/

export default
{    
    going_dam() {
        console.log("Dam")
    }
}

const sayHello = () => console.log("Hello")
const sayGoodbye = () => console.log("Goodbye!")

export {sayHello, sayGoodbye}

//Or (cleaner):

export const sayHi = () => console.log("Hi")
export const sayBye = () => console.log("Bye!")

