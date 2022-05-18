package app

fun main() {
    val numbers = (1..100).toList()

    println(numbers.maxOrNull())
    println(numbers.minOrNull())
    println(numbers.average())
    println(numbers.sum())

    println(numbers.sumBy { it / 2 })
}