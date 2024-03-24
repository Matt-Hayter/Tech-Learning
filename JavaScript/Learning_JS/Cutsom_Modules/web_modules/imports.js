//For demonstrating custom module imports
//Modules can be required() or imported
//Here, modules are enabled through the index.html file

//Default import
import imported_Fruit from "/Modules/web_modules/default_exports.js" //imported name doesn't have to match module name for default
//Named imports
import { sayHello, sayBye } from "/Modules/web_modules/named_exports.js"

sayHello()
sayBye()
console.log(imported_Fruit)