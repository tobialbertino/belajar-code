package app

fun main() {
    val list: List<String> = listOf("M", "Khoiru", "Tobi")

    println(list[0])
    println(list[1])
    println(list[2])
    println(list.indexOf("M"))
    println(list.indexOf("Tidak Ada"))
    println(list.contains("Tobi"))
    println(list.contains("Tidak ada"))
    println(list.containsAll(listOf("Tobi", "Khoiru")))
    println(list.isEmpty())
    println(list.isNotEmpty())
}