package app

class Invariant<T> (var data: T)

fun main() {
    val invariantString: Invariant<String> = Invariant("String")

    // val invariantAny: Invariant<Any> = invariantString("String") // bisa
    // invariantAny.data = 100 // bahaya
}