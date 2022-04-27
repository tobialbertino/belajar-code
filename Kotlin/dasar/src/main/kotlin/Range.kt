fun main() {
    //    val range = 1..100
    val Range = 100 downTo 1 step 2
    println(Range.count())
    println(Range.contains(12))
    println(Range.contains(200))
    println(Range.first)
    println(Range.last)
    println(Range.step)
}
