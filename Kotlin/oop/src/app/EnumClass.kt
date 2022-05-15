package app

import data.Gender

fun main() {
    val man = Gender.MALE
    val woman = Gender.FEMALE
    val allGenders: Array<Gender> = Gender.values()

    val manFromString: Gender = Gender.valueOf("MALE")
    val womanFromString: Gender = Gender.valueOf("FEMALE")

    println(man)
    println(woman)
    println(allGenders.toList())

    println(manFromString)
    println(womanFromString)

    man.showDescription()
    woman.showDescription()
}