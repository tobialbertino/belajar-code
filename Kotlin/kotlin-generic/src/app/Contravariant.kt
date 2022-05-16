package app

class Contravariant<in T> {

    fun sayHello(param: T) = println("Hello $param")

    // fun getData(): T = T // TIDAK BOLEH
}

fun main() {
    val contravariantAny: Contravariant<Any> = Contravariant()
    val contravariantString: Contravariant<String> = contravariantAny

    // contravariantString.getData() // error
    contravariantString.sayHello("Tobi")
}