package com.learning.basics

fun main(args: Array<String>) {
    //Types:

    //All types are objects (no primitive types, unlike java)
    val myByte: Byte //Integer values from -128 to 127 -> saves memory

    val myBool: Boolean //1 bit

    val myShort: Short //2 bytes
    val myInt: Int //4 bytes
    val myLong: Long //8 bytes

    val myFloat: Float //4 bytes
    val myDouble: Double //8 Bytes

    val myChar: Char //2 bytes
    val myString: String //variable

    //For for types that cannot be inferred, can still refer shorthand using suffix
    val myLong1 = 10L
    val myFloat1 = 10F
    val myHex = 0x0F
    val myBinary = 0xb01

    //Type conversions:

    val myInt1 = 100
    val myNewInt = myInt1 //Assumes to be int if not specified
    //No implicit conversions
    val myLong2: Long = myInt1.toLong() //Have to explicitly convert between types

    //Type assumptions:

    val myChar1 = 'A' //Single quotes fo r char
    val myString1 = "A String" //Double for string
    val myInt2 = 10
    val myFloat2 = 10.1

    //Strings:

    val escapeCharacters = "alal \n"
    val concatenation = "Hello" +
            "my" +
            "name"
    val multiplelines = """
            This is a string on line 1
            This is a string on line 2
        """
    //String interpolation
    val years = 10
    val message1 = "A decade is $years years"
    //Calling method within string interpolation -> curly brackets
    val name = "Mary"
    val message2 = "Length of name is ${name.length}"
}