package app

fun <T> displayListIterator(listIterator: ListIterator<T>){
    println("Display next")
    while (listIterator.hasNext()) {
        println(listIterator.next())
    }

    println("Display Previous")
    while (listIterator.hasPrevious()) {
        println(listIterator.previous())
    }
}

fun main() {
    displayListIterator(listOf("Tobi", "Albertino").listIterator())
}