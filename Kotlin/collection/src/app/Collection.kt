package app

fun <T> displayCollection(collection: Collection<T>) {
    for (element in collection) {
        println(element)
    }
}

fun main() {
    displayCollection(listOf("Tobi", "Albertino"))
    displayCollection(mutableListOf("Tobi", "Albertino"))
    displayCollection(setOf("Tobi", "Albertino"))
    displayCollection(mutableSetOf("Tobi", "Albertino"))
    displayCollection(mapOf("Tobi" to "Albertino").entries)
    // displayCollection(mapOf("Tobi", "Albertino")) // ERROR, Map bukan turunan collection
}