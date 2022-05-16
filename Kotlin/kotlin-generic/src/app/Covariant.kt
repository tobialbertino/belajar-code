package app

class Covariant<out T>(val data: T) {

    fun data(): T = data

    // Tidak BOLEH membuat func dengan input generic covariant
    // fun setData(param: T) = this.data = param
}

fun main() {
    val covariantString: Covariant<String> = Covariant("Tobi")
    val covariantAny: Covariant<Any> = covariantString

    println(covariantAny.data())

    // covariantAny.setData(100) // Tidak BOLEH
}