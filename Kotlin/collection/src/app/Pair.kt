package app

fun main() {
    val pair1: Pair<String, String> = Pair("Tobi", "Albertino")
    println(pair1.first)
    println(pair1.second)

    val pair2: Pair<String, String> = "Tobi" to "Albertino"
    println(pair2.first)
    println(pair2.second)
}