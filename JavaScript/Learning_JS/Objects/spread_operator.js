//UIs are broken up into individual components, which each have their own states
//State is usually immutable, can't change it but need to make a copy -> spread operator allows this
//Can use a state manager (eg. Redux or Vuex) if app is complicated

const userState = {
    name: "John",
}

const newuser_sate = {
    ...userState, //Spread operator, copies content of previous object
    age: 30 //Adding an age to user state
}