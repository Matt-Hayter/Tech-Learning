//This specifies the package that the file is within
package com.learning.basics

import com.learning.basics.utils.someUtility //Automatically inserted by IDE after someUtility is typed
import com.learning.basics.utils.someOtherUtility as altUtilityName //Custom name
//If no package is specified, the default package is used (bad practise)

fun main(args: Array<String>) {
    println("Specified package!")
    //Use name from other package
    someUtility("a name")
    altUtilityName("Some other name")
}