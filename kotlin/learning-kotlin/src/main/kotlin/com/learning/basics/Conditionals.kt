package com.learning.basics

fun main(args: Array<String>) {

    //Additional "if" functionality

    val myString = "Some String"
    val result1 = if(myString == "") {
        //Returns the last value written here
        "Empty(not returned)"
        20 //Returned
    } else {
        20
        "not Empty" //Returned
    }
    println(result1)
    println()

    //when statements

    val result2 = "Value"
    when(result2) {
        //Once first match is found, execution block ends
        //Can have a match leading to the execution of a block
        "Value" -> {
            println("Triggered execution block")
            println("Second statement")
                    }
        //Can have a match leading to a single execution
        is String -> println("It's a string") //Shouldn't execute as already matched above
        else -> println("No match found")
    }
    println()

    //When for assigning a value
    val result3 = when(result2) {
        "No match" -> "Value 0" //Returns "Value 0" -> assigns this to result3 variable
        is String -> {
            println("It's another String")
            "Value 1"
        }
        else -> "Value 2"
    }
    println(result3)
    println()
}