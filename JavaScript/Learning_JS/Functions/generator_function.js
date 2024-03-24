//function* used to create a generator function
const generator = function*(iterations) {
  for(let i = 0; i < iterations; i++) {
    yield i //yield keyword for generators
  }
}

const gen = generator(4) //Function returns generator object
console.log(gen.next().value)
console.log(gen.next().value)
console.log(gen.next().value, "\n")

//Generator function for fibonacci series:
var fibGenerator = function*(callCount) {
  let firstNum = 0
  let secondNum = 1
  while(true) {
    yield firstNum;
    [firstNum, secondNum] = [secondNum, secondNum + firstNum]
  }
};


const genFib = fibGenerator(6);
console.log(genFib.next().value); // 0
console.log(genFib.next().value); // 1
console.log(genFib.next().value); // 1
console.log(genFib.next().value); // 2
console.log(genFib.next().value); // 3
console.log(genFib.next().value); // 5
console.log(genFib.next().value); // 8