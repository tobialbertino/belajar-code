package app

fun <T> displayMutableCollection(collection: MutableCollection<T>) {
    for (element in collection) {
        println(element)
    }
}

fun main() {
    // displayMutableCollection(listOf("Tobi", "Albertino")) // ERROR
    displayMutableCollection(mutableListOf("Tobi", "Albertino"))
    // displayMutableCollection(setOf("Tobi", "Albertino")) // ERROR
    displayMutableCollection(mutableSetOf("Tobi", "Albertino"))
    // displayMutableCollection(mapOf("Tobi" to "Albertino").entries) // ERROR
    displayMutableCollection(mutableMapOf("Tobi" to "Albertino").entries)
}