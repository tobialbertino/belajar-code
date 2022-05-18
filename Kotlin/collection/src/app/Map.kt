package app

fun main() {
    val map: Map<String, String> = mapOf(
        Pair("a", "M"),
        "b" to "Khoiru",
        "c" to "Albertino"
    )

    for ((key, value) in map) {
        println("$key to $value")
    }
}