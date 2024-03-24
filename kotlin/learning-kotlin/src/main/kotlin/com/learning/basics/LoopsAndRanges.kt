package com.learning.basics

fun main(args: Array<String>) {

    //For loops:

    for(a in 1 .. 100) { //Assumes a is int
        println(a) //Auto converts int to string for print
    }
    //Create range of numbers
    val numbers = 0 .. 100 step 5
    for(a in numbers) {
        println(a)
    }
    //Alternative syntax
    for (b in 100 downTo 1 step 5) {
    }
    val capitals = listOf("London", "Paris", "Rome")
    for(capital: String in capitals) {
        println(capital)
    }
    //With index (python enumerate)
    for((index, value) in capitals.withIndex()) {
        println("The element at $index is $value")
    }

    //While loops:

    //Check condition -> execute block
    var i = 100
    while(i > 0) {
        i--
    }

    //Execute block -> check condition
    var x = 10
    do {
        println(x)
        x--
    } while (x >= -10)

    //Breaking out of loops
    loop@ for(i in 1 .. 100) {
        for(j in 1 ..100) {
            if(j % i == 0) {
                continue@loop //Continue on outer loop
            } else if(j/i == 9) {
                break
            }
        }
    }
}