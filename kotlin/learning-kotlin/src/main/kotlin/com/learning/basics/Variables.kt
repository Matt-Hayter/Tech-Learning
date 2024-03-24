package com.learning.basics

fun main(args: Array<String>) {
    /*

    Mutable reference vs immutable reference:

        Kotlin variables that store objects only store references to objects, not the instance itself
        Two types of variables:
        1. val (from value)—Immutable reference. A variable declared with val can’t be reassigned after it’s initialized.
        2. var (from variable)—Mutable reference. A variable declared with var can be reassigned after it's initialized.
        Note that, even though a val reference is itself immutable and can’t be changed, the object that it points to may be mutable.

    Mutable object vs Immutable object:

        Two types of Objects:
        1. Mutable: Object state can be changed
        2. Immutable: Object state cannot be changed

        Immutable objects include: all number types, strings, booleans and tuples. In most languages, primitives are known as being
        immutable as there's no way to change them after being initialised, they can only be replaced

        In Kotlin, these aren't technically primitive types, but object wrappers of primitive types. When possible kotlin uses primitives,
        but only if they are non-nullable (primitives are not nullable in the JVM)
    */

    //mutable variables: var

    var streetNumber: Int //Declare variable with mutable reference
    streetNumber = 1 //Initialise variable with mutable reference
    //Explicit type
    var streetName1: String = "Explicit type"
    //Inferred type
    var streetName2 = "Inferred type" //Don't need to write out type -> compiler can infer

    //variables with immutable variables (const, recommended if mutable not needed): val

    val postcode = "E11 P1"
    //postcode = "ABC D1" is not possible here
}