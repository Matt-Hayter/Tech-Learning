//Used for objects and arrays -> clean syntax for pulling copying elements from obj/arr

const user = {
    name: "Matt",
    email: "some_email@outlookcom",
    address: {
        house_number: "1",
        street: "Sayes Court",
        town: "Addlestone"
    }
}

const {name, email} = user //Copied object values to new variables
const {address: {town}} = user //Copied to a new city variable
console.log(name, email, town)