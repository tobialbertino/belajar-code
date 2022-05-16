package app

import data.Function

fun main() {
    val function = Function("Tobi")
    function.sayHello("Joko")
    function.sayHello<String>("Joko")

    function.sayHello(21)
    function.sayHello<Int>(21)


}