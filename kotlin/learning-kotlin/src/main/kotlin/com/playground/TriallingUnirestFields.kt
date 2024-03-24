package com.playground

import java.io.File
import java.util.*

fun main(args: Array<String>) {
    val uploadValue = if (File("").exists()) File("") else null
    val fields = mapOf("upload" to uploadValue)
    fields.forEach { (key, value) ->
        when (value) {
            //is String -> println("Here String")
            is File -> println("Here File")
            is Optional<*> -> println("Here Optional")
        }
    }
    passFieldsMap(fields)
}
fun passFieldsMap(fieldsMap: Map<String, Any?>) {
    fieldsMap.forEach { (key, value) ->
        when (value) {
            is String -> println("Here String")
            is File -> println("Here File")
        }
    }
}