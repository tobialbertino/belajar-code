fun main() {
    val names: Array<String> = arrayOf("Tobi", "Joko", "Budi")
    names[0] = "Rudi"
    println(names[0])

    val nilai: Array<Int> = arrayOf(10, 20, 30)
    println(nilai[0])
    println(nilai[1])
    println(nilai[2])

    val members: Array<String?> = arrayOfNulls(10)
    members[0] = "Tobi"
    members[1] = "Tobi"
    members[2] = "Tobi"
    members[3] = "Tobi"
    members[4] = "Tobi"
    members[5] = "Tobi"
}