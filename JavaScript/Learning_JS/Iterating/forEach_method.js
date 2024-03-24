//Calls a function for each element in an array
//Doesn't seem to imporve code much?

const printNumbers = {
    phrase: 'The current value is:',
    numbers: [1, 2, 3, 4],
    loop() {
      this.numbers.forEach((number) => { //Feeds input
        console.log(this.phrase, number)
      })
    },
    equiv_loop() {
      for(num of this.numbers) {
        console.log(this.phrase, num)
      }
    }
  }
  
  printNumbers.loop()
  printNumbers.equiv_loop()